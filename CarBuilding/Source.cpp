#include <iostream>
#include <dos.h>
using namespace std;

void use_of_fuel_in_move(double liters);
void use_of_fuel_in_peace(double liters);

class Car
{
public:
	
	Car(double liters = 20)
	{
		cout << "Car Constructor" << endl;
	}
	~Car()
	{
		cout << "Car Destructor" << endl;
	}friend class Engine;
	friend class FuelTank;
	
	
	void move_forward(double liters)
	{
		
		if (liters > 0)
		{
			cout << "Car is going forward" << endl;
			use_of_fuel_in_move(liters);
		}
		
	}
	void turn_right(double liters)
	{
		if (liters > 0)
		{
			cout << "Car turned right" << endl;
			use_of_fuel_in_move(liters);
		}
	}
	void turn_left(double liters)
	{
		if (liters > 0)
		{
			cout << "Car turned left" << endl;
			use_of_fuel_in_move(liters);
		}
		else cout << "Out of fuel";
	}
	void reverse(double liters)
	{
		if (liters > 0)
		{
			cout << "Car is going backwards" << endl;
			use_of_fuel_in_move(liters);
		}
		else cout << "Out of fuel";
	}
};

class FuelTank
{
	double liters;
	double min = 0;
	double max = 60;
public:

	FuelTank()
	{
		cout << "FT Constructor:";
	}
	FuelTank(double liters, double min, double max) :liters(liters), min(min), max(max)
	{
		cout << "FT Constructor:";
	}
	~FuelTank()
	{
		cout << "FT Destructor";
	}
	friend class Car;
	friend class Engine;
	void refule(double liters)
	{
		double fuel;
		cout << "How much liters?"; cin >> fuel;
		double result = liters + fuel;
		if (liters < 60)
		{
			while (liters < result)
			{
				_sleep(1000);
				liters++;
				cout << "Level of fuel: " << liters << endl;
			}
		}
		else cout << "Fuel Tank is full" << endl;
		cout << "Fuel Tank is full";
	}
};

class Engine
{
public:

	Engine()
	{
		cout << "EngineConstructor" << endl;
	}
	~Engine()
	{
		cout << "EngineDestructor" << endl;
	}
	friend class Car;
	friend class FuelTank;

	void turn_on(double liters)
	{ 
		if (liters > 0)
		{
			cout << "Engine started" << endl;
			use_of_fuel_in_peace(liters);
		}
		else cout << "Out of fuel";
	}
	void turn_off()
	{
		cout << "Engine turned off" << endl;
	}
};

void use_of_fuel_in_move(double liters)
{
	double use_in_movement = 2.4;
	while (liters > 0)
	{
		_sleep(1000);
		liters = (liters - use_in_movement);
		cout << "Level of fuel:" << liters << endl;
	}
	cout << "End of fuel" << endl;
}
void use_of_fuel_in_peace(double liters)
{
	double use_in_movement = 0.8;
	while (liters > 0)
	{
		_sleep(1000);
		liters = (liters - use_in_movement);
		cout << "Level of fuel:" << liters << endl;
	}
	cout << "End of fuel" << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	Car car;
	Engine engine;
	FuelTank fuel_tank;
	//engine.turn_on(20);
	//fuel_tank.refule(20);
	//car.move_forward(40);
}
/*
Сомневаюсь что сделаю лучше, чем эта примитивная машина, нашел полное решение и ничего не понял.
*/
