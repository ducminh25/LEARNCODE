#include <bits/stdc++.h>
using namespace std;

void factor (int n) {
    for (int i = 2; i * i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            cout << i << " " << count << endl;
        }
    }
    if (n > 1) {
        cout << n << " " << 1 << endl;
    }
}

int main() {
    int n;
    cin >> n;
    factor(n);
    return 0;
}

/**
int main ()
{
    int n;
    cin >> n;
    int i = 2;
    int arr[100000001];
    while (n > 1)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                arr[i]++;
                n /= i;
            }
        }
        i++;
    }
    for (int i = 1; i <= 100000000; i++)
    {
        if (arr[i] > 0)
        {
            cout << i << " " << arr[i] << endl;
        }
    }
    return 0;
}
**/
