#include <algorithm>
#include <functional>
#include <cassert>
#include <memory>
#include <iostream>

using namespace std;

class FlyWithWings
{
public:
	void operator ()()
	{
		++m_sortieCount;
		cout << "I'm flying with wings!! Sortie #" << m_sortieCount << endl;
	}
private:
	unsigned m_sortieCount = 0;
};

void NoFly() {}

void QuackBehavior()
{
	cout << "Quack Quack!!!" << endl;
}

void SqueakBehavior()
{
	cout << "Squeek!!!" << endl;
}

void Mute() {}

void NoDance() {}

void Waltz()
{	
	cout << "Dance Waltz!" << endl;
}

void Minuet()
{
	cout << "Dance Menuet!" << endl;
}

class Duck
{
public:
	Duck(function<void()> flyBehavior, function<void()> const &quackBehavior, function<void()> const &danceBehavior)
		:
		m_flyBehavior(flyBehavior),
		m_quackBehavior(quackBehavior),
		m_danceBehavior(danceBehavior)
	{
		SetFlyBehavior(NoFly);
	}
	void Quack() const
	{
		m_quackBehavior();
	}
	void Swim()
	{
		cout << "I'm swimming" << endl;
	}
	void Fly()
	{
		m_flyBehavior();
	}
	virtual void Dance()
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(function<void()> flyBehavior)
	{
		m_flyBehavior = flyBehavior;
	}

	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	function<void()> m_flyBehavior;
	function<void()> m_quackBehavior;
	function<void()> m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings(), QuackBehavior, Minuet)
	{}

	void Display() const override
	{
		cout << "I'm mallard duck" << endl;
	}
};


class RedheadDuck : public Duck
{
public:
	RedheadDuck()
		: Duck(FlyWithWings(), QuackBehavior, Minuet)
	{
	}
	void Display() const override
	{
		cout << "I'm redhead duck" << endl;
	}
};

class DeckoyDuck : public Duck
{
public:
	DeckoyDuck()
		: Duck(FlyWithWings(), Mute, NoDance)
	{
	}
	void Display() const override
	{
		cout << "I'm deckoy duck" << endl;
	}
};

class RubberDuck : public Duck
{
public:
	RubberDuck()
		: Duck(FlyWithWings(), QuackBehavior, NoDance)
	{
	}
	void Display() const override
	{
		cout << "I'm rubber duck" << endl;
	}
};

class ModelDuck : public Duck
{
public:
	ModelDuck()
		: Duck(FlyWithWings(), QuackBehavior, NoDance)
	{
	}	
	void Display() const override
	{
		cout << "I'm model duck" << endl;
	}
};

void DrawDuck(Duck const& duck)
{
	duck.Display();
}

void PlayWithDuck(Duck & duck)
{
	duck.Quack();
	duck.Dance();
	duck.Fly();
	DrawDuck(duck);
}

int main()
{
	MallardDuck mallarDuck;
	PlayWithDuck(mallarDuck);
	RedheadDuck redheadDuck;
	PlayWithDuck(redheadDuck);
	RubberDuck rubberDuck;
	PlayWithDuck(rubberDuck);
	DeckoyDuck deckoyDuck;
	PlayWithDuck(deckoyDuck);
	ModelDuck modelDuck;
	PlayWithDuck(modelDuck);
	PlayWithDuck(modelDuck);

	return 0;
}
