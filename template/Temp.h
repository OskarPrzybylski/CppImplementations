#include <iostream>


using std::endl;



template<typename KEY, typename DATA> class Temp{

private:


struct el{
DATA data;
KEY key;
el *next;

el(DATA newdata, KEY newkey): data(newdata), key(newkey), next(NULL){};

el(const el *k): data(k->data), key(k->key), next(NULL){};

};
el *head;

public:


Temp();
~Temp();
void add(KEY,DATA);
el* at(KEY&);
DATA &operator()(KEY);

class InvalidID{};


friend std::ostream& operator<<(std::ostream& out, const Temp<KEY, DATA>& q){
el *buf=q.head;

while(buf){
out<<buf->key<<"\t"<<buf->data<<endl;
buf=buf->next;

}
return out;

}



};



template<typename KEY, typename DATA> Temp<KEY, DATA>::Temp(){

head=NULL;

}

template<typename KEY, typename DATA> Temp<KEY, DATA>::~Temp(){
el *buf;

while(head){
buf=head->next;
delete head;
head = buf;
}

}


template<typename KEY, typename DATA> void Temp<KEY, DATA>::add(KEY newKey, DATA newValue){

KEY buf = newKey;

el *newcell = at(buf);
if(newcell == NULL){
newcell = new el(newValue, buf);
newcell->next=head;
head=newcell;

}
else{
newcell->data=newValue;

}



}


template<typename KEY, typename DATA> typename Temp<KEY,DATA>::el* Temp<KEY,DATA>::at(KEY& str){

el* buf=head;


while(buf){

if(buf->key == str){
return buf;
}
buf=buf->next;
}

return NULL;
}

template<typename KEY, typename DATA> DATA& Temp<KEY, DATA>::operator()(KEY str){
el *buf=at(str);


if(buf==NULL){
throw InvalidID();
}
return buf->data;


}

