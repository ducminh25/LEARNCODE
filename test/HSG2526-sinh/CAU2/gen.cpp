#include <bits/stdc++.h>
#include <direct.h> // Dùng cho Windows để tạo folder (_mkdir)
// Nếu dùng Linux/Mac đổi thành <sys/stat.h> và dùng mkdir(path, 0777)

using namespace std;

// ==========================================
// CẤU HÌNH RANDOM
// ==========================================
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randInt(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

// ==========================================
// GIẢI THUẬT CHUẨN (REFERENCE SOLUTION)
// ==========================================
// Hàm này tính toán kết quả chính xác cho bộ test vừa sinh ra
long long solve(int n, int k, const vector<int>& h) {
    vector<int> preMax(n + 2, 0), sufMax(n + 2, 0);
    vector<long long> preSum(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        preMax[i] = max(preMax[i - 1], h[i]);
        preSum[i] = preSum[i - 1] + h[i];
    }
    for (int i = n; i >= 1; i--) {
        sufMax[i] = max(sufMax[i + 1], h[i]);
    }

    long long sumAll = preSum[n];
    long long ans = 4e18; // Init infinity

    if (k == 0) {
        long long L = preMax[n];
        ans = n * L - sumAll;
    } else { // k == 1 hoặc k == -1
        for (int i = 0; i <= n; i++) {
            long long H1 = 0;
            if (i > 0) H1 = preMax[i];

            // Nếu k = -1, bắt buộc xuất phát ở h[1], tức H1 phải bằng h[1]
            // Nếu H1 hiện tại (preMax[i]) > h[1] thì điểm cắt này vô hiệu.
            if (k == -1 && i > 0 && H1 > h[1]) continue;
            if (k == -1) H1 = h[1]; // Gán cứng theo đề

            long long RawH2 = (i < n) ? sufMax[i + 1] : 0;

            // Ràng buộc quan trọng: KHÔNG ĐƯỢC HẠ ĐỘ CAO
            long long H2 = max(H1, RawH2);

            long long cost1 = 0, cost2 = 0;
            if (i > 0) cost1 = i * H1 - preSum[i];
            if (i < n) {
                long long sumPart2 = sumAll - preSum[i];
                cost2 = (long long)(n - i) * H2 - sumPart2;
            }
            ans = min(ans, cost1 + cost2);
        }
    }
    return ans;
}

// ==========================================
// TRÌNH SINH TEST (GENERATOR)
// ==========================================
int main() {
    // Tạo 20 test
    for (int iTest = 1; iTest <= 20; iTest++) {
        // 1. Tạo tên thư mục test01, test02...
        string dirName = "test" + string(iTest < 10 ? "0" : "") + to_string(iTest);
        _mkdir(dirName.c_str()); // Lệnh tạo folder trên Windows

        // 2. Thiết lập thông số N và K theo Subtask
        int n, k;

        if (iTest <= 8) {
            // 40% số điểm: k = 0, N <= 10^6
            k = 0;
            if (iTest <= 2)
                n = randInt(10, 100); // Test nhỏ
            else
                n = randInt(1e5, 1e6); // Test max
        } else if (iTest <= 14) {
            // 30% tiếp theo: k = -1, N <= 10^6
            k = -1;
            if (iTest <= 10)
                n = randInt(10, 1000);
            else
                n = randInt(1e5, 1e6);
        } else {
            // 30% còn lại: k = 1, N <= 10^4 (Theo ảnh)
            k = 1;
            n = randInt(100, 10000); // Max 10^4
        }

        // 3. Sinh mảng H
        vector<int> h(n + 1);
        for (int j = 1; j <= n; j++) {
            // Random độ cao từ 0 đến 10^9
            // Tạo vài test có độ cao nhỏ để dễ debug
            if (iTest % 5 == 0)
                h[j] = randInt(1, 100);
            else
                h[j] = randInt(0, 1000000000);
        }

        // --- Ghi file INPUT ---
        string inpPath = dirName + "/CAU2.INP";
        ofstream inp(inpPath);
        inp << n << " " << k << "\n";
        for (int j = 1; j <= n; j++) {
            inp << h[j] << (j == n ? "" : " ");
        }
        inp.close();

        // --- Giải và ghi file OUTPUT ---
        long long result = solve(n, k, h);

        string outPath = dirName + "/CAU2.OUT";
        ofstream out(outPath);
        out << result;
        out.close();

        cout << "Generated " << dirName << ": N=" << n << ", K=" << k << " -> OK." << endl;
    }

    cout << "Hoan thanh sinh 20 test!" << endl;
    return 0;
}