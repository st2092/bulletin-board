#include "message.h"
using namespace std;

/*
 * Default constructor for abstract base class.
 */
Message::Message()
:author(" "), subject(""), body(" "), id(1)
{}

/*
 * This constructor takes in the author, subject, body and id
 * and initialized member variable to those variables.
 */
Message::Message(const string & author, const string & subject, const string & body, unsigned id)
:author(author), subject(subject), body(body), id(id)
{}

/*
 * Returns the subject of the message.
 */
string
Message::getSubject() const
{
  return subject;
}

/*
 * Returns the id of the message.
 */
unsigned
Message::getId() const
{
  return id;
}

/*
 * This method adds the message pointer passed into the method
 * into a vector of messages. The message pointers in the vector
 * points to messages that are a child (reply) to this message.
 */
void
Message::addChild(Message* child_ptr)
{
  child_list.push_back(child_ptr);
}

/*
 * This is the destructor for the Message class that gets call when the program ends.
 */
Message::~Message()
{
  for (unsigned i = 0; i < child_list.size(); i++)
  {
    delete child_list[i];
  }
}
