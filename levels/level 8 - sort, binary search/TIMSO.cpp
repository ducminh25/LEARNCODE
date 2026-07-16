#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr, arr + n);
    cout << arr[0] << " " << arr[n - 1] << endl;
    for (int i = 0; i <= n - 2; ++i) {
        for(int j = arr[i] + 1; j <= arr[i + 1] - 1; ++j) {
            cout << j << " ";
        }
    }

    return 0;
}