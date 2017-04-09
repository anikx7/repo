//============================================================================
// Name        : locomotor.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include "locomotor.h"
#include<iostream>
using namespace std;

Locomotor::Locomotor()
{
	name = "";
	part_number = 0;
	weight = 0;
	cost = 0;
	description = "";
	type_name = "Locomotor";
	max_speed = 0;
	use_status = 0;
	power_consumed = 0;
}

Locomotor::Locomotor(string n, int p, double w, double c, string d, double m,double po){
name = n;
part_number = p;
weight = w;
cost = c;
description = d;
type_name = "Locomotor";
max_speed = m;
use_status = 0;
power_consumed = p;

}

void Locomotor::show()
{
	cout << "Name: " << name << ", Part Number: " << part_number << ", weight: " << weight << "gram(s)\n";
	cout << "Cost: $" << cost << ", Max Speed: " << max_speed << "MPH, Power consumed: " << power_consumed << "watt(s) (" << description << ")\n\n";
}

void Locomotor::set_name(string n)
{
	name = n;
}

string Locomotor::get_name()
{
	return name;
}

void Locomotor::set_part_number(int p)
{
	part_number = p;
}

int Locomotor::get_part_number()
{
	return part_number;
}

void Locomotor::set_weight(double w)
{
	weight = w;
}

double Locomotor::get_weight()
{
	return weight;
}

void Locomotor::set_cost(double c)
{
	cost = c;
}

double Locomotor::get_cost()
{
	return cost;
}

void Locomotor::set_description(string d)
{
	description = d;
}

string Locomotor::get_description()
{
	return description;
}

void Locomotor::set_use_status(int u)
{
	use_status = u;
}

int Locomotor::get_use_status()
{
	return use_status;
}

void Locomotor::set_max_speed(double p)
{
	max_speed = p;
}

double Locomotor::get_max_speed()
{
	return max_speed;
}

void Locomotor::set_power_consumed(double p)
{

	power_consumed = p;
}

double Locomotor::get_power_consumed()
{
	return power_consumed;
}
