#include "bulletin_board.h"
using namespace std;

unsigned message_count = 0;

/*
 * This method adds the user into the list of user.
 * Users that are in the list of user are registered
 * user of the bulletin board.
 */
void
BulletinBoard::addUser( const string & username, const string & pw )
{
  list_of_users.push_back( User(username, pw) );
}
 
/*
 * This method returns true if the user exist.
 */
bool
BulletinBoard::userExists( const string & username, const string & pw )
{
  for(unsigned i = 0; i < list_of_users.size(); i++)
  {
    // check if user exists
    if ( list_of_users[i].check(username, pw) )
    {
      return true;
    }
  }
  
  return false; // user does not exist
}
  
/*
 * This method loads in a list of users from a file.
 * The format of the user file is the following:
 *    < username >
 *    < password >
 */
bool
BulletinBoard::loadUsers( const string & filename )
{
  ifstream input (filename.c_str());
  string username;
  string pw;
  if (input)
  {
    while (!input.eof())
    {
      input >> username;
      if (input.eof())
      {
        return false;  // file format is incorrect (password for username should follow)
      }
      else
      {
        input >> pw;
        addUser(username, pw);
      }
    }
   
    input.close();
    return true;
  }
  else
  {
    // input file stream is invalid
    return false;
  }
}
   
/*
 * This method gets the user from the list of users that matches
 * the username passed in.
 * Returns the default user if not found.
 */
User
BulletinBoard::getUser( const string & username )
{
  for (unsigned i = 0; i < list_of_users.size(); i++)
  {
    if (list_of_users.getUsername() == username)
    {
      return list_of_users[i];
    }
  }
 
  User not_found();
  return not_found;
}
   
/*
 * This method displays messages currently on the 
 * bulletin board.
 */
void
BulletinBoard::display() const
{
  string seperator (150, '=');
  cout << "\n" << seperator << "\n";
  for (unsigned i = 0; i < list_of_messages.size(); i++)
  {
    if (!list_of_messages[i]->isReply())
    {
      list_of_messages[i]->print();
      cout << seperator << endl;
    }
  }
}
    
/*
 * This method loads in a file containing all the messages
 * into the bulletin board when it exited last time.
 */
bool
BulletinBoard::loadMessages( const string & filename )
{
  ifstream input (filename.c_str());
  if (input)
  {
    // do nothing for now
  }
  else
  {
    // input file stream is invalid
    return false;
  }
}
     
/*
 * This method adds a new topic to the bulletin board.
 */ 
void
BulletinBoard::addTopic()
{
  string subject;
  string body;
  stringstream stringstream_subject;
  stringstrea stringstream_body;
  
  // get subject and message from user
  cout << "Subject: ";
  getline(cin, subject);
  stringstream_subject << subject;
  
  cout << "Message: ";
  while (getline(cin, body))
  {
    if (body != "")
    {
      // add message to stringstream 
      stringstream_body << body << "\n";
    }
    else
    {
      break;
    }
  }
  
  // create message and add to list
  Message* msg_ptr = new Topic(current_user.getUsername(),    // username
                               stringstream_subject.str(),    // subject
                               stringstream_body.str(),       // message
                               list_of_messages.size() + 1);  // post number or id
  list_of_messages.push_back(msg_ptr);
  message_count++;
  cout << "Post added!" << endl;
}
      
/*
 * This method adds a reply to a Topic.
 */
void
BulletinBoard::addReply()
{
  if (list_of_messages.size() == 0)
  {
    // there are no topics in bulletin board yet
    return;
  }
  cout << "\nEnter Topic ID ( '-1' for Menu): ";
  int topic_id;
  cin >> topic_id;
  if (topic_id ==  -1)
  {
    // return to menu
    return; 
  }
  else
  {
    while (topic_id > list_of_messages.size())
    {
      // topic id is invalid
      cout << "Invalid topic id!" << endl;
      cout << "Enter Topic ID (-1 for Menu): ";
      cin >> topic_id;
      if (topic_id == -1)
      {
        // return to menu
        return;
      }
    }
   
    // get reply from user
    cout << "Enter Message: ";
    string body;
    stringstream stringstream_body;
    //getline(cin, message);
    while (getline(cin, body))
    {
       if (body != "")
       {
         stringstream_body << body << "\n";
       }
       else
       {
         break;
       }
    }
   
    // add reply to topic post
    Message* msg_ptr = new Reply(current_user.getUser,
                                "Re: " + list_of_messages[topic_id - 1]->getSubject(),
                                "\t" + stringstream_body.str(),
                                message_count + 1);
    list_of_messages.push_back(msg_prt);
    message_count++;
    list_of_messages[topic_id - 1]->addChild(msg_ptr);
    cout << "Post added!" << endl;
  }
}

