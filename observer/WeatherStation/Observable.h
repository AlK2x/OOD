#pragma once
#include "stdafx.h"
#include "IObservable.h"
#include "IObserver.h"

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer) override;

	void NotifyObservers() override;

	void RemoveObserver(ObserverType & observer) override;

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:

	struct comparison
	{
		bool operator()(const ObserverType* a, const ObserverType* b)
		{
			return a->priority > b->priority;
		}
	};

	std::set<ObserverType *, comparison> m_observers;
};

template<class T>
void CObservable<T>::RegisterObserver(ObserverType & observer)
{
	m_observers.insert(&observer);
}

template<class T>
void CObservable<T>::NotifyObservers()
{
	T data = GetChangedData();
	auto observers = m_observers;
	for (auto & observer : observers)
	{
		observer->Update(data);
	}
}

template<class T>
void CObservable<T>::RemoveObserver(ObserverType & observer)
{
	m_observers.erase(&observer);
}
