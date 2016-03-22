#pragma once
#include "stdafx.h"
#include "IObservable.h"
#include "IObserver.h"

// ���������� ���������� IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;
	typedef std::pair<unsigned, ObserverType*> ComparableType;

	void RegisterObserver(ObserverType & observer, unsigned priority = 0) override;

	void NotifyObservers() override;

	void RemoveObserver(ObserverType & observer) override;

protected:
	// ������-���������� ������ ����������� ������ �����, 
	// � ������� ���������� ���������� �� ���������� � �������
	virtual T GetChangedData()const = 0;

private:

	struct SComparator
	{
		bool operator() (ComparableType const & left, ComparableType const & right)
		{
			return left.first < right.first;
		}
	};

	std::set<ComparableType, SComparator> m_observers;
};

template<class T>
void CObservable<T>::RegisterObserver(ObserverType & observer, unsigned priority = 0)
{
	m_observers.insert(std::make_pair(priority, &observer));
}

template<class T>
void CObservable<T>::NotifyObservers()
{
	T data = GetChangedData();
	auto observers = m_observers;
	for (auto & observer : observers)
	{
		observer.second->Update(data);
	}
}

template<class T>
void CObservable<T>::RemoveObserver(ObserverType & observer)
{
	//m_observers.erase(&observer);
}
