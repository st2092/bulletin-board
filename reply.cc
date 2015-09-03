#include "reply.h"
using namespace std;

/*
 * Default constructor
 */
Reply::Reply()
:Message()
{}

/*
 * Constructor with parameters. 
 */
 Reply::Reply(const string & author, const string & subject, const string & body, unsigned id)
 :Mesage(author, "Re: " + subject, body, id)
 {}
 
/*
 * This method prints the reply.
 */
void
Reply::print() const
{
  cout << "\tMessage #" << id << ":" << subject
       << "\tfrom " << author << ": " << body;
}

/* Tentative function
 * This method prints the Reply and all of its subtree recursively.
 * After printing the Reply with the given indentation and format it
 * calls the printSubtree() method of all the Replies in its child_list
 * with incremented indentation value.
 *
 * Note: each indentation value represent 2 spaces.
 * e.g. indentation = 2 then reply should be indented 4 spaces
 */
void
Reply::print_subtree(int indentation)
{
  // not yet implemented
}

/*
 * This function returns true if the object is a Reply.
 * In this case, this method always return true.
 */
bool
Reply::isReply() const
{
  return true;
}

/*
 * This method writes the contents of the Reply to a string in the following format:
 *  <begin_reply>
 *  :id: 4
 *  :subject: single line
 *  :from: author
 *  :children: 5 6 (this line should not be printed if there are no children)
 *  :body: multiple lines
 *  2nd line
 *  <end>
 */
string
Reply::toFormattedString() const
{
  stringstream formatted_str;
  formatted_str << "<begin_reply>\n" << ":id: " << id
                << "\n:subject:" << subject
                << "\n:from: " << author;
  if (child_list.size() > 0)
  {
    stringstream child_str;
    child_str << child_list[0]->getId();
    for (unsigned i = 1; i < child_list.size(); i++)
    {
      child_str << " " << child_list[i]->getId();
    }
    formatted_str << "\n:children: " << child_str.str();
  }
  
  formatted_str << "\n:body:" << body << "<end>\n";
  return formatted_str.str();
}