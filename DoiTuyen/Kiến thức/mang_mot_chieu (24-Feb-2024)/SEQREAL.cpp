#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    double A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    double sum = 0, sumNeg = 0, sumPos = 0, sumEven = 0, sumOdd = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (A[i] < 0) {
            sumNeg += A[i];
        } else if (A[i] > 0) {
            sumPos += A[i];
        }
        if (i % 2 == 0) {
            sumEven += A[i];
        } else {
            sumOdd += A[i];
        }
    }

    cout << fixed << setprecision(2) << sum << " " << sumNeg << " " << sumPos << " " << sumOdd << " " << sumEven << endl;
    return 0;
}
