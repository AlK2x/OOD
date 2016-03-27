#pragma once
#include "stdafx.h"
#include "IObservable.h"
#include "IObserver.h"
#include "WeatherInfo.h"
#include "boost\multi_index\ordered_index.hpp"
#include "boost\multi_index\hashed_index.hpp"
#include "boost\multi_index\member.hpp"
#include "boost\multi_index\identity.hpp"
#include "boost\multi_index_container.hpp"

using namespace boost;
using namespace boost::multi_index;

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	
	struct ComparableTypeEx
	{
		ObserverType* obs;
		unsigned priority;
	};

	typedef multi_index_container <
		ComparableTypeEx,
		indexed_by<
			hashed_unique<member<ComparableTypeEx, ObserverType*, &ComparableTypeEx::obs>>,
			ordered_non_unique<member<ComparableTypeEx, unsigned, &ComparableTypeEx::priority>>
		>
	> MultiIndexType;

	void RegisterObserver(ObserverType & observer, unsigned priority = 0) override;

	void NotifyObservers() override;

	void RemoveObserver(ObserverType & observer) override;

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	MultiIndexType m_multiObservers;
};

template<class T>
void CObservable<T>::RegisterObserver(ObserverType & observer, unsigned priority = 0)
{
	m_multiObservers.insert({&observer, priority});
}

template<class T>
void CObservable<T>::NotifyObservers()
{
	T data = GetChangedData();
	auto observers = m_multiObservers;
	auto &iter = observers.get<1>();
	for (auto it = iter.begin(); it != iter.end(); ++it)
	{
		it->obs->Update(data);
	}
}

template<class T>
void CObservable<T>::RemoveObserver(ObserverType & observer)
{
	auto &it = m_multiObservers.get<0>();
	auto iter = it.find(&observer);
	it.erase(iter);
}
