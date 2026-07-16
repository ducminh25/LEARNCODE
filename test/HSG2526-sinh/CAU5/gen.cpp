/**
 * Generator Fix: Bo hoa
 * Yeu cau: K <= N tuyet doi. N*K <= 5.10^6.
 * Input: CAU5.INP, Output: CAU5.OUT
 */

#include <bits/stdc++.h>
#include <sys/stat.h> 

using namespace std;

// --- CẤU HÌNH RANDOM ---
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randNum(long long l, long long r) {
    if (l > r) return l; // An toan
    return uniform_int_distribution<long long>(l, r)(rng);
}

// --- SOLVER (O(NK log N) - Validated) ---
const long long INF = 1e18;

long long solve(int n, int k, const vector<int>& a) {
    // prev_dp[i]: Max tong do dep khi chia i bong hoa thanh (grp-1) bo
    vector<long long> prev_dp(n + 1, -INF);
    vector<long long> dp(n + 1, -INF);

    // Base case: 0 bo hoa thi tai vi tri 0 co gia tri 0 (de lam diem tua cho bo dau tien)
    prev_dp[0] = 0; 

    struct Element {
        int min_val;      // Min cua doan hien tai
        long long max_g;  // Max DP cua tang truoc tuong ung voi doan nay
    };

    for (int grp = 1; grp <= k; ++grp) {
        fill(dp.begin(), dp.end(), -INF);
        
        vector<Element> st;
        multiset<long long> candidates;

        for (int i = 1; i <= n; ++i) {
            int val = a[i];
            long long current_best_prev = prev_dp[i-1]; // p = i-1

            // Monotonic Stack: Duy tri tinh tang dan cua min_val tu duoi len (trong stack la giam dan)
            while (!st.empty() && st.back().min_val >= val) {
                // Merge khoang: lay max DP cua khoang bi loai bo
                current_best_prev = max(current_best_prev, st.back().max_g);
                
                // Xoa candidate cu vi min_val da thay doi (nho hon)
                long long old_score = st.back().min_val + st.back().max_g;
                auto it = candidates.find(old_score);
                if (it != candidates.end()) candidates.erase(it);
                
                st.pop_back();
            }

            // Them phan tu moi vao stack
            st.push_back({val, current_best_prev});
            
            // Candidate moi = min_val hien tai + max DP cua diem cat phu hop nhat
            if (current_best_prev > -INF) {
                candidates.insert(val + current_best_prev);
            }

            // Lay gia tri tot nhat hien tai
            if (!candidates.empty()) {
                dp[i] = *candidates.rbegin();
            }
        }
        // Chuan bi cho vong lap sau
        prev_dp = dp;
    }

    return prev_dp[n];
}

// --- GEN TEST ---
void make_test(int id, int n_min, int n_max, int k_type, long long val_limit) {
    // k_type: 
    // 1 -> Subtask 1 (K <= 2)
    // 2 -> Subtask 2 (N, K <= 500)
    // 3 -> Subtask 3 (N*K <= 5.10^6)

    // 1. Tao Folder
    string dir_name = "test" + (id < 10 ? string("0") : string("")) + to_string(id);
    string cmd = "mkdir " + dir_name; 
    system(cmd.c_str()); // Lenh Windows/Linux deu on voi mkdir co ban

    // 2. Sinh N truoc
    int n = randNum(n_min, n_max);
    
    // 3. Tinh K dua tren N de dam bao K <= N
    int k;
    if (k_type == 1) {
        // K <= 2 va K <= N
        k = randNum(1, min(n, 2));
    } else if (k_type == 2) {
        // K tuy y nhung K <= N
        k = randNum(1, n);
    } else {
        // N*K <= 5.10^6
        long long max_k_allowed = 5000000LL / n;
        if (max_k_allowed < 1) max_k_allowed = 1; 
        // Rang buoc cung: K <= N
        k = randNum(1, min((long long)n, max_k_allowed));
    }

    // Assert de dam bao logic khong bao gio sai
    assert(k <= n);
    assert(k >= 1);
    if (k_type == 3) assert((long long)n * k <= 5000000LL);

    // Hardcode test cuoi cung de stress test
    if (id == 20) {
        n = 100000;
        k = 50; // 100000 * 50 = 5.000.000 (Max subtask)
    }

    // Ghi Input
    string file_inp = dir_name + "/CAU5.INP";
    ofstream out_inp(file_inp);
    out_inp << n << " " << k << "\n";
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = randNum(0, val_limit);
        out_inp << a[i] << (i == n ? "" : " ");
    }
    out_inp.close();

    // 4. Sinh Output
    string file_out = dir_name + "/CAU5.OUT";
    ofstream out_out(file_out);
    
    long long ans = solve(n, k, a);
    out_out << ans;
    out_out.close();

    // Log nhe
    // cout << "Gen Test " << id << ": N=" << n << ", K=" << k << " [OK]" << endl;
}

int main() {
    // --- PHAN BO TEST ---
    // Subtask 1 (30%): K <= 2. Test 01-06
    for(int i=1; i<=6; ++i) {
        // N tang dan de test phu
        int n_min = (i==1) ? 5 : 10000; 
        make_test(i, n_min, 100000, 1, 1000000000);
    }

    // Subtask 2 (40%): N <= 500. Test 07-14
    for(int i=7; i<=14; ++i) {
        make_test(i, 10, 500, 2, 1000000000);
    }

    // Subtask 3 (30%): N*K <= 5.10^6. Test 15-20
    for(int i=15; i<=20; ++i) {
        make_test(i, 50000, 100000, 3, 1000000000);
    }

    cout << "Da sinh xong 20 test chuan xac." << endl;
    return 0;
}