/*
 * Constructor for the bulletin board class.
 * This constructor gives the bulletin board a default name.
 */
BulletinBoard::BulletinBoard()
:bulletin_board_title("Fairy Tail Bulletin Board")
{}

/*
 * Constructor for the bulletin board class.
 * This constructor assigns the bulletin board title passed
 * into the constructor.
 */
BulletinBoard::BulletinBoard(const string & board_title)
:bulletin_board_title(board_title)
{}

/*
 * This method is the destructor of the bulletin board class.
 * Deletes all the allocated memory for the messages.
 */
BulletinBoard::~BulletinBoard()
{
  for (unsigned i = 0; i < list_of_messages.size(); i++)
  {
    delete *(list_of_messages[i]);
  }
}

/*
 * This method allows the user to login to the bulletin board.
 * A user can only make a post if they are logged in.
 */
void
BulletinBoard::login()
{
  string username;
  string pw;
  bool logged_in = false;
  while (!logged_in)
  {
    cout << "username [enter 'back' for menu]: ";
    getline(cin, username);
    if (username == "back")
    {
      // return back to menu
      return;
    }
    else
    {
      cout << "password: ";
      getline(cin, pw);
      logged_in = userExists(username, pw);
      if (!logged_in)
      {
        cout << "Username or password is not on record!" << endl;
      }
    }
  }
  
  // logged in successfully
  current_user = new User(username, pw);
  cout << "Welcome " << current_user.getUsername() << "!" << endl;
}

/*
 * This method allows the user to log off.
 */
void
BulletinBoard::logout()
{
  delete current_user;
  current_user = new User();
}

/*
 * This method displays the menu of available action.
 */
 void
 display_menu()
 {
   cout << "+-------------------------------------------------+\n"
        << "|                   ~ Menu ~                      |\n"
        << "|   'D' or 'd': Display Messages                  |\n"
        << "|   'N' or 'n': Add New Topic                     |\n"
        << "|   'R' or 'r': Add Reply to a Topic              |\n"
        << "|   'L' or 'l': Login                             |\n"
        << "|   'O' or 'o': Logout                            |\n"
        << "|   'Q' or 'q': Quit                              |\n"
        << "+-------------------------------------------------+"
        << endl;
 }

/*
 * This method runs the method to perform the action issued by
 * the user.
 * Returns true to indicate keep running; false for quitting
 */
bool
perform_action(const char & action)
{
  swtich (action)
  {
    case 'D': case 'd': // display messages
      if (list_of_messages.size() <= 0)
      {
        cout << "\nNo messages to display." << endl;
      }
      else
      {
        display();
      }
      return true;
      break;
    case 'N': case 'n': // add new topic
      addTopic();
      return true;
      break;
    case 'R': case 'r': // add reply to a topic
      addReply();
      return true;
      break;
    case 'L': case 'l': // login
      login();
      return true;
      break;
    case 'O': case 'o': // logout
      logout();
      cout << "Log off successfully." << endl;
      return true;
      break;
    case 'Q': case 'q': // quit
      return false;
      break;
    default:
      cout << "Invalid option! Please try again." << endl;
      return true;
      break;
  }
}
 
/*
 * This method runs the bulletin board and interacts with the
 * user through the menu. 
 */
void
BulletinBoard::run()
{
  char action;
  bool keep_running = true;
  while (keep_running)
  {
    display_menu();
    cout << "Enter action to perform: ";
    cin >> action;
    if (action == 'Q' || action == 'q')
    {
      break;
    }
    if (!current_user.userExists() && (action != 'L' || action != 'l'))  
    {
      // user not logged in yet
      while (action != 'L' || action != 'l')
      {
        cout << "Action is invalid, please log in first." << endl;
        cout << "Enter action to perform: ";
        cin >> action;
      }
    }
    if (current_user.userExists() && (action == 'L' || action == 'l'))
    {
      // user is logged in and wants to login again
      while (action == 'L' || action == 'l')
      {
        cout << "Action is invalid, please log in first." << endl;
        cout << "Enter action to perform: ";
        cin >> action;
      }
    }
    keep_running = perform_action(action);
  }
  
  // user wants to quit
  // backup all the necessary information
}

/*
 * This method save messages to a data file for backup.
 */
bool
BulletinBoard::saveMessages(const string & filename)
{
  ofstream output (filename.c_str());
  if (output)
  {
    output << list_of_messages.size() << "\n";
    for (unsigned i = 0; i < list_of_messages.size(); i++)
    {
      output << list_of_messages[i]->toFormattedString();
    }
    
    output.close();
    return true;
  }
  else
  {
    return false;
  }
}