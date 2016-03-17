#pragma once

#include <set>
#include <functional>
#include "boost\heap\fibonacci_heap.hpp"

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType & observer) override
	{
		m_observers.insert(&observer);
		m_hObservers.push(&observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		for (auto & observer : m_observers)
		{
			observer->Update(data);
		}

		for (auto & obs : m_hObservers)
		{
			obs->Update(data);
		}
	}
		
	void RemoveObserver(ObserverType & observer) override
	{
		//auto that = m_observers.find(&observer);
		//if (that == this)
		//{
		//	std::cout << "Try delete myself" << std::endl;
		//	return;
		//}
		m_observers.erase(&observer);

		for (auto it = m_hObservers.begin(); it != m_hObservers.end();++it)
		{
			auto a = decltype(m_hObservers)::s_handle_from_iterator(it);
			m_hObservers.erase(a);
		}
		
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	std::set<ObserverType *> m_observers;
	boost::heap::fibonacci_heap<ObserverType *> m_hObservers;
};
