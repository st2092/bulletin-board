#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "user.h"
using namespace std;

/*
 * This class is an abstract base class.
 */
class Message
{
  protected:  // allow access to these members by objects of derived classes
    string author;
    string subject;
    string body;
    unsigned id;
    vector<Message*> child_list;
    
  private:
    Message();
    Message(const string & author, const string & subject, const string & body, unsigned id);
    virtual void print() const = 0;   // must be defined by every derived class
    virtual bool isReply() const = 0; // must be defined by every derived class
    string getSubject() const;
    unsigned getId() const;
    virtual string ToFormattedString() const = 0; // must be defined by every derived class
    virtual ~Message();
    void addChild(Message* child);
};
#endif