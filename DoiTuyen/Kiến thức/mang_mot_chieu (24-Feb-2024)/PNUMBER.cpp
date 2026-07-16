#include <bits/stdc++.h>
using namespace std;
bool sodep(int num) {
    int chuso;
    while (num > 0) {
        int chuso = num % 10;
        if (chuso != 6 && chuso != 8) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main ()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (sodep(arr[i])) {
            count++;
        }
    }
    cout << count;
    return 0;
}