#include <bits/stdc++.h>
using namespace std;
 
int max(int a, int b)
{
    return a+b;
}
int max(float a, float b)
{
    return a+b;
}
int main()
{
    cout << "int max = " << max(4, 5) << endl;
    cout << "float max = " << max(4.4, 5.5) << endl;
    return 0;
}