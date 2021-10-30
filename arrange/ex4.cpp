#include<iostream>

using namespace std;

void quickSort(int b[], int l, int r){
	int p = b[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (b[i] < p){
			i++;
		}
		while (b[j] > p){
			j--;
		}
		if (i <= j){
			int temp = b[i];
			b[i] = b[j];
			b[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(b, i, r);
	}
	if (l < j){
		quickSort(b, l, j);
	}
}
void printArray(int a[], int n){
    for (int i = 0; i < n; i++){
    	cout << a[i] << " ";
	}
}
int a[100001], b[100001];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            b[k] = a[i];
            k++;
        }
    }
    quickSort(b,0,k-1);
    k = 0; 
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            a[i] = b[k];
            k++;
        }
    }         
    for(int i = n-1; i >= 0; i--){
        if(a[i] < 0){
            a[i] = b[k];
            k++;
        }
    }
	printArray(a, n);
}