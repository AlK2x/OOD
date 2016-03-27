#include "stdafx.h"
#include "DummyObserver.h"

void CDummyObserver::Update(IObservable<int> const& subject)
{
	std::cout << m_number << std::endl;
}
