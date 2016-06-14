#ifndef TOPIC_H
#define TOPIC_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "message.h"
#include "reply.h"
#include "bulletin_board.h"

/*
 * This class is derived from the Message class.
 */
class Topic: public Message {
  // no new member variables, use the ones inherited from Message
  
  public:
    Topic();
    Topic(const string & author, const string & subject, const string & body, unsigned int id);
    virtual void print() const;
    virtual bool isReply() const;
    virtual string toFormattedString() const;
};
#endif
