#include "system.h"
#include "prototypes.h"

//Package 4 - Node Flow rates

void pac_4(int input_lines, int num_nodes , vector <double> &iflows, bool &sol_valid, bool debug )
{
//
	string fn = "pac_4 function" ;
	user_trace(debug , 1 , fn) ;
//

	for (int i =0 ; i<input_lines ; i++ )
	{
		int node_num ;
		double flow ;
		string rawline, node_numstr , flowstr ;
		bool nodeline = true ;

		//get data
		getline (cin , rawline) ;
		int lead_spaces = rawline.find_first_not_of(' ');
		rawline.erase(0, lead_spaces);
			//serparte by ' '
		int space_loc = rawline.find(' ') ;
		node_numstr = rawline.substr ( 0, space_loc ) ;
		flowstr = rawline.substr ( space_loc+1 , rawline.length() ) ;
		node_num = stoi(node_numstr) ;
		flow = stod(flowstr) ;

		//fill iflows vector
		if (node_num <=0 || node_num > num_nodes)
		{
			cout << "Invalid node no. " << node_num << " ; input line ignored." << endl << flush ;
			nodeline = false ;
			continue ;
		} // check that input node no. is valid
		if (nodeline)
		{
			iflows ( node_num) = flow ;

			if(debug)
			{
				cout << "Node Number: " << node_num << '\t' << "Flow rate: " <<  \
					iflows(node_num) << endl << flush ;
			}
		}
		sol_valid = false ;
	}
//
	user_trace(debug , 2 , fn) ;
//
	return ;
}
