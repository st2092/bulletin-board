#ifndef BBOARD_H
#define BBOARD_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "message.h"
#include "user.h"
#include "topic.h"
#include "reply.h"
using namespace std;

/*
 * This is the main class to the bulletin board.
 * This class manages the messages, users, and functionality
 * to keep the bulletin board running.
 */
 class BulletinBoard {
   private:
    string bulletin_board_title;
    User current_user;
    vector<User> list_of_users;
    vector<Message*> list_of_messages;
    
    // helper functions
    void addUser(const string & name, const string & pw);
    bool userExists(const string & name, const string & pw) const;  // ensure function cannot modify member variables
    User getUser(const string & name) const;
    void display() const;
    void addTopic();
    void addReply();
    
   public:
    BulletinBoard();
    BulletinBoard( const string & title);
    ~BulletinBoard();
    bool loadUsers( const string & filename);
    bool loadMessages( const string & filename);
    bool saveMessages( const string & filename);
    void login();
    void logout();
    void run();
 };
#endif