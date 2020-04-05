#include "system.h"
#include "prototypes.h"


// Package 6 - Tolerance & Max Newton Iterations

void pac_6(int input_lines , double &tol , int &iter_limit , bool &sol_valid, bool debug )
{
//
	string fn = "pac_6 function" ;
	user_trace(debug , 1 , fn) ;
//
	string tolstr , limitstr, rawline ;
	//get data
	cin >> tol >> iter_limit ;

	if (tol <= 0.0)
	{
		cout << "Tolerance must be greater than 0; default of 0.01 is used." << endl << flush ;
		tol = 0.1 ;
	}
	if (iter_limit <=0)
	{
		cout << "Iterations limit must be > 1; default of 5 was used." << endl << flush ;
		iter_limit =  5 ;
	}

	if(debug)
		cout << "Tolerance: " << tol << "\tMax number of iterations: " << iter_limit \
		 << endl << flush ;
	sol_valid = false ;
//
	user_trace(debug , 2 , fn) ;
//
	return ;
}
