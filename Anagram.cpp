#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void permute(string& a, int st, int end)
{
    if (st == end)
        cout << a << endl;
    else {
        // Permutations made
        for (int i = st; i <= end; i++) {
 
            // Swapping done
            swap(a[st], a[i]);
 
            // Recursion called
            permute(a, st + 1, end);
 
            // backtrack
            swap(a[st], a[i]);
        }
    }
}
 
int main()
{
    string str = "BIRO";
    int n = str.size();

    permute(str, 0, n - 1);
    return 0;
}