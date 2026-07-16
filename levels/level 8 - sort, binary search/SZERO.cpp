#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<long long, int> sum_pos; // Lưu vị trí xuất hiện đầu tiên của một tổng trong mảng tổng cộng dồn
    long long sum = 0;
    int start = -1, end = -1, max_len = 0;

    sum_pos[0] = -1;  // Để xử lý trường hợp tổng từ đầu đến vị trí nào đó bằng 0

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum_pos.find(sum) != sum_pos.end()) {
            int len = i - sum_pos[sum];
            if (len > max_len) {
                max_len = len;
                start = sum_pos[sum] + 1;
                end = i;
            }
        }
        else sum_pos[sum] = i;
    }

    if (start == -1)
        cout << -1 << endl;
    else
        cout << start + 1 << " " << end + 1 << endl;

    return 0;
}