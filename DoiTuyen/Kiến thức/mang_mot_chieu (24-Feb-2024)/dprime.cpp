#include <bits/stdc++.h>
using namespace std;

bool nguyento(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int tongchuso(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool nguyentoSum(int n) {
    return nguyento(tongchuso(n));
}

int dem(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nguyento(arr[i]) && nguyentoSum(arr[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("dprime.inp", "r", stdin);
    //freopen("dprime.out", "w", stdout);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = dem(arr, n);
    cout << count << endl;
    
    for (int i = 0; i < n; i++) {
        if (nguyento(arr[i]) && nguyentoSum(arr[i])) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}