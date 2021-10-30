#include <iostream>

using namespace std;

int n = 2;

int *arr;

bool nextBinary(int *arr)
{

    // in mảng.

    for (int j = 0; j < n; j++)
    {

        cout << arr[j] << " ";
    }

    cout << endl;

    //sinh mảng binary kế tiếp

    int index = n - 1;

    while (arr[index] == 1 && index >= 0)
        index--;

    //mảng binary cuối cùng -> return false.

    if (index == -1)
        return false;

    arr[index] = 1;

    for (int i = index + 1; i < n; i++)
    {

        arr[i] = 0;
    }

    return nextBinary(arr);
}

int main()
{

    freopen("BINARY.OUT", "w", stdout);

    //init first binary array.

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {

        arr[i] = 0;
    }

    nextBinary(arr);

    return 0;
}