#include <iostream>
#include <string.h>
using namespace std;

typedef struct Product{
    char name[30];
    int id;
    int price;
}Pr;
void enter(Pr product[], int n);
void printProducts(Pr product[], int n);
Pr *findProduct(Pr product[], int n, int price_search);
int main(){
    int n;
    cout << "Enter the amount of products: ";
    cin >> n;
    Pr list[n];
    enter(list,n);
    cout << "DATA:\n";
    printProducts(list,n);
    int price_search;
    cout << "Enter prive which you want to search: ";
    cin >> price_search;
    Pr *product  = findProduct(list,n,price_search);
    if(product == NULL){
        cout << "The product doesn't exist";
    } else {
        cout << "The product " << product->id;
    }
    return 0;
}
void enter(Pr product[], int n){
    for (int i = 0; i<n; i++){
        cout << "Enter product " << i+1 << ":";
        cout << "\nID:";
        cin >> product[i].id;
        cin.ignore();
        cout << "Name: ";
        cin.get(product[i].name,30);
        cout << "Price: ";
        cin >> product[i].price; 
    }

}
void printProducts(Pr product[], int n){
    for(int i = 0; i<n; i++){
        Pr source = product[i];
        cout << source.id <<"\t" << source.name <<"\t"<<source.price <<endl;
    }
}
Pr *findProduct(Pr product[], int n, int price_search){
    int left = 0, right = n - 1;
    int mid = 0;
    do{
        mid = (left + right)/2;
        Pr find = product[mid];
        if(find.price == price_search){
            return &find;
        } else if (find.price > price_search){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    } while (left <= right);
    return NULL;
}
