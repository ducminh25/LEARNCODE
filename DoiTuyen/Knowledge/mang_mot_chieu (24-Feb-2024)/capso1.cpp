#include <iostream>
using namespace std;

int dem_cap(int arr[], int n, int X) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] + arr[i + 1] == X) {
            count++;
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

    int demcap = dem_cap(arr, n, X);

    cout << demcap << endl;

    return 0;
}