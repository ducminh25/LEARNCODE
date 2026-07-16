#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(a[i], a[min_idx]);
        }
    }
}

void input() {
    if (!(cin >> n)) return;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void solve() {
    selectionSort(a, n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0);
    cout.tie (0);

    input();
    solve();

    cerr << "hello" << " ";

    return 0;
}


/*
5 4 2 7 8
*/