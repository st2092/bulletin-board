#ifndef REPLY_H
#define REPLY_H
#include <iostream>
#include <vector>
#include "message.h"

class Reply: public Message {
  private:
    //unsigned parent_id;
  
  public:
    Reply();
    Reply(const string & author, const string & subject, const string & body, unsigned id);
    virtual void print() const;
    virtual void printSubtree(int indentation) const;
    virtual bool isReply() const;
    virtual string toFormattedString() const;
    //unsigned getParentId() const;
};
#endif