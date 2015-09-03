#include "topic.h"
using namespace std;

/*
 * Default constructor
 */
Topic::Topic()
:Message()
{}

/*
 * Constructor with parameters. 
 */
Topic:Topic(const string & author, const string & subject, const string & body, unsigned id)
:Message(author, subject, body, id)
{}

/*
 * This method returns true if this object is a reply.
 * In this case, it is always false since this is a topic.
 */
bool
Topic::isReply()
{
  return false;
}

/*
 * This method returns a formatted string of this topic with all of its replies.
 * 
 * Format example:
 *  <begin_topic>
 *  :id: 4
 *  :subject: single line
 *  :from: author
 *  :children: 5 6 (this line should not show if there are no children)
 *  :body: multiple lines - line 1
 *  line 2
 *  line 3
 *  <end>
 */
string
Topic::toFormattedString() const
{
  stringstream formatted_str;
  formatted_str << "<begin_topic>\n" << ":id: " << id
                << "\n:subject:" << subject
                << "\n:from: " << author;
  if (child_list.size() > 0)
  {
    stringstream child_str;
    child_str << child_list[0]->get_id();
    for (unsigned i = 1; i < child_list.size(); i++)
    {
      //child_str << child_list[i]->get_id() << " ";
      child_str << " " << child_list[i]->get_id();
    }
    formatted_str << "\n:children: " << child.str(); 
  }
  
  formatted_str << "\n:body:" << body << "<end>\n"
  return formatted_str.str();
}

/*
 * This method prints the Topic with all of its children and 
 * children sub-tree of replies.
 */
void
Topic::print() const
{
  cout << "Message #" << id << ": "
       << subject << "\n"
       << "from " << author << ": "
       << body;
       
  for (unsigned i = 0; i < child_list.size(); i++)
  {
    dynamic_cast<Reply*>(child_list[i])->print_subtree(1);
  }
}