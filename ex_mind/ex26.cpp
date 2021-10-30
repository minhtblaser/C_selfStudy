#include <bits/stdc++.h>

using namespace std;

int numOfSame(string s1,string s2)
{
    // To store the frequences of characters
    // of string s1 and s2
    int freq1[26] = { 0 };
    int freq2[26] = { 0 };
    int i, count = 0;
    //update the frequencies of two strings
    for (i = 0; i < s1.length(); i++)
        freq1[s1[i] - 'a']++;
    for (i = 0; i < s2.length(); i++)
        freq2[s2[i] - 'a']++;
    // Find the count of valid pairs
    for (i = 0; i < 26; i++)
        count += (min(freq1[i], freq2[i]));
    return count;
}
int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    cout << numOfSame(s1, s2);
    return 0;
}