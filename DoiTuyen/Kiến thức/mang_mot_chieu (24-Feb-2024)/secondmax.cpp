#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double A[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    double max1 = A[0], max2 = -1;
    for(int i = 1; i < n; i++) {
        if(A[i] > max1) {
            max2 = max1;
            max1 = A[i];
        }
    }
     for(int i = 1; i < n; i++) {
        if(A[i] > max2 && A[i] < max1) {
            max2 = A[i];
        }
    }

    if(max2 == -1)
        cout << "NO";
    else
        cout << max2;

    return 0;
    
}