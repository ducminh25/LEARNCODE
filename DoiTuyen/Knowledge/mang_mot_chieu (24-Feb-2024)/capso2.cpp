#include <bits/stdc++.h>
using namespace std;

int capso(int arr[], int n, int X) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == X) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, X;
    cin >> n >> X;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dem = capso(arr, n, X);

    cout << dem << endl;

    return 0;
}