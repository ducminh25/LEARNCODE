/**
 * Stress Test Verification for Flower Bunch Problem
 * Muc dich: So sanh ket qua giua Thuat toan Toi uu va Thuat toan Trau bo
 */

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// ==========================================
// 1. THUẬT TOÁN CHUẨN (OPTIMIZED SOLVER)
// Copy y nguyen tu code sinh test
// ==========================================
long long solve_optimized(int n, int k, const vector<int>& a) {
    vector<long long> prev_dp(n + 1, -INF);
    vector<long long> dp(n + 1, -INF);
    prev_dp[0] = 0; 
    
    struct Element { int min_val; long long max_g; };

    for (int grp = 1; grp <= k; ++grp) {
        fill(dp.begin(), dp.end(), -INF);
        vector<Element> st;
        multiset<long long> candidates;

        for (int i = 1; i <= n; ++i) {
            int val = a[i];
            long long current_best_prev = prev_dp[i-1];

            while (!st.empty() && st.back().min_val >= val) {
                current_best_prev = max(current_best_prev, st.back().max_g);
                long long old_score = st.back().min_val + st.back().max_g;
                auto it = candidates.find(old_score);
                if (it != candidates.end()) candidates.erase(it);
                st.pop_back();
            }
            st.push_back({val, current_best_prev});
            candidates.insert(val + current_best_prev);
            if (!candidates.empty()) dp[i] = *candidates.rbegin();
        }
        prev_dp = dp;
    }
    return prev_dp[n];
}

// ==========================================
// 2. THUẬT TOÁN TRÂU BÒ (NAIVE DP)
// Do phuc tap: O(K * N^2) -> Chi chay duoc N nho
// ==========================================
long long solve_brute(int n, int k, const vector<int>& a) {
    // dp[i][j]: chia i bong hoa dau tien thanh j bo
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -INF));
    
    dp[0][0] = 0;

    for (int j = 1; j <= k; ++j) { // Duyet so bo
        for (int i = 1; i <= n; ++i) { // Duyet vi tri ket thuc
            int current_min = 2e9; // Vo cung lon
            // Duyet nguoc ve de tim diem cat p (p < i)
            // Bo cuoi cung la doan [p+1...i]
            for (int p = i - 1; p >= 0; --p) {
                current_min = min(current_min, a[p+1]); // Min cua doan [p+1...i]
                if (dp[p][j-1] > -INF) {
                    dp[i][j] = max(dp[i][j], dp[p][j-1] + current_min);
                }
            }
        }
    }
    return dp[n][k];
}

// ==========================================
// 3. TRÌNH KIỂM TRA (MAIN)
// ==========================================
int main() {
    srand(time(0));
    int TEST_COUNT = 1000; // So luong test ngau nhien muon kiem tra
    cout << "Dang chay Stress Test..." << endl;

    for (int t = 1; t <= TEST_COUNT; ++t) {
        // Sinh input ngau nhien nho
        int n = rand() % 100 + 1; // N tu 1 den 100
        int k = rand() % n + 1;   // K tu 1 den N
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) a[i] = rand() % 1000;

        // Chay 2 thuat toan
        long long ans_opt = solve_optimized(n, k, a);
        long long ans_brute = solve_brute(n, k, a);

        // So sanh
        if (ans_opt != ans_brute) {
            cout << "PHAT HIEN LOI!" << endl;
            cout << "Input: N=" << n << ", K=" << k << endl;
            cout << "Mang A: ";
            for(int i=1; i<=n; ++i) cout << a[i] << " ";
            cout << endl;
            cout << "Output Chuan: " << ans_opt << endl;
            cout << "Output Trau:  " << ans_brute << endl;
            return 1; // Dung ngay lap tuc
        }

        if (t % 100 == 0) cout << "Da check xong " << t << " test..." << endl;
    }

    cout << "CHINH XAC 100%! Logic sinh test an toan." << endl;
    return 0;
}