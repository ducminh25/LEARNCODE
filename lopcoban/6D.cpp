/*#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, d;
    cin >> n >> d;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] >= arr[j]) 
            {
                arr[j] = arr[j] + d;
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
//Cách làm chưa chuẩn*/
#include <iostream>
using namespace std;
long long n, d, count = 0, k;
int main() {
    cin >> n >> d;
    long long arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long count = 0;
    for (int i = 2; i <= n; i++) {
        if (arr[i] <= arr[i - 1]) {
            k = (arr[i - 1] - arr[i]) / d + 1;
            arr[i] += k * d;
            count += k;
        }
    }

    cout << count;

    return 0;
}