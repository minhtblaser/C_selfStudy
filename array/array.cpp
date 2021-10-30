#include <iostream>
using namespace std;

class ArrayList {
public:
	static const int MAX_SIZE = 100; 
	ArrayList(); 			// initialize an empty list 
	bool isEmpty() const; 	// check if the list is empty
	int length() const; 	// get the number of elements in a list
	void insert(const int x, int i); 	// insert x at the position i
	void append(const int x); 	// insert x at the end of the list
	void remove(int i); 		// remove the ith element
	int retrieve(int i) const; // return the value the ith element
	void print() const; 	// print all element values
private:
	int element[MAX_SIZE];	// array to store all list elements
	int last;	// index of the last item
};
// Definition of all ArrayList methods
ArrayList::ArrayList(){
	last = -1;
}
bool ArrayList::isEmpty() const {
	return (last == -1);
}	
int ArrayList::length() const{
	return last + 1; 
}
void ArrayList::append(const int x){
	if (last + 1 == MAX_SIZE){
		cout << "The array is full" << endl;
	}
	element[last + 1] = x;
	last++;
} 
void ArrayList::insert(const int x, int i){
	for(int index = last + 1; index>i; index--){
		element[index] = element[index-1];
	}
	element[i] = x;
	last++;
}
void ArrayList::print() const{
	for(int i = 0; i <= last; i++){
		cout << element[i] << " ";
	}
}
void ArrayList::remove(int i){
	for(int index = i; index < last ; index++){
        element[index] = element[index+1];
    }
    // Giam so luong phan tu sau khi xoa.
    --last;
}
int ArrayList::retrieve(int i) const {
	for(int index = 0; index < last; index++){
		if (index == i){
			return element[i];
		}
	}
}
// Main function
int main() {
	ArrayList list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);
	if (list.isEmpty())
		cout << "Empty list";
	cout << list.length();
	cout << endl;
	list.print();
	cout << endl;
	list.insert(11,3);
	list.print();
	cout << endl;
	list.remove(1);
	list.print();
	cout << endl;
	cout << list.retrieve(3);
	return 0;
}