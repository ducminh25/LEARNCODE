#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randInt(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

// ==========================================
// 1. LOGIC TỐI ƯU (Cần kiểm chứng)
// ==========================================
long long solveOptimized(int n, int k, const vector<int>& h) {
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
    } 
    else { // k == 1 hoặc k == -1
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
// 2. LOGIC VÉT CẠN (Brute Force - Chắc chắn đúng)
// ==========================================
long long solveBruteForce(int n, int k, const vector<int>& h) {
    long long ans = 4e18;
    long long sumAll = 0;
    for(int x : h) sumAll += x;

    if (k == 0) {
        int maxH = 0;
        for(int x : h) maxH = max(maxH, x);
        ans = (long long)n * maxH - sumAll;
    } else {
        // Duyệt mọi điểm cắt i từ 0 đến n
        for (int i = 0; i <= n; ++i) {
            // Tìm max đoạn 1 thủ công
            long long H1 = 0;
            bool ok = true;
            if (i > 0) {
                for (int j = 1; j <= i; ++j) H1 = max(H1, (long long)h[j]);
            }
            
            if (k == -1) {
                // Nếu k=-1, bắt buộc H1 == h[1]
                if (i > 0) {
                     if (H1 > h[1]) ok = false; // Max đoạn đầu > h[1] => Vi phạm
                     else H1 = h[1];
                } else {
                    H1 = h[1]; // i=0, vẫn tính xuất phát là h[1]
                }
            }

            if (!ok) continue;

            // Tìm max đoạn 2 thủ công
            long long RawH2 = 0;
            if (i < n) {
                for (int j = i + 1; j <= n; ++j) RawH2 = max(RawH2, (long long)h[j]);
            }

            // Ràng buộc không hạ độ cao
            long long H2 = max(H1, RawH2);

            // Tính phí thủ công
            long long currentCost = 0;
            // Phí đoạn 1
            for (int j = 1; j <= i; ++j) currentCost += (H1 - h[j]);
            // Phí đoạn 2
            for (int j = i + 1; j <= n; ++j) currentCost += (H2 - h[j]);

            ans = min(ans, currentCost);
        }
    }
    return ans;
}

// ==========================================
// 3. TRÌNH KIỂM TRA (Checker)
// ==========================================
int main() {
    int testCount = 0;
    while (true) {
        testCount++;
        // Sinh test ngẫu nhiên nhỏ để dễ vét cạn
        int n = randInt(1, 50); 
        int k_type = randInt(0, 2); // 0: k=0; 1: k=1; 2: k=-1
        int k;
        if (k_type == 0) k = 0;
        else if (k_type == 1) k = 1;
        else k = -1;

        vector<int> h(n + 1); // h[0] dummy
        // Test trường hợp biên (h toàn 0, h tăng dần, h giảm dần...)
        for (int i = 1; i <= n; i++) h[i] = randInt(0, 100);

        long long outOpt = solveOptimized(n, k, h);
        long long outBrute = solveBruteForce(n, k, h);

        if (outOpt != outBrute) {
            cout << "Found WRONG ANSWER!" << endl;
            cout << "Input: N=" << n << " K=" << k << endl;
            cout << "H: ";
            for(int i=1; i<=n; i++) cout << h[i] << " ";
            cout << endl;
            cout << "Optimized: " << outOpt << endl;
            cout << "BruteForce: " << outBrute << endl;
            return 1; // Dừng ngay
        }

        if (testCount % 1000 == 0) {
            cout << "Passed " << testCount << " tests..." << endl;
        }
    }
    return 0;
}