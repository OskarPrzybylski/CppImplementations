#include <iostream>
#include <string>

using std::endl;
using std::string;


class Employee{
public:
string name;
string job;
int age;



Employee();
Employee(std::string, std::string, int); 
friend std::ostream& operator<<(std::ostream&, const class Employee);

};
Employee::Employee(): name(""), job(""), age(0){}

Employee::Employee(std::string newName, std::string newJob, int newAge): name(newName),job(newJob),age(newAge){}

std::ostream& operator<<(std::ostream& out, const Employee q){
    out<<q.name<<"\t"<<q.job<<"\t"<<q.age<<endl;

    return out;
}


