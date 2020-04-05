#include "system.h"
#include "prototypes.h"

void net_describe(string &title, int &num_nodes , int &num_pipes , int &resv_node , int &resv_pres ,
						matrix <double> &pipe_prop , matrix <double> &nodes_prop , double &tol, double &iter_limit, vector <int> incid_indexes, vector <int> nodal_incidences, bool &debug)
{
//
	string fn = "network describe function" ;
	user_trace(debug , 1 , fn) ;
//
	linkup(num_pipes, num_nodes, debug, nodes, incid_indexes, nodal_incidences ) ;

	if (!linkup)
		return;

	
	cout << endl << "*" << flush ;
	//user_message(
//
	user_trace(debug, 2, fn);
//
	return ;
}
