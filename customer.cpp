//============================================================================
// Name        : customer.cpp
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include "customer.h"
#include<string>
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;


Customer::Customer()
{
	name = " ";
	phone = " ";
	address = " ";
	email = " ";
}

Customer::Customer(string customer_name, string customer_phone,string a, string e)
{
	name = customer_name;
	phone = customer_phone;
	address = a;
	email = e;
}

void Customer::set_name(string customer_name)
{
	name = customer_name;
}

string Customer::get_name()
{
	return name;
}

void Customer::set_phone(string customer_phone)
{
	phone = customer_phone;
}

string Customer::get_phone()
{
	return phone;
}

void Customer::set_address(string a)
{
	address = a;
}

string Customer::get_address()
{
	return address;
}

void Customer::set_email(string e)
{
	email = e;
}

string Customer::get_email()
{
	return email;
}

void Customer::set_order_number(int o)
{
	order_number = o;
}

int Customer::get_order_number()
{
	return order_number;
}
