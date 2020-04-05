#include "system.h"
#include "prototypes.h"

//Package 1 - New Network

void pac_1( int input_lines, string &title , matrix <int> &nodes, \
	vector <double> &plength, vector <double> &pdiameter, vector <double> &phw, \
	vector <double> &iheads, vector< double> &iflows, int &num_nodes, int &num_pipes, \
	vector <int> &incid_indexes, vector <int> &nodal_incidences, \
	vector <double> &pipe_flows, bool debug )
{
//
	string fn = "pac_1 function" ;
	user_trace(debug , 1 , fn) ;
//

	//delete previously defined network
	nodes.free() ;
	iflows.free() ;
	iheads.free() ;
	plength.free() ;
	pdiameter.free() ;
	phw.free() ;
	incid_indexes.free() ;
	nodal_incidences.free() ;
	pipe_flows.free() ;

	//get network title
	user_message(14) ;
	getline ( cin, title, '\n' ) ;
	int lead_spaces = title.find_first_not_of(' ');
	title.erase(0, lead_spaces);
	if (debug) cout << "\nTitle: " << title << endl << flush ;

	//get number of nodes and pipes
	string nodes_pipes, nodesstr, pipesstr;
	getline(cin , nodes_pipes) ;
	lead_spaces = nodes_pipes.find_first_not_of(' ');
	nodes_pipes.erase(0, lead_spaces);

		//serparte by ' '
	int space_loc = nodes_pipes.find(' ') ;
	pipesstr = nodes_pipes.substr ( 0, space_loc ) ;
	nodesstr = nodes_pipes.substr ( space_loc+1 , nodes_pipes.length() ) ;
	num_pipes = stoi(pipesstr) ;
	if (num_pipes <= 0 || num_pipes >= 1000)
	{
		user_message(7) ;
		user_message(11) ;
		num_pipes = 0 ;
	}
	num_nodes = stoi(nodesstr) ;
	if (num_nodes <= 0 || num_nodes >= 1000)
	{
		user_message(7) ;
		user_message(11) ;
		num_nodes = 0 ;
	}
	if (debug) {
		cout << "\nNumber of Pipes: " << num_pipes
		<< ";\nNumber of Nodes: " << num_nodes << endl << flush ;
	}

	//check limits before creating vectors/arrays
	if (num_nodes <= 0 || num_pipes<=0 || num_nodes>2000 || num_pipes>4000)
	{
		user_message(9) ;
		num_nodes = 2000 ; num_pipes = 4000 ;
	}

	//create nodes matrix and iflows/iheads vectors and fill with 0s

	nodes.create ( 1 , num_pipes , 1 , 2 );
	for (int i = 1 ; i< num_pipes ; i++)
	{
		for (int j=1; j<=2 ; j++) nodes(i , j) = 0 ;
	}
	iheads.create ( 1 , num_nodes) ;
	for (int i = 1 ; i< num_nodes ; i++)
		iheads(i) = 0 ;
	iflows.create ( 1 , num_nodes) ;
	for (int i = 1 ; i< num_nodes ; i++)
		iflows(i) = 0 ;

	//create pipe properties vectors and fill with 0s
	plength.create(1, num_pipes) ;
	for (int i = 1 ; i< num_pipes ; i++) plength(i) = 0 ;
	pdiameter.create(1, num_pipes) ;
	for (int i = 1 ; i< num_pipes ; i++) pdiameter(i) = 0 ;
	phw.create(1, num_pipes) ;
	for (int i = 1 ; i< num_pipes ; i++) phw(i) = 0 ;


	//create link and itp vectors and fill with 0s
	incid_indexes.create ( 1, num_nodes+1 ) ;
	for (int i=1 ; i<= num_nodes+1; i++) incid_indexes(i)=0 ;
	nodal_incidences.create ( 1 , num_pipes*2 ) ;
	for (int i=1 ; i<= num_nodes+1; i++) nodal_incidences(i)=0 ;

	//create solution vectors an fill with 0s
	pipe_flows.create(1, num_pipes) ;
	for (int i=1 ; i<= num_pipes ; i++) pipe_flows(i) = 0 ;

//
	user_trace(debug , 2 ,fn ) ;
//
	return ;
}
