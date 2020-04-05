#include "system.h"
#include "prototypes.h"

//Package 3 - Pipe Properties

void pac_3(int input_lines, int num_nodes , int num_pipes, matrix <int> &nodes, \
	vector <double> &plength, vector <double> &pdiameter, vector <double> &phw, bool &sol_valid, bool debug )
{
	string rawline ;
	bool pipeline ;
	if (input_lines > num_pipes)
	{
		user_message(15) ;
		for( int i=0 ; i<input_lines ; i++)
			getline(cin, rawline) ;
		return ;
	}
//
	string fn = "pac_3 function" ;
	user_trace(debug , 1 , fn) ;
//
if (debug)
	cout << "# of input lines: " << input_lines << endl << flush ;
//
	pipeline = true ;
	//set up variables
	int pipe, sn , en;
	double l , d , hw, zero = 0.0 ;

	// read input input_lines
	for (int i=1 ; i<= input_lines ; i++)
	{
		cin >> pipe >> sn >> en >> l >> d >> hw ;
		if (debug)
		{
			cout << pipe << "   " << sn << "   " << en << "   " <<
				l << "   " << d << "   " << hw << endl ;
		}
		//check for inappropriate values
		if ( pipe <=0 || pipe>num_pipes )
		{
			cout << "Invalid pipe no. " << pipe << " ; input line ignored." << endl << flush ;
			pipeline = false ;
			continue ;
		}
		if ( sn <=0 || sn>num_nodes )
		{
			user_message(8);
			cout << pipe << endl << flush ;
			cout << "  >> start node is not acceptable. set to default (0)." << endl << flush ;
			sn = 0 ;
			continue ;
		}
		if ( en <=0 || en>num_nodes)
		{
			user_message(8);
			cout << pipe << endl << flush ;
			cout << "   >> end node is not acceptable. set to default (0)." << endl << flush ;
			en = 0 ;
			continue ;
		}
		if (l <=zero)
		{
			user_message(8);
			cout << pipe << endl << flush ;
			cout << "   >> length of pipe is not acceptable. set to default (0)." << endl << flush ;
			l = zero ;
			continue ;
		}
		if (d <=zero)
		{
			user_message(8);
			cout << d << endl << flush ;
			cout << "   >> diameter of pipe is not acceptable. set to default (0)." << endl << flush ;
			d = zero ;
			continue ;
		}
		if (hw <= zero)
		{
			user_message(8);
			cout << pipe << endl << flush ;
			cout << "   >> hazen williams coef. of pipe is not acceptable. set to default (0)." << endl << flush ;
			hw = zero ;
			continue ;
		}
		if (pipeline)
		{
			//fill nodes arrays
			nodes(pipe , 1) = sn ;
			nodes(pipe , 2) = en ;
			//fill pipe properties vectors
			plength(pipe) = l ;
			pdiameter(pipe) = d ;
			phw(pipe) = hw ;

		}
	}
	 //occurs for each pipe data input line

	if(debug)
	{
		cout << endl << "Pipe Properties to date:" << endl << flush ;
		cout << "PIPE      " << "START NODE\t" << "END NODE  " << "LENGTH    " << \
			"DIAMETER  " << "HW COEF.   " << endl << flush;
		for (int i=1 ; i<num_pipes+1; i++)
		{
			cout << i << "              " << nodes(i,1) << "\t   " <<nodes(i,2) << "        " << \
				plength(i) << "         " << pdiameter(i) << "      " << phw(i) << endl << flush ;
			continue;
		}
	}

	sol_valid = false ;
//
	user_trace(debug , 2 , fn);
//
	return;
}
