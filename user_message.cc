#include "system.h"
#include "prototypes.h"

void user_message (int mess_num)
{
	switch (mess_num)
	{
		case 1:
			cout << "Welcome to Pipe Input Project" << endl << endl << flush ;
			break;

		case 2:
			cout << endl << endl <<  "Thank you for using Pipe Input Project. \nGoodbye." << endl << flush ;
			break;

		case 3:
			cout << "Packet type and line count : " << endl << flush ;
			break;

		case 4:
			cout << "A network has not been established. Please enter a packet type 1." << endl << flush;
			break;

		case 5 :
			cout << endl << "THE FOLLOWING NODES WERE NOT MENTIONED IN THIS NETWORK: \n" << flush ;
			break;

		case 6 :
			cout << endl << "The user has called for the solution of this network." << endl << flush ;
			break;

		case 7 :
			cout << endl << "An invalid value was entered by user. The value was not recorded." << endl << flush ;
			break;

		case 8:
			cout << "Invalid value at pipe #: " << endl << flush;
			break;

		case 9 :
			cout << "Number of nodes and pipes must be within range." << endl << flush;
			cout << "\t (0 < # pipes < 4000) ; (0 < # nodes < 2000)" << endl << flush ;
			cout << "Values have been set to the maximums as default." << endl << flush ;
			break;

		case 10 :
			cout << "Reservior node pressure must be a real value. That is, greater than zero." << endl <<
			 	"Reservoir node pressure has been set to the default value (1000.0)" << endl << flush ;
			break ;

		case 11 :
			cout << "Number of nodes and number of pipes must be greater than 0 and less than 1000." << endl << flush ;
			break ;

		case 12 :
			cout << endl << "Solve command not implemented" << endl << flush ;
			break ;

		case 13 :
			cout << endl << "Enter comments for project now." << endl << flush ;
			break ;

		case 14 :
			cout << endl << "Enter data." << endl << flush ;
			break ;

		case 15 :
			cout << endl << "Can not edit more pipes than in network." << endl << flush ;
			break ;

		case 16 :
			cout << endl << "Cannot edit more nodes than in network." << endl << flush ;
			break ;
	}
}
