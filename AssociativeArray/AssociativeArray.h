#ifndef __ASSOCIATIVEARRAY_H__
#define __ASSOCIATIVEARRAY_H__
#include <string>

struct Node{
Node* next;
std::string key;
int value;
kk
Node(std::string newk, int newv): next(NULL), key(newk), value(newv){}
};

class AssociativeArray{
private:
Node* top;

public:
AssociativeArray();
virtual ~AssociativeArray();
void clear();
Node* check(std::string&);
virtual void changeKey(std::string &key){};
void push(std::string,int);
void print();
class ElementNotFound{};
int &operator[] (std::string);
};


class AssociativeArray2 : public AssociativeArray{

virtual void changeKey(std::string &key);
};


#endif
