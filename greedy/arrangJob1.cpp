#include <bits/stdc++.h>

using namespace std;

struct time{
    int start,end;
};
struct time data[100];
bool cmp (struct time start1,struct time start2){
    return start1.end < start2.end;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> data[i].start;
    }
    for(int i=0; i<n; i++){
        cin >> data[i].end;
    }
    sort(data,data + n, cmp);
    int count = 1, j = 0;
    for(int i=1; i<n; i++){
        if(data[j].end <= data[i].start){
            count++;
            j = i;
        }
    }
    cout << count << endl;
    return 0;
}