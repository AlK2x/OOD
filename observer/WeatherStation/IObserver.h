#pragma once
#include "IObservable.h"
#include "WeatherInfo.h"

template <class T>
class IObservable;
/*
��������� ��������� IObserver. ��� ������ ������������� �����,
�������� �������� ����������� �� ���������������� IObservable
���������� ������� �������� ��� ���������,
������������� ����������� � ����� Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(IObservable<T> const& subject) = 0;
	virtual ~IObserver() = default;
};