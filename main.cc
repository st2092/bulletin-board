#include "bulletin_board.h"
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

/*
 * This method sets up the bulletin board.
 * Loads in the users and messages from files.
 */
void
bulletin_board_init(BulletinBoard & bb, const string & user_data_file, const string & message_data_file)
{
	// load users from file
	if (!bb.loadUsers(user_data_file))
	{
		cerr << "Unable to load users from " << user_data_file << endl;
		exit(EXIT_FAILURE);
	}
	
	// load messages
	if (!bb.loadMessages(message_data_file))
	{
		cerr << "Unable to load messages from " << message_data_file << endl;
		exit(EXIT_FAILURE);
	}
}

int main (int argc, char** argv)
{
	if (argc != 3)
	{
		cerr << "Invalid usage!" << endl;
		cout << "Format: <program> <user_data_file> <message_data_file>" << endl;
		exit(-1);
	}
	
	// initialize bulletin board
	string user_data_file(argv[1]);
	string message_data_file(argv[2]);
	
	BulletinBoard bulletin_board;
	bulletin_board_init(bulletin_board, user_data_file, message_data_file);
	bulletin_board.run();
	
	// save messages and users
	
	return 0;
}
