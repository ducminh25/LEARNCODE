#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("TBC.inp","r", stdin);
    freopen("TBC.out","w", stdout);
    int n;
    cin >> n;
    double arr[n];
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double average = sum / n;
    cout << fixed << setprecision(2) << average << endl;

    double min_difference = abs(arr[0] - average);
    double min_difference_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (abs(arr[i] - average) < min_difference) {
            min_difference = abs(arr[i] - average);
            min_difference_element = arr[i];
        }
    }

    cout << fixed << setprecision(2) << min_difference_element;

    return 0;
}