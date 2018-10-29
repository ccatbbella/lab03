#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  if(head == 0 && tail == 0){
    head = new StudentRoll::Node;
    head -> next = 0;
    tail = head;
    head -> s = new Student(s);
  }
  else{
    StudentRoll::Node* n = new StudentRoll::Node;
    n -> next = 0;
    n -> s = new Student(s);
    tail -> next = n;
    tail = n;
  }    
}

std::string StudentRoll::toString() const {
  if(head == NULL && tail == NULL) return "[]";
  std::string f = "[";
  StudentRoll::Node* n = head;
  if(head == tail){
    f+=head->s->toString();
    f+="]";
    return f;
  }
  while(n != tail){
    f = f + n->s->toString() + ",";
    n = n->next;
  }
  f = f + tail->s->toString() + "]";
  return f;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  *this = orig;
}

StudentRoll::~StudentRoll() {
  StudentRoll::Node* n = head;
  while(n){
    head = n->next;
    delete n->s;
    delete n;
    n = head;
  }
  head = NULL;
  tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  if (&right == this) 
    return (*this);
  this->~StudentRoll();
  StudentRoll::Node* n = right.head;
  while(n){
    this->insertAtTail(*(n->s));
    n = n->next;
  }
  

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





