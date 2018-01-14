
#include <iostream>
#include "AssociativeArray.hpp"

using std::cout;
using std::endl;

int main(){
AssociativeArray array;
AssociativeArray2 array2;

cout<<"push element1 o indeksie 2"<<endl;
array.push("element1",2);
cout<<"push Element2 o indeksie 3"<<endl;
array2.push("Element2",3);
cout<<"element1 wyszukiwany po nazwie element1 ma index:"<<array["element1"]<<endl;
cout<<"Element2 wyszukiwany po nazwie element2 ma index:"<<array2["element2"]<<endl;


cout<<"proba wyszukania Element1 w pierwszej tablicy oraz element3 w drugiej tablicy "<<endl;
try{
cout<<array["Element1"]<<endl;
cout<<array2["element3"]<<endl;
}
catch(const char* msg){
cout<<msg<<endl;
array.clear();
array2.clear();

}

return 0;
}
