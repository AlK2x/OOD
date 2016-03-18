#include "stdafx.h"
#include "DummyObserver.h"

void CDummyObserver::Update(int const & data)
{
	std::cout << m_number << std::endl;
}
