//============================================================================
// Name        : torso.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include "torso.h"
#include<iostream>

using namespace std;

Torso::Torso()
{
	name = "";
	part_number = 0;
	weight = 0;
	cost = 0;
	description = "";
	type_name = "Torso";
	use_status = 0;
}

Torso::Torso(string n, int p, double w, double c, string d, Battery b_temp1)
{
	name = n;
	part_number = p;
	weight = w;
	cost = c;
	description = d;
	type_name = "Torso";
	b1 = b_temp1;
	use_status = 0;
}

Torso::Torso(string n, int p, double w, double c, string d, Battery b_temp1, Battery b_temp2)
{
	name = n;
	part_number = p;
	weight = w;
	cost = c;
	description = d;
	type_name = "Torso";
	b1 = b_temp1;
	b2 = b_temp2;
	use_status = 0;
}
void Torso::show()
{
	cout << "Name: " << name << ", Part Number: " << part_number << ", weight: " << weight << "gram(s)\n";
	cout << "Cost: $" << cost << " (" << description << ")\n\n";
	cout << "----------------------Batteries inside the Torso--------------------------\n";
	if(b1.get_part_number()==0){}
	else { b1.show(); }

	if (b2.get_part_number() == 0){}
	else { b2.show(); }

	if (b3.get_part_number() == 0){}
	else { b3.show(); }
	cout << "---------------------------------------------------------------------------\n\n";
}

Torso::Torso(string n, int p, double w, double c, string d, Battery b_temp1, Battery b_temp2, Battery b_temp3)
{
	name = n;
	part_number = p;
	weight = w;
	cost = c;
	description = d;
	type_name = "Torso";
	b1 = b_temp1;
	b2 = b_temp2;
	b3 = b_temp3;
	use_status = 0;
}



void Torso::set_name(string n)
{
	name = n;
}

string Torso::get_name()
{
	return name;
}

void Torso::set_part_number(int p)
{
	part_number = p;
}

int Torso::get_part_number()
{
	return part_number;
}

void Torso::set_weight(double w)
{
	weight = w;
}

double Torso::get_weight()
{
	return weight;
}

void Torso::set_cost(double c)
{
	cost = c;
}

double Torso::get_cost()
{
	return cost;
}

void Torso::set_description(string d)
{
	description = d;
}

string Torso::get_description()
{
	return description;
}

void Torso::set_use_status(int u)
{
	use_status = u;
}

int Torso::get_use_status()
{
	return use_status;
}

void Torso::set_b1(Battery b)
{
	b1 = b;
}

Battery Torso::get_b1()
{
	return b1;
}

void Torso::set_b2(Battery b)
{
	b2 = b;
}

Battery Torso::get_b2()
{
	return b2;
}


void Torso::set_b3(Battery b)
{
	b3 = b;
}

Battery Torso::get_b3()
{
	return b3;
}
