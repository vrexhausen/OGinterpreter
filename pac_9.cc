#include "system.h"
#include "prototypes.h"

//Package 9 - Network Description

void pac_9( int input_lines, string title, int num_nodes , int num_pipes , int resv_node , double resv_pres ,
						vector <double> iflows, vector <double> iheads , matrix <int> nodes, vector <double> plength, \
						vector <double> pdiameter, vector <double> phw, double tol, int iter_limit, bool debug)
{
//
	string fn = "pac_9 function" ;
	user_trace(debug , 1 , fn) ;
//
		//output of the network description
//
	fn = "network describe" ;
	user_trace(debug , 1 , fn) ;
//
		// Header Box
		for (int i = 0 ; i<75 ; i++ )
			cout << left << "*" ;

		cout << endl << "*" << flush;
		for (int i=0 ; i<73 ; i++)
			cout <<left << " " << flush ;
		cout << "*" << flush ;

		string head = "Steady-State Pressurized Pipe Flow Analysis" ;
		int title_len = head.length() ;
		int lead_space = (73 - title_len)/2 ;
		cout << endl << "*" << flush;
		for (int i=0 ; i < lead_space ; i++ )
			cout << " " << flush ;
		cout << head << flush ;
		for (int i=0 ; i < lead_space ; i++ )
			cout << " " << flush ;
		cout << "*" << endl << flush ;

		cout << "*" << flush;
		for (int i=0 ; i<73 ; i++)
			cout << " " << flush ;
		cout << "*" << endl << flush ;

		string sub_head = "-- Tabular Listing of Network Data --" ;
		title_len = sub_head.length() ;
		lead_space = (73 - title_len)/2 ;
		cout << "*" << flush;
		for (int i=0 ; i < lead_space ; i++ )
			cout << " " << flush ;
		cout << left <<sub_head << flush ;
		for (int i=0 ; i < lead_space ; i++ )
			cout << " " << flush ;
		cout << "*" << endl << flush ;

		cout << "*" << flush;
		for (int i=0 ; i<73 ; i++)
			cout << " " << flush ;
		cout << "*" << endl << flush ;

		for (int i = 0 ; i<75 ; i++ )
			cout << left << "*" << flush;


		// Network Specifics
		cout << endl << endl << "Project: " << title << endl << flush ;
		cout << endl << "Number of Nodes: " << num_nodes
			<< "   Number of Pipes: " << num_pipes << endl << flush ;
		cout << endl << "Reservoir Node:  " << resv_node << "   Reservoir Head:  "
			<< setprecision(1) << resv_pres << endl << flush ;

		// Pipe Properties
		string pipe_sub_head = "Pipe Properties" ;
		int underline = pipe_sub_head.length() ;

		cout << endl << pipe_sub_head << endl << flush ;
		for (int i = 0 ; i < underline ; i++ )
			cout << "-" << flush ;

		cout << endl << left <<  "Pipe    " << "Start-Node    " << "End-Node    " << \
			"Length    " << "Diameter    " << "Hazen Coefficient" << endl << flush ;
		cout << setw(50) << right << "(ft)       (in)" << endl << flush ;

		string pipe_num , start, end, l, d, hw ;
		for (int p = 1 ; p<=num_pipes ; p++)
		{
			cout << right << fixed << setw(3) << p ;
			cout << right << fixed << setw(11) << nodes(p,1) ;
			cout << right << fixed << setw(11) << nodes(p,2) ;
			cout << right << fixed << setw(10) << setprecision(1) << plength(p) ;
			cout << right << fixed << setw(14) << setprecision(1) << pdiameter(p) ;
			cout << right << fixed << setw(16) << setprecision(1) << phw(p) << endl << flush ;
		}

		//nodal flows/heads
		string node_sub_head = "External Nodal Flows and Inital Heads" ;
		underline = node_sub_head.length() ;

		cout << endl << node_sub_head << endl << flush;
		for (int i = 0 ; i < underline ; i++ )
			cout << "-" << flush ;

		cout << "\nNode    External Flow Rate    Inital Head" << endl << flush ;
		cout << setw(38) << right << "(cfs)               (ft)" <<endl << flush ;

		string node_num , flowrt , ihead ;
		for (int n = 1 ; n<num_nodes ; n++)
		{
			cout << right << fixed << setw(3) << n ;
			cout << right << fixed << setw(16) << setprecision(1) << iflows(n) ;
			cout << right << fixed << setw(18) << setprecision(1) << iheads(n) << endl << flush ;
		}

		// tolerance and iteration limit
		cout << endl << "Newton Tolerance:       " << setprecision(3) << tol
			<< endl << endl << "Newton Iteration Limit:  " << iter_limit << endl << endl << flush;

		for (int i = 0 ; i < 30 ; i++ )
			cout << "-" << flush ;
		cout << endl << endl << flush ;
//
		user_trace(debug, 2, fn) ;

	if (input_lines == 2)
	{
		//solution output
		user_message(12) ;
	}
//
	fn = "pac_9 function" ;
	user_trace(debug , 2 , fn) ;
//
	return;
}
