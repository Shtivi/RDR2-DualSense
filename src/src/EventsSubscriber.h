#pragma once


template <typename T> class EventsSubscriber
{
public:
	virtual void handleEvent(T eventData) = 0;
};