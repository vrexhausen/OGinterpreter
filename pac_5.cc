#include "system.h"
#include "prototypes.h"

// Package 5 - Node Pressures

void pac_5(int input_lines , int num_nodes, int resv_node, double resv_pres, \
	vector <double> &iheads, bool &sol_valid, bool debug )
{
//
	string fn = "pac_5 function" ;
	user_trace(debug , 1 , fn) ;
//
int node ;
double pres, zero = 0.0 ;
	for (int i = 0 ; i<input_lines ; i++ )
	{
		bool nodeline = true ;
		//get data
		cin >> node >> pres ;
		cout << pres << endl << flush ;
		//fill iheads vector
		if (node <=0 || node > num_nodes)
		{
			cout << "Invalid node no. " << node << " ; input line ignored." << endl << flush ;
			nodeline = false ;
			continue ;
		} // check that input node no. is valid
		else if (node == resv_node)
		{
			cout << "Reservoir head cannot be set through packet 5; input line ignored." << endl << flush ;
			nodeline = false ;
			continue ;
		} // check that input node is not reservoir node
		else if (pres <= zero || pres >= resv_pres)
		{
			cout << "Node no. " << node << ": \n" ;
			cout << "Node pressure must be greater than 0 and less than reservoir head;" << endl << flush ;
			cout << "input line ignored." << endl << flush ;
			nodeline = false ;
			continue ;
		} // check that pressure is in range
		if (nodeline)
		{//fill iheads vector
			cout << "node check!" << endl << flush ;
			iheads ( node ) = pres ;
			if(debug)
			{
				cout << "Node Number: " << node << '\t' << "Flow rate: " <<  \
					iheads( node ) << endl << flush ;
			}
		}
	}
	sol_valid = false ;

	user_trace(debug , 2 , fn) ;
//
	return ;
}
