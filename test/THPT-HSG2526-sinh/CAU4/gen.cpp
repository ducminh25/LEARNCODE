#include <bits/stdc++.h>
#include <direct.h> // Thư viện cho Windows để tạo folder (_mkdir)

using namespace std;

// Cấu hình tên bài
const string TASK_NAME = "CAU4";
const int MOD = 1e9 + 7;

// Hàm sinh số ngẫu nhiên trong đoạn [l, r]
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
    return l + rng() % (r - l + 1);
}

// ---------------------------------------------------------
// PHẦN GIẢI BÀI TOÁN (SOLVER) - Đảm bảo chính xác tuyệt đối
// ---------------------------------------------------------
// Input: N, K, mảng A
// Output: Số cách đi modulo 10^9 + 7
long long solve_logic(int n, int k, const vector<int>& a) {
    // 1. Tìm tập hợp tất cả các bước nhảy có thể (các ước số)
    set<int> steps;
    for (int val : a) {
        for (int i = 1; i * i <= val; ++i) {
            if (val % i == 0) {
                steps.insert(i);
                steps.insert(val / i);
            }
        }
    }

    // 2. Quy hoạch động
    // dp[i] là số cách đi từ đá 1 đến đá i
    // dp[1] = 1 (đứng tại chỗ là 1 cách để bắt đầu)
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 1; i < n; ++i) {
        if (dp[i] == 0) continue; // Nếu không đến được đá i thì bỏ qua
        
        for (int step : steps) {
            if (i + step <= n) {
                dp[i + step] = (dp[i + step] + dp[i]) % MOD;
            }
        }
    }

    return dp[n];
}

// ---------------------------------------------------------
// PHẦN SINH INPUT (GENERATOR)
// ---------------------------------------------------------
void generate_test(int test_id) {
    // Tạo tên folder: test01, test02, ...
    string id_str = (test_id < 10 ? "0" : "") + to_string(test_id);
    string folder_name = "test" + id_str;
    
    // Tạo folder trên Windows
    _mkdir(folder_name.c_str());

    string inp_file = folder_name + "/" + TASK_NAME + ".INP";
    string out_file = folder_name + "/" + TASK_NAME + ".OUT";

    ofstream inp(inp_file);
    
    int n, k;
    vector<int> a;

    // --- CẤU HÌNH SUBTASK ---
    if (test_id <= 8) { 
        // Subtask 1 (40%): N <= 20, K = 1, a1 = 6
        k = 1;
        a.push_back(6);
        
        // Các trường hợp biên cho subtask 1
        if (test_id == 1) n = 2; // Nhỏ nhất
        else if (test_id == 2) n = 3;
        else if (test_id == 8) n = 20; // Lớn nhất của subtask
        else n = rand(4, 19);
        
    } else {
        // Subtask 2 (60%): N <= 10^5, K <= 10, ai <= 10^6
        
        // Test 9-10: N nhỏ vừa, K random
        if (test_id <= 10) {
            n = rand(50, 200);
            k = rand(1, 10);
            for(int i=0; i<k; ++i) a.push_back(rand(1, 100));
        }
        // Test 11-12: N lớn, K=1, a[i] là số nguyên tố (ít ước - ít bước nhảy)
        else if (test_id <= 12) {
            n = rand(1000, 50000);
            k = 1;
            a.push_back(999983); // Số nguyên tố lớn
        }
        // Test 13: Trường hợp a_i = 1 (chỉ nhảy được 1 bước) - tạo chuỗi dài
        else if (test_id == 13) {
            n = 10000; 
            k = 5;
            for(int i=0; i<k; ++i) a.push_back(1);
        }
        // Test 14-15: N lớn, K max, a[i] là số có cực nhiều ước (nhiều bước nhảy)
        else if (test_id <= 15) {
            n = rand(50000, 80000);
            k = 10;
            // 720720 là số có rất nhiều ước
            for(int i=0; i<k; ++i) a.push_back(720720 - rand(0, 100)); 
        }
        // Test 16-19: Random mạnh tay gần giới hạn
        else if (test_id <= 19) {
            n = rand(80000, 99999);
            k = rand(5, 10);
            for(int i=0; i<k; ++i) a.push_back(rand(10000, 1000000));
        }
        // Test 20: Max ping mọi thông số
        else {
            n = 100000;
            k = 10;
            for(int i=0; i<k; ++i) a.push_back(1000000 - i);
        }
    }

    // Ghi Input
    inp << n << " " << k << endl;
    for (int i = 0; i < k; ++i) {
        inp << a[i] << (i == k - 1 ? "" : " ");
    }
    inp.close();

    // --- SINH OUTPUT ---
    // Gọi hàm giải (Solver) để tính kết quả chuẩn
    long long result = solve_logic(n, k, a);

    ofstream out(out_file);
    out << result;
    out.close();

    cout << "Generated " << folder_name << ": N=" << n << ", K=" << k << " -> Result=" << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Dang sinh 20 test case..." << endl;
    for (int i = 1; i <= 20; ++i) {
        generate_test(i);
    }
    cout << "Hoan tat!" << endl;
    return 0;
}