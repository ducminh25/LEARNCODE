/*#include <bits/stdc++.h>
using namespace std;
void solve() {

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int maxSum = INT_MIN;
    for (int i = 0; i <= n - k; ++i) {
        int sum = 0;
        for (int j = i; j < i + k; ++j) {
            sum += arr[j];
        }
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    return 0;
//Partial result: 75/100
}
*/
#include <bits/stdc++.h>
using namespace std;

int n, a[100005], k;
long long s[1000005], maxx;
void nhap() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
void giai() {
    // tinh s[1]
    for (int i = 1; i <= k; i++)
        s[1] = s[1] + a[i];
    // tinh s[2], s[3], ..., s[n]
    for (int i = 2; i <= n - (k - 1); i++)
        s[i] = s[i - 1] - a[i - 1] + a[i + (k - 1)];
    // tim maxx
    maxx = s[1];
    for (int i = 2; i <= n - (k - 1); i++)
        if (s[i] > maxx)
            maxx = s[i];
    cout << maxx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    nhap();
    giai();
}
