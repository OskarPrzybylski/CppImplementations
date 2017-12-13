
#include <iostream>
#include "AssociativeArray.hpp"

using std::cout;
using std::endl;

int main(){
AssociativeArray array;
AssociativeArray2 array2;

array.push("kurde",2);
array2.push("Kurde",3);
try{
cout<<array["kurdek"]<<endl;
cout<<array2["KURDEk"]<<endl;
}
catch(const char* msg){
cout<<msg<<endl;
array.clear();
array2.clear();

}

return 0;
}
