#include <bits/stdc++.h>
using namespace std;

// Hàm đệ quy để tìm số lượng cách biểu diễn N thành tổng của tối đa k số lập phương
int findWays(int N, int k, int start) {
    // Cơ sở của đệ quy: Nếu N bằng 0, có một cách duy nhất là không sử dụng số nào cả
    if (N == 0 && k >= 0) return 1;
    // Nếu không còn số lập phương nào có thể sử dụng, trả về 0
    if (k == 0) return 0;
    // Nếu N nhỏ hơn 0, không có cách nào hợp lệ
    if (N < 0) return 0;

    int ways = 0;
    for (int i = start; i * i * i <= N; ++i) {
        // Đệ quy với N giảm đi lập phương của i và giảm số lập phương tối đa có thể sử dụng
        ways += findWays(N - i * i * i, k - 1, i);
    }
    return ways;
}

int main() {
    int N;
    cin >> N;
    // Gọi hàm đệ quy với số lập phương tối đa là 5 và bắt đầu từ số 1
    cout << findWays(N, 5, 1) << endl;
    return 0;
}


/*
Bài 2. LP Biểu diễn lập phương
Cho một số nguyên N. Tìm ra số lượng cách để biểu diễn số N thành tổng của tối đa 5 số lập phương.
Input: 1 dòng chứa số N, với (1 < N <= 12500).
Output: In ra kết quả về số lượng cách.
Ví dụ:

Input

Output

64

2

Giải thích:

+ Cách 1: 64 = 27+ 27 + 8 + 1 +1
+ Cách 2: 64= 64+0 +0+0+ 0
*/