#include <bits/stdc++.h>
using namespace std;

// Định nghĩa lớp HS
struct HS {
    long long x, y;
};

// Định nghĩa hàm so sánh cho priority_queue
struct compare {
    bool operator()(const HS& a, const HS& b) {
        return a.x < b.x;
    }
};

int main() {
    // Khởi tạo hai hàng đợi ưu tiên
    priority_queue<HS, vector<HS>, compare> pqA;
    priority_queue<HS, vector<HS>, compare> pqB;

    // Khởi tạo tổng chỉ số thông minh của hai đội
    long long sumA = 0, sumB = 0;

    // Đọc số học sinh
    int n;
    cin >> n;

    // Xử lý từng học sinh
    for (int i = 1; i <= n; i++) {
        // Đọc thông tin học sinh
        long long x, y;
        cin >> x >> y;
        HS newHS = {x, y};

        // Thêm học sinh mới vào đội B
        pqB.push(newHS);
        sumB += y;

        // Cân bằng hai đội
        while (pqA.size() < i / 2) {
            HS top = pqB.top();
            pqB.pop();
            pqA.push(top);
            sumA += top.y;
            sumB -= top.y;
        }
        while (pqA.size() > i / 2) {
            HS top = pqA.top();
            pqA.pop();
            pqB.push(top);
            sumA -= top.y;
            sumB += top.y;
        }

        // In ra độ chênh lệch tổng chỉ số thông minh
        cout << abs(sumA - sumB) << '\n';
    }

    return 0;
}