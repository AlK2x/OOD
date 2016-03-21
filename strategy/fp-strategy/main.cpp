#include <algorithm>
#include <functional>
#include <cassert>
#include <memory>
#include <iostream>

using namespace std;

typedef function<void()> FlyBehavior;
typedef function<void()> QuackBehavior;
typedef function<void()> DanceBehavior;

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

void QuackFunc()
{
	cout << "Quack Quack!!!" << endl;
}

void Squeak()
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
	
	Duck(FlyBehavior const & flyBehavior, QuackBehavior const & quackBehavior, DanceBehavior const & danceBehavior)
		: m_quackBehavior(quackBehavior),
		m_danceBehavior(danceBehavior)
	{
		assert(quackBehavior);
		assert(danceBehavior);
		SetFlyBehavior(flyBehavior);
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
	void Dance()
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(FlyBehavior const & flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = flyBehavior;
	}

	virtual void Display() const = 0;
	virtual ~Duck() {};
private:
	FlyBehavior m_flyBehavior;
	QuackBehavior m_quackBehavior;
	DanceBehavior m_danceBehavior;
};

class MallardDuck : public Duck
{
public:
	MallardDuck()
		: Duck(FlyWithWings(), QuackFunc, Minuet)
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
		: Duck(FlyWithWings(), QuackFunc, Waltz)
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
		: Duck(NoFly, QuackFunc, NoDance)
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
		: Duck(NoFly, QuackFunc, NoDance)
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
