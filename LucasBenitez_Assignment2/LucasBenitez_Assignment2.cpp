// COP3014 - Assignment Number 1
// Purpose: Coin Dispenser Machine, and, Dollar Dispenser Machine
// Concepts: C++ basics, I/O design, data types and arithmetic operators
// Author: Lucas Benitez, lbenitez2019@gmail.com
// Last edited: 9/7/2022


#include <iostream>							// Includes functions to read and write from std i/o streams.
#include <cmath>							// Includes library for math functions
#include <iomanip>							// Includes library for manipulating output
using namespace std;						// Using the C++ std library namespace


int main()
{
	double P; // principle loan amount
	double M; // total monthly payment including principle plus interest
	double r; // monthly interest rate
	double n; // length of the loan in months

	cout.setf(ios::fixed);    //	format output for currency
	cout.setf(ios::showpoint);//	format output for currency
	cout.precision(2);		  //	format output for currency


	// print out gretting 

	// TEMP COMMENTING OUT TO MAKE TESTING FASTER -- BEGIN
	/*
	cout << "enter loan amount (in thousands): "; // ask for loan amount
	cin >> P;
	P = P * 1000;	// convert to thousands

	cout << "enter interest rate: ";	// ask for interest rate
	cin >> r;
	r = r / 100 / 12;	// convert from annual to monthly percentage rate

	cout << "enter length of loan (in months): ";	// ask for lenght of loan in months
	cin >> n;
	*/

	// Delete the below 3 lines when done testing
	P = 20000.00;
	r = 4.4 / 100.0 / 12.0;
	n = 36.0;

	// TEMP COMMENTING OUT TO MAKE TESTING FASTER -- END



	M = P * (r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
	cout << "the value of M is: " << M << endl;

	double mi;	      // monthly interest amount
	double mp;		  // monthly principle amount
	double rb = P;	  // remaining balance
	int lc = 1;	      // loop counter

	// Table header
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << "| Mth | Monthly payment | Interest payment | Priciple payment | Remaining balance   |" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	while (lc < n + 1)
	{
		mi = r * rb;  // calculate monthly interest amount
		mp = M - mi;  // calculate monthly priciple amount
		rb = rb - mp; // calculate remaining balance 

		//cout << std::setfill(' ') << std::setw(14);

		cout << "  " << lc << "       $" << M << "             $" << setfill(' ') << setw(5) << mi << "            $" << mp << "              $" << rb << endl;

		lc++;
	}



	return 0;
}