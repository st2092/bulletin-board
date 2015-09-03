#ifndef USER_H
#define USER_H
#include "message.h"
#include <iostream>
using namespace std;

/*
 * This class represents a user account.
 */
class User {
  private:
    string username;
    string pw;
    
  public:
    User();
    User(const string & username, const string & pw);
    string getUsername() const;
    bool check(const string & username, const string & pw) const;
    void setPassword(const string & new_pw);
};
#endif