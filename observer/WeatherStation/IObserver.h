#pragma once
#include "IObservable.h"
#include "WeatherInfo.h"

template <class T>
class IObservable;
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
	virtual void Update(IObservable<T> const& subject) = 0;
	virtual ~IObserver() = default;
};