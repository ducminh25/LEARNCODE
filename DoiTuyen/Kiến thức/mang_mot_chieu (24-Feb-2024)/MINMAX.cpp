#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    double A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    double min = A[0], max = A[0];
    for (int j = 0; j < n; j++)
    {
        if (A[j] < min) min = A[j];
    }

    for (int a = 0; a<n; a++)
    {
        if (A[a] > max) max = A[a];
    }
    cout<< fixed << setprecision(2) << max<<" "<<min;
    return 0;
}