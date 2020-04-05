#include "system.h"
#include "prototypes.h"

//Package 2 - reservation node & pressure

void pac_2(int input_lines, int num_nodes , int &resv_node , double &resv_pres, bool &sol_valid, bool debug )
{
//
	string fn = "packet 2 function" ;
	user_trace(debug , 1 , fn) ;
//
	string rawline, resv_nodestr , resv_presstr ;
	getline(cin, rawline) ;

	int nchars = rawline.length();
	int lead_spaces = rawline.find_first_not_of(' ');
	rawline.erase(0, lead_spaces);
		//serparte by ' '
	int space_loc = rawline.find(' ') ;
	resv_nodestr = rawline.substr ( 0, space_loc ) ;

	space_loc = space_loc+1 ;
	int space_loc2 = rawline.find_last_not_of(' ') ;
	int buffer = (space_loc2 - space_loc) ;
	resv_presstr = rawline.substr ( space_loc, buffer+1 ) ;
	resv_node = stoi(resv_nodestr) ;
	resv_pres = stoi(resv_presstr) ;

// check reservoir node
	if (resv_node <=0 || resv_node > num_nodes)
	{
			user_message(7) ;
			cout << endl << "Reservoir node must be greater than 0 and less than the total number of nodes." <<
				endl << "Reservoir node has been set to the default (1)." << endl ;
			resv_node = 1 ;
	}

// check resrevoir node pressure
	if (resv_pres <= 0)
	{
		user_message(7) ;
		user_message(10) ;
		resv_pres = 1000.0 ;
	}

	if (debug) {
		cout << "Reservoir node number: " << resv_node << endl <<
			"Reservoir head: " << resv_pres << endl << flush ;
		}
	sol_valid = false ;

//
	user_trace(debug , 2 , fn) ;
//
	return ;
}
