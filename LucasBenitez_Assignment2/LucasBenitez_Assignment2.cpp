// COP3014 - Assignment Number 2
// Purpose: Mortgage Calculator with loop function
// Author: Lucas Benitez, lbenitez2019@gmail.com
// Last edited: 9/19/2022


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

		cout << "Enter loan amount (in thousands): ";	// ask for loan amount
		cin >> P;
		P = P * 1000;									// convert to thousands

		cout << "Enter interest rate: ";				// ask for interest rate
		cin >> r;
		r = r / 100 / 12;								// convert from annual to monthly percentage rate

		cout << "Enter length of loan (in months): ";	// ask for lenght of loan in months
		cin >> n;

		// Compute total mortgage payment 
		M = P * (r * pow(1 + r, n)) / (pow(1 + r, n) - 1);

		double mi;	      // monthly interest amount
		double mp;		  // monthly principle amount
		double rb = P;	  // remaining balance
		int lc = 1;	      // loop counter

		// Table header (field width shown below for formatting)
		//       123456 123456789012345678 123456789012345678 123456789012345678 123456789012345678901
		//       12   123456         1234567890         1234567890         1234567890    
		//         XXX     $XXXXXX.XX         $XXXXXX.XX         $XXXXXX.XX         $XXXXXXX.XX       
		cout << "--------------------------------------------------------------------------------------" << endl;
		cout << "| Mth | Monthly payment  | Interest payment | Priciple payment | Remaining balance   |" << endl;
		cout << "--------------------------------------------------------------------------------------" << endl;
		while (lc < n + 1)
		{
			mi = r * rb;  // calculate monthly interest amount
			mp = M - mi;  // calculate monthly priciple amount
			rb = rb - mp; // calculate remaining balance


			// Print one row of the table, formatted and aligned 
			cout << setfill(' ') << setw(2) << " ";	// 2 spaces of padding
			cout << setfill(' ') << setw(3) << lc;	// "Mth" field is 3 digits wide

			cout << setfill(' ') << setw(6) << "$";	// 5 spaces of padding, then dollar sign
			cout << setfill(' ') << setw(9) << M;	// "Monthly Payment" field is 9 digits wide

			cout << setfill(' ') << setw(10) << "$";// 10 spaces of padding
			cout << setfill(' ') << setw(9) << mi;	// "Monthly Interest" field is 9 digits wide

			cout << setfill(' ') << setw(10) << "$";// 10 spaces of padding
			cout << setfill(' ') << setw(9) << mp;	// "Principle payment" field is 9 digits wide
			
			cout << setfill(' ') << setw(10) << "$";// 9 spaces of padding
			cout << setfill(' ') << setw(10) << rb; // "Remaining Balance" field is 10 digits wide
			cout << endl;

			lc++;
		}

		// Prompt user if they want to go again. 
		cout << "Continue? (y/n) ";
		cin >> STRT;
		
	}
}