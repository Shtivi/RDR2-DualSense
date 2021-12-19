#pragma once

#include "EventsSubscriber.h"

template <typename T> class EventsChannel
{
private:
	set<EventsSubscriber<T>*> subscribers;

public:
	void subscribe(EventsSubscriber<T>* subscriber) 
	{
		subscribers.insert(subscriber);
	}

	void dispatch(T eventData)
	{
		for each (EventsSubscriber<T> * subscriber in subscribers)
		{
			subscriber->handleEvent(eventData);
		}
	}
};
