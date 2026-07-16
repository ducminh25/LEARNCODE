#include <bits/stdc++.h>
using namespace std;
int n, k = 1, d = 1, maxx = 1;
int arr[100005];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) { 
        cin >> arr[i];
    }
    
    sort(arr + 1, arr + 1 + n);
    for(int i = 2; i <= n; ++i) {
        if(arr[i] != arr[i - 1]) {
            k++;
            d = 1;
        }
        else d++;
        maxx = max(d, maxx);
    }
    cout << k << endl << maxx << endl;

    return 0;
}