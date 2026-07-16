#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
 
    vector<int> a (n), b (n), c (n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
 
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());
    sort (c.begin(), c.end());
 
    int i = 0, j = 0, k = 0, cnt = 0;
    while (i < n && j < n && k < n) {
        if (a[i] < b[j] && b[j] < c[k]) {
            cnt++;
            i++;
            j++;
            k++;
        } 
        else {
            if (a[i] >= b[j]) j++;
            if (b[j] >= c[k]) k++;
        }
    }
 
    cout << cnt;    
    return 0;
}

/*
Bài code đọc vào ba dãy số nguyên a, b, và c, mỗi dãy có n phần tử. Sau đó, nó sắp xếp lại các phần tử trong từng dãy theo thứ tự tăng dần.

Tiếp theo, bài code sử dụng ba con trỏ i, j, và k để duyệt qua các phần tử trong ba dãy a, b, và c. 
Nếu phần tử tại vị trí i trong dãy a nhỏ hơn phần tử tại vị trí j trong dãy b và phần tử tại vị trí j trong dãy b nhỏ hơn phần tử tại vị trí k trong dãy c, 
thì nó tăng biến cnt lên 1 và di chuyển cả ba con trỏ i, j, và k lên 1.

Nếu không, nó sẽ di chuyển con trỏ j lên 1 nếu phần tử tại vị trí i trong dãy a lớn hơn hoặc bằng phần tử tại vị trí j trong dãy b, 
và di chuyển con trỏ k lên 1 nếu phần tử tại vị trí j trong dãy b lớn hơn hoặc bằng phần tử tại vị trí k trong dãy c.

Cuối cùng, biến cnt sẽ chứa số lượng chỉ số i mà a[i] < b[i] < c[i] là lớn nhất có thể.
*/