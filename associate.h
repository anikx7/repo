//============================================================================
// Name        : associate.h
// Author      : Rafid Ishrak Jahan
// Version     :
// Copyright   : Your copyright notice
// Description : Robbie Robot Shop in C++, Ansi-style
//============================================================================

#ifndef __ASSOCIATE__
#define __ASSOCIATE__

#include<string>
#include"customer.h"
#include"robot.h"
#include"order.h"
using namespace std;


//Defining a class
class Associate
{
private:
	//Data's of the class
	string name;
	int employee_number;
	vector<Order>orders;
	int order_count;

	//Functions of the class	
public:
	Associate();
	Associate(string employee_name, int n);
	void set_name(string customer_name);
	string get_name();
	void set_employee_number(int n);
	int get_employee_number();

	void set_order(Order order1);
	Order get_order(int order_number);
	int get_order_count();


};
#endif
