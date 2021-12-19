#include "Main.h"

static ScriptTasks* _scriptTasksInstance = NULL;

ScheduledTask::ScheduledTask(int seconds, function<void()>const& callbackArg)
	: callback(callbackArg)
{
	this->seconds = seconds;
	this->registeredAt = time(0);
	//this->callback = callback;
}

ScriptTasks::ScriptTasks()
{}

ScriptTasks* ScriptTasks::instance()
{
	if (!_scriptTasksInstance)
	{
		_scriptTasksInstance = new ScriptTasks();
	}

	return _scriptTasksInstance;
}

void ScriptTasks::update()
{
	updateTasks();
	updatePlancks();
}

void ScriptTasks::setTimeout(int seconds, function<void()> const&& callback)
{
	ScheduledTask* task = new ScheduledTask(seconds, callback);
	tasks.push_back(task);
}

void ScriptTasks::addPlanck(int duration, function<void()> const&& callback)
{
	ScheduledTask* task = new ScheduledTask(duration, callback);
	plancks.push_back(task);
}

void ScriptTasks::updateTasks()
{
	vector<ScheduledTask*>::iterator itr = tasks.begin();
	while (itr != tasks.end())
	{
		ScheduledTask* task = *itr;
		int elapsedSeconds = Stopwatch::getElapsedSeconds(task->registeredAt, time(0));
		if (elapsedSeconds > task->seconds)
		{
			task->callback();
			itr = tasks.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

void ScriptTasks::updatePlancks()
{
	vector<ScheduledTask*>::iterator itr = plancks.begin();
	while (itr != plancks.end())
	{
		ScheduledTask* task = *itr;
		int elapsedSeconds = Stopwatch::getElapsedSeconds(task->registeredAt, time(0));
		if (elapsedSeconds < task->seconds)
		{
			task->callback();
			itr++;
		}
		else
		{
			itr = plancks.erase(itr);
		}
	}
}