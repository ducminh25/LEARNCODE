#include <bits/stdc++.h>
using namespace std;

bool nguyento(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (nguyento(arr[i])) {
            count++;
            sum += arr[i];
        }
    }

    cout << count << sum;

    return 0;
}