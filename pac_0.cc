#include "system.h"
#include "prototypes.h"

//Package 0 - Comments

void pac_0( int input_lines , bool debug )
{
//
	string fn = "packet 0 function" ;
	user_trace(debug , 1 , fn) ;
//
	user_message (13) ;
	///cin.ignore();
	string comment_line ;
	for (int i = 0 ; i < input_lines ; i++)
	{
		getline(cin, comment_line, '\n');
		cout << "\ncomment: " << comment_line << endl << flush ;
	}
//
	user_trace(debug , 2 ,fn ) ;
//
	return ;
}
