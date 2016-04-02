#pragma once

#include "IBeverage.h"

enum class ShakeSize
{
	Small,
	Medium,
	Large
};

enum class TeaType
{
	White,
	Green,
	Red,
	BlowMyMind
};

std::string GetTeaNameByTeaType(TeaType type)
{
	switch (type)
	{
	case TeaType::White:
		return "White Tea";
		break;
	case TeaType::Green:
		return "Green Tea";
		break;
	case TeaType::Red:
		return "Red Tea";
		break;
	case TeaType::BlowMyMind:
		return "Blow My Mind Tea";
		break;
	default:
		return "Tea";
	}
}

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description) 
	{}

	double GetCost() const override 
	{
		return 60; 
	}
};

// Капуччино
class CCapuccino : public CCoffee
{
public:
	CCapuccino() 
		:CCoffee("Capuccino") 
	{}

	double GetCost() const override 
	{
		return 80; 
	}
};

class CDoubleCapuccino : public CCoffee
{
public:
	CDoubleCapuccino()
		:CCoffee("Double Capuccion")
	{}

	double GetCost() const override
	{
		return 120;
	}
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte() 
		:CCoffee("Latte") 
	{}

	double GetCost() const override 
	{
		return 90; 
	}
};

class CDoubleLatte : public CCoffee
{
public:
	CDoubleLatte()
		:CCoffee("Double Latte")
	{}

	double GetCost() const override
	{
		return 130;
	}
};

// Чай
class CTea : public CBeverage
{
public:
	CTea() 
		:CBeverage("Tea") 
	{}

	double GetCost() const override 
	{
		return 30; 
	}
};

class CSpecialTea : public CBeverage
{
public:
	CSpecialTea(TeaType teaSort = TeaType::Green)
		:CBeverage(GetTeaNameByTeaType(teaSort))
	{}

	double GetCost() const override
	{
		return 42;
	}
};

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(ShakeSize size = ShakeSize::Large) 
		:CBeverage("Milkshake"), m_shakeSize(size)
	{}

	double GetCost() const override 
	{ 
		if (m_shakeSize == ShakeSize::Small)
		{
			return 50;
		}

		if (m_shakeSize == ShakeSize::Medium)
		{
			return 60;
		}

		return 80; 
	}
private:
	ShakeSize m_shakeSize;
};
