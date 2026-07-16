#include <bits/stdc++.h>
#include <sys/stat.h> // Thu vien de tao folder (Windows/Linux)
#include <windows.h>  // Thu vien cho Windows (neu can)

using namespace std;

// --- CẤU HÌNH RANDOM ---
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randLL(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

// --- THUẬT TOÁN GIẢI (SOLVER) ---
// Độ phức tạp: O(N * log(Answer)) - Đảm bảo chính xác tuyệt đối
long long solve(int n, long long m, const vector<long long>& a) {
    long long low = 1, high = 3000000000LL; // Max A_i + Max M
    long long ans = -1;

    // Tìm min hiện tại của mảng để tối ưu cận dưới
    long long current_min = a[0];
    for(long long x : a) current_min = min(current_min, x);
    low = current_min;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long needed = 0;
        bool possible = true;
        
        for (long long x : a) {
            if (x < mid) {
                needed += (mid - x);
                // Cắt tỉa sớm nếu vượt quá m để tránh tràn số (dù logic LL đủ chứa)
                if (needed > m) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// --- HÀM TẠO TEST ---
void make_test(int test_id) {
    // 1. Tạo tên thư mục testXX
    string dir_name = "test";
    if (test_id < 10) dir_name += "0";
    dir_name += to_string(test_id);

    // Lệnh tạo folder (Hỗ trợ Windows)
    string cmd = "mkdir " + dir_name;
    system(cmd.c_str());

    // 2. Thiết lập ràng buộc theo Subtask
    int n;
    long long m;
    long long min_val = 1, max_val = 1000000000LL;

    // Subtask 1 (20%): n <= 10^5, m <= 1 (Test 01-04)
    if (test_id <= 4) {
        n = randLL(1, 100000);
        m = randLL(0, 1);
        if (test_id == 1) { n = 1; m = 0; } // Biên n min
        if (test_id == 2) { n = 100000; m = 1; } // Biên n max
    }
    // Subtask 2 (20%): n = 2, m <= 100 (Test 05-08)
    else if (test_id <= 8) {
        n = 2;
        m = randLL(0, 100);
        if (test_id == 5) m = 0;
        if (test_id == 8) m = 100;
        max_val = 1000000000LL; // Giá trị phần tử vẫn có thể lớn
    }
    // Subtask 3 (30%): n <= 1000, m <= 100 (Test 09-14)
    else if (test_id <= 14) {
        n = randLL(1, 1000);
        m = randLL(0, 100);
        if (test_id == 14) { n = 1000; m = 100; }
    }
    // Subtask 4 (30%): n <= 2*10^5, m <= 10^9 (Test 15-20)
    else {
        n = randLL(1000, 200000);
        m = randLL(100, 1000000000LL);
        if (test_id == 20) { // Max constraints
            n = 200000;
            m = 1000000000LL;
        }
    }

    // Sinh mảng a
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = randLL(min_val, max_val);
    }

    // Trường hợp biên đặc biệt: Tất cả phần tử bằng nhau (Test 18)
    if (test_id == 18) {
        long long val = randLL(1, max_val);
        for(int i=0; i<n; i++) a[i] = val;
    }

    // 3. Ghi file Input
    string inp_file = dir_name + "/CAU3.INP";
    ofstream out_inp(inp_file);
    out_inp << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        out_inp << a[i] << (i == n - 1 ? "" : " ");
    }
    out_inp.close();

    // 4. Giải và ghi file Output
    long long result = solve(n, m, a);
    string out_file = dir_name + "/CAU3.OUT";
    ofstream out_out(out_file);
    out_out << result;
    out_out.close();

    cout << "Generated " << dir_name << " | N=" << n << " M=" << m << " | Ans=" << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // Xử lý tạo folder trên Windows tránh lỗi
    system("cls"); 
    cout << "Dang sinh 20 test..." << endl;

    for (int i = 1; i <= 20; i++) {
        make_test(i);
    }

    cout << "Da sinh xong 20 test!" << endl;
    return 0;
}