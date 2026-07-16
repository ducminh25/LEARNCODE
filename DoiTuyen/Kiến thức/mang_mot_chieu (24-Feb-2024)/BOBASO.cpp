#include <bits/stdc++.h>
using namespace std;
bool isTriangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int countTriangles = 0;
    int maxPerimeter = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (isTriangle(arr[i], arr[j], arr[k])) {
                    ++countTriangles;
                    int perimeter = arr[i] + arr[j] + arr[k];
                    maxPerimeter = max(maxPerimeter, perimeter);
                }
            }
        }
    }

    cout << countTriangles << " " << maxPerimeter;

    return 0;
}
