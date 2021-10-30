
// C++ program to reverse a string using recursion
#include <bits/stdc++.h>
#include<string>

using namespace std;
 
/* Function to print reverse of the passed string */
void reverse(string str)
{
    if(str.size() == 0)
    {
        return;
    }
    reverse(str.substr(1));
    cout << str[0];
}
 
/* Driver program to test above function */
int main()
{
    string a;
    getline(cin, a);
    reverse(a);
    return 0;
}
 
// This is code is contributed by rathbhupendra