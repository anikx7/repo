//============================================================================
// Name        : order.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#ifndef __ORDER__
#define __ORDER__

#include<string>
#include"customer.h"
#include"robot.h"
using namespace std;


//Defining a class
class Order
{
private:
	//Data's of the class
	int employe_number;
	int order_number;
	int day;
	int month;
	int year;
	Customer customer;
	Robot robot_model;
	int quantity;


	//Functions of the class	
public:
	Order();
	Order(int o, int d, int m, int y, Customer c, Robot r, int q, int employee);
	double get_total_price_with_tax();

	void show();

	void set_employee_number(int o);
	int get_employee_number();
	void set_order_number(int o);
	int get_order_number();

	void set_day(int d);
	int get_day();

	void set_month(int m);
	int get_month();

	void set_year(int y);
	int  get_year();

	void set_customer(Customer c_temp);
	Customer get_customer();

	void set_robot_model(Robot r_temp);
	Robot get_robot_model();

	void set_quantity(int q);
	int get_quantity();
};
#endif