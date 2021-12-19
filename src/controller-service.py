from pydualsense import pydualsense, TriggerModes, PulseOptions
import time
import sys
import signal
import os

from pydualsense.enums import Brightness, LedOptions, PulseOptions

logfile = open("controller-service.log", "w")
dualsense = None

def log(text, newline = True):
    logfile.write(text);
    if newline:
        logfile.write("\n")
    logfile.flush()
    print(text)

def close(signal, frame):
    log("Closing")
    if dualsense != None:
        dualsense.close()
    logfile.close()
    sys.exit(0)

def parse_input(lines: list[str]): 
    result = {}
    result["PULSE_RATE"] = 0
    result["HEALTH"] = 1

    i = 0
    for line in lines:
        try:
            [key, value] = line.split('=')
            result[key.strip()] = value.strip()
            i = i + 1
        except Exception as ex:
            log("failed to parse input on line: " + str(i) + ", error: " + str(ex))
    return result

def reset_triggers():
    dualsense.triggerL.setMode(TriggerModes.Off)
    dualsense.triggerL.setForce(0, 0);
    dualsense.triggerR.setMode(TriggerModes.Off)
    dualsense.triggerR.setForce(0, 0);

def handle_triggers(params):
    dualsense.triggerL.setMode(TriggerModes.Rigid)
    dualsense.triggerL.setForce(1, 50)

    match params["MODE"]:
        case 'OFF':
            reset_triggers()
        case 'GUN_MANUAL':
            dualsense.triggerR.setMode(TriggerModes.Pulse)
            dualsense.triggerR.setForce(1, int(90 * (1 + float(params["STIFFNESS"]))))

        case 'GUN_COCK':
            dualsense.triggerR.setMode(TriggerModes.Pulse)
            dualsense.triggerR.setForce(1, int(20 * (1 + float(params["STIFFNESS"]))))    
        case 'THROWABLE':
            dualsense.triggerR.setMode(TriggerModes.Pulse_A)
            dualsense.triggerR.setForce(0, 160)
            dualsense.triggerR.setForce(1, 30)
            dualsense.triggerR.setForce(2, 230)
            # dualsense.triggerR.setMode(TriggerModes.Rigid)
            # dualsense.triggerR.setForce(0, 30)
            # dualsense.triggerR.setForce(1, 150)
            # dualsense.triggerR.setForce(2, 80)
        case 'GUN_AUTOMATIC_PREPARE':
            dualsense.triggerR.setMode(TriggerModes.Rigid)
            dualsense.triggerR.setForce(0, 30)
            dualsense.triggerR.setForce(1, 255)
        case 'GUN_AUTOMATIC':
            dualsense.triggerR.setMode(TriggerModes.Pulse_B)
            dualsense.triggerR.setForce(0, 9)
            dualsense.triggerR.setForce(1, 190)
        case 'CANNON':
            dualsense.triggerR.setMode(TriggerModes.Rigid)
            dualsense.triggerR.setMode(TriggerModes.Pulse_A)
            dualsense.triggerR.setForce(0, 255)
            dualsense.triggerR.setForce(1, 200)
            dualsense.triggerR.setForce(2, 255)
        # case 'BOW':
            # dualsense.triggerR.setMode(TriggerModes.Pulse_B)
            # dualsense.triggerR.setForce(0, 60)
            # dualsense.triggerR.setForce(1, 250) 
            # dualsense.triggerR.setForce(2, 2) 
        case 'RELOAD':
            dualsense.triggerR.setMode(TriggerModes.Off)
            dualsense.triggerR.setForce(0, 0);

def handle_leds(rate, interval_pos, interval_direction, greeness):
    now = time.time()

    if rate == 0:
        interval_pos = 1
    else:
        if interval_direction == -1 and interval_pos <= 0:
            interval_direction = 1
        else:
            if interval_direction == 1 and interval_pos >= 1:
                interval_direction = -1

    green = greeness * 80
    red = 80 - green
    dualsense.light.setColorI(int(red * interval_pos), int(green * interval_pos), 0)

    return [
        interval_pos + interval_direction * 0.0004 * rate, 
        interval_direction
    ]

signal.signal(signal.SIGINT, close)
interval_pos = 0
interval_direction = 1

log("Initializaing");
while dualsense == None:
    try:
        dualsense = pydualsense()
        dualsense.init()
        log("DualSense initialized")
    except Exception as ex:
        dualsense = None
        log("failed to initialize controller: " + str(ex))
        log("retrying in 5 seconds")
        time.sleep(5)

if dualsense != None:
    if not os.path.exists("./inputs"):
        log("waiting for input file to appear...")
        while not os.path.exists("./inputs"):
            continue
    log("input file found")

    while True:
        inputFile = open("inputs", "r")
        lines = inputFile.readlines()

        if len(lines) == 0:
            reset_triggers()
        else:
            params = parse_input(lines)

            pulse_rate = 0
            health = max(min(float(params["HEALTH"]), 1), 0)

            if float(params["PULSE_RATE"]) > 0:
                pulse_rate = max(min(float(params["PULSE_RATE"]), 1), 0.2)
            
            handle_triggers(params)
            [interval_pos, interval_direction] = handle_leds(
                rate = pulse_rate, 
                interval_pos = interval_pos, 
                interval_direction = interval_direction, 
                greeness = health
            )

    


# dualsense.triggerL.setMode(TriggerModes.Rigid)
# dualsense.triggerL.setForce(1, 50)

# # Gun
# dualsense.triggerR.setMode(TriggerModes.Pulse)
# dualsense.triggerR.setForce(1, 90)

# Bow
# dualsense.triggerR.setMode(TriggerModes.Pulse_A)
# dualsense.triggerR.setForce(0, 160)
# dualsense.triggerR.setForce(1, 30)
# dualsense.triggerR.setForce(2, 210)


