#include "system.h"
#include "prototypes.h"


int main ()
{
	user_message(1) ;
		//welcome message

	matrix <int> nodes ;
		//nodes matrix is used for linkup and contains a row for each pipe
		//col 1 is for the neg node and col 2 is the pos node
		//nodes matrix is defined in pac_1 and filled in pac_3
	nodes.create(1,1,1,1) ;

	vector <double> iheads ;
	vector <double> iflows ;
	iheads.create(1,1) ;
	iflows.create(1,1) ;
		//node properties vectors ihead and iflow will contain a row for each node

	//create vectors for each pipe property
	//length, diameter, hazen coefficient
	//start and end nodes stored in nodes matrix
		vector <double> plength ;
		vector <double> pdiameter ;
		vector <double> phw ;
			//dummy values
		plength.create(1,1) ;
		pdiameter.create(1,1) ;
		phw.create(1,1) ;

	//create vectors for linkup function
	vector <int> link ;
	link.create (1,1) ;
	vector <int> ipt ;
	link.create(1,1);
		// link and itp vectors

	// create vectors for Solution
	vector <double> pipe_flows ;
		// dummy values
	pipe_flows.create(1,1) ;

	int num_nodes = 0, num_pipes = 0, resv_node = 1, iter_limit = 5 ;
	bool debug = true , net_solved = false;
	double tol = 0.01, resv_pres = 1000.0 ;
	string title ;

	int packet_type=0, input_lines=0 ;

	while (true)
	{
// loop count
		cout << "\nHI:)\n" << flush ;
		string rawline, packet, input ;

		cout << "check 2" << endl << flush;

//read in line as a string, convert to variable integers
		//cin >> packet_type >> input_lines ;
		getline(cin, rawline);

		cout << "check 3" << endl << endl << rawline << endl << flush ;

		cin >> packet_type >> input_lines ;

		if (cin.fail())
		{
         cout << "Please enter an integer";
         // clear error state
         cin.clear();
         // discard 'bad' character(s)
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
	//	memset(rawline, 0, rawline.length()) ;
	/*
		int lead_spaces = rawline.find_first_not_of(' ');
		rawline.erase(0, lead_spaces);
		int space_loc = rawline.find(' ') ;
		packet = rawline.substr ( 0, space_loc ) ;
		input =	rawline.substr ( space_loc+1 , rawline.length() ) ;

		cout << packet << '\t' << input << endl << flush ;

		packet_type = stoi(packet) ;
		input_lines = stoi(input) ;
*/
		cout << "Packet type:\t" << packet_type <<"\nInfo:\t" << input_lines << endl << flush;

		if (packet_type == 0)
		{
			pac_0(input_lines, debug) ;
			continue ;
		}
		if (packet_type == 1)
		{
			pac_1(input_lines, title, nodes , plength, pdiameter, \
					phw, iheads, iflows, num_nodes, num_pipes, ipt, \
					link, pipe_flows, debug) ;
			continue ;
		}
		if (packet_type == 2 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			pac_2(input_lines, num_nodes, resv_node, resv_pres, net_solved, debug) ;
			continue ;
		}
		if (packet_type == 3 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			pac_3(input_lines, num_nodes, num_pipes, nodes, plength, pdiameter, phw, net_solved, debug) ;
			continue ;
		}
		if (packet_type == 4 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			pac_4(input_lines, num_nodes, iflows, net_solved, debug) ;
			continue ;
		}
		if (packet_type == 5 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			pac_5(input_lines, num_nodes, resv_node, resv_pres, iheads , net_solved, debug) ;
			continue ;
		}
		if (packet_type == 6 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			pac_6(input_lines , tol, iter_limit, net_solved, debug) ;
			continue ;
		}
		if (packet_type == 7 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			linkup(num_pipes, num_nodes, debug, nodes, ipt, link) ;
			continue ;
		}
		if (packet_type == 8 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			pac_8(input_lines, num_nodes, num_pipes, resv_node, nodes, iheads, iflows, plength, \
						pdiameter, phw, tol, iter_limit, net_solved, pipe_flows, ipt, link, debug ) ;
			continue ;
		}
		if (packet_type == 9 && net_check(num_nodes, num_pipes, input_lines, debug))
		{
			pac_9(input_lines, title, num_nodes , num_pipes , resv_node , resv_pres ,
						iheads, iflows, nodes, plength, pdiameter, phw, tol, iter_limit, debug) ;
			continue ;
		}

		if (packet_type == 10)
		{
			pac_10(input_lines, debug) ;
			continue ;
		}
		if (packet_type == 11)
			break ;
		else if(packet_type > 11 || packet_type < 0 )
		{
			cout << endl << "Invalid packet type: " << packet_type << endl ;
			string trash ;
			for (int q=1 ; q <=input_lines ; q++)
				getline (cin, trash, '\n') ;
		}

	}

	user_message(2) ;

	return 0 ;
}
