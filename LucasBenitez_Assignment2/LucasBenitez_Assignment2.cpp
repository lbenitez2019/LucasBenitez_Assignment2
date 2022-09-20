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
	char STRT = 'y';    // checks whether or not the user wants to continue or quit the program
	double P;			// principle loan amount
	double M;			// total monthly payment including principle plus interest
	double r;			// monthly interest rate
	double n;			// length of the loan in months

	cout.setf(ios::fixed);    //	format output for currency
	cout.setf(ios::showpoint);//	format output for currency
	cout.precision(2);		  //	format output for currency


	while (STRT == 'y' || STRT == 'Y')
	{

		cout << "enter loan amount (in thousands): "; // ask for loan amount
		cin >> P;
		P = P * 1000;	// convert to thousands

		cout << "enter interest rate: ";	// ask for interest rate
		cin >> r;
		r = r / 100 / 12;	// convert from annual to monthly percentage rate

		cout << "enter length of loan (in months): ";	// ask for lenght of loan in months
		cin >> n;


		// equation 
		M = P * (r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
		cout << "the value of M is: " << M << endl;

		double mi;	      // monthly interest amount
		double mp;		  // monthly principle amount
		double rb = P;	  // remaining balance
		int lc = 1;	      // loop counter

		// Table header
		// field width shown below for formatting
		//        12345 12345678901234567 123456789012345678 123456789012345678 123456789012345678901
		cout << "-------------------------------------------------------------------------------------" << endl;
		cout << "| Mth | Monthly payment | Interest payment | Priciple payment | Remaining balance   |" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;
		while (lc < n + 1)
		{
			mi = r * rb;  // calculate monthly interest amount
			mp = M - mi;  // calculate monthly priciple amount
			rb = rb - mp; // calculate remaining balance 

			//cout << std::setfill(' ') << std::setw(14);
			//cout << "  " << lc << "       $" << M << "             $" << setfill(' ') << setw(5) << mi << "            $" << mp << "              $" << rb << endl;
			cout << setfill(' ') << setw(4) << lc;
			cout << "      $" << setfill(' ') << setw(10) << M;
			cout << "      $" << setfill(' ') << setw(10) << mi;
			cout << "        $" << setfill(' ') << setw(10) << mp;
			cout << "        $" << setfill(' ') << setw(10) << rb;
			cout << endl;

			lc++;
		}

		// Prompt user if they want to go again. 
		cout << "Continue? (y/n) ";
		cin >> STRT;
		
	}
}