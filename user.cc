#include "user.h"
using namespace std;

/*
 * Default constructor
 * Creates a user object with empty username and password
 */
User::User()
:username(""), pw("")
{}

/*
 * Constructor that creates an user object with specified
 * username and password.
 */
User::User(const string & username, const string & pw)
:username(username), pw(pw)
{}

/*
 * Return the username of this user object.
 */
string
User::getUsername() const
{
  return username;
}

/*
 * Returns true if the stored username and password matches
 * with the parameters.
 *
 * Note: although a User object having the default username/password
 *       is a valid User object, we should still return false 
 */
bool
User::check(const string & username, const string & pw) const
{
  if (username == "" || pw == "")
  {
    // default username and password
    return false;
  }
  else if (this->username == username && this->pw == pw)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/*
 * This method allows the user to change their password.
 */
void
User::setPassword(const string & new_pw)
{
  pw = new_pw;
}
