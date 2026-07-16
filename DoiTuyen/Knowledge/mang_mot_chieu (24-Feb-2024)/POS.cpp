#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double x;
    cin >> n >> x;
    double arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    double first_negative = 0;
    double last_positive = 0;
    int first_x_position = -1;
    int last_x_position = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0 && first_negative == 0) {
            first_negative = arr[i];
        }
        if (arr[i] > 0) {
            last_positive = arr[i];
        }
        if (arr[i] == x) {
            if (first_x_position == -1) {
                first_x_position = i + 1;
            }
            last_x_position = i + 1;
        }
    }

    cout << fixed << setprecision(2) << first_negative << " " << last_positive << endl;
    cout << first_x_position << " " << last_x_position << endl;

    return 0;
}