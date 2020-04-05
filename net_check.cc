#include "system.h"
#include "prototypes.h"

bool net_check(int num_nodes , int num_pipes, int input_lines,  bool debug)
{
//
	string fn = "network check function" , rawline ;
	user_trace(debug , 1 , fn) ;
//

//check for existence of nodes and pipes
	// == check for existence of network

	if (num_nodes<=0 && num_pipes<=0)
	{
		user_message(4);
		for( int i=0 ; i<input_lines ; i++)
			getline(cin, rawline) ;
//
		user_trace(debug, 2, fn) ;
//
		return (false) ;
	}
//
	user_trace(debug, 2, fn) ;
//
	return (true) ;
}
