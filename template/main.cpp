#include <iostream>
#include <limits>
#include <stdlib.h>
#include "Temp.h"
#include "Employee.h"
#include "Book.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;




int main(){
Temp<int,Employee> employeedata;
Temp<int,Book> bookdata;


employeedata.add(202277,Employee("Oskar","cashier",21));
employeedata.add(202278,Employee("Mateusz","programmer",22));

bookdata.add(212,Book("ksiazk1","komedia",212,true));
bookdata.add(213,Book("ksiazk2","komedia1",230,false));


cout<<bookdata;
cout<<employeedata;





try{
cout<<"wyszukiwanie istniejacego"<<endl;
cout<<employeedata(202277)<<endl;

}
catch(const char* msg){
cout<<msg<<endl;

}


try{
cout<<"wyszukiwanie nieistniejacego"<<endl;
cout<<employeedata(20227)<<endl;


}
catch(const char* msg){
cout<<msg<<endl;
}


return 0;
}
