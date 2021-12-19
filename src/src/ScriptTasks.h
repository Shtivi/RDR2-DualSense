#pragma once

class ScheduledTask
{
public:
	ScheduledTask(int seconds, function<void()>const& callback);
	function<void()>const& callback;
	time_t registeredAt;
	int seconds;
};

class ScriptTasks
{
private:
	vector<ScheduledTask*> tasks;
	vector<ScheduledTask*> plancks;
	Stopwatch stopwatch;

public:
	ScriptTasks();
	static ScriptTasks* instance();
	void update();
	void setTimeout(int seconds, function<void()> const&& callback);
	void addPlanck(int duration, function<void()> const&& callback);

private:
	void updateTasks();
	void updatePlancks();
};