#pragma once
#include "stdafx.h"
#include "IObserver.h"	

template <typename T>
class PriorityObserver : public IObserver<T>
{
public:
	virtual void Update(T const& data) = 0;
	bool operator < (PriorityObserver const & that)
	{
		return m_priority < that.priority;
	}
	void SetPriority(unsigned priority)
	{
		m_priority = priority;
	}
private:
	unsigned m_priority = 0;
};