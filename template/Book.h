#include <string>
#include <iostream>

using std::endl;
using std::string;
class Book{
public:
    string name;
    string category;
    int pages;
    bool onStock;
	
    Book();
    Book(string, string, int, bool);
    friend std::ostream& operator<<(std::ostream&, const Book);
};

Book::Book(): name(""), category(""), pages(0), onStock(false){}

Book::Book(string newName, string newCategory, int newPages, bool newstock):
	name(newName), 
	category(newCategory), 
	pages(newPages), 
	onStock(newstock){}

std::ostream& operator<<(std::ostream& out, const Book q){
    out<<q.name<<"\t"<<q.category<<"\t"<<q.pages<<"\t"<<q.onStock<<endl;
	
    return out;
}
