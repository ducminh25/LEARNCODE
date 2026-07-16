/**
 * Generator for Problem: Cap so (Number Pairs)
 * Author: Mon (Gemini)
 * Logic: b^2 - a^2 = prime <==> b = a+1 AND 2a+1 = prime.
 */

#include <bits/stdc++.h>
#include <sys/stat.h> // Thu vien de tao folder (Windows/Linux)
#include <sys/types.h>

using namespace std;

// --- CẤU HÌNH ---
const int NUM_TESTS = 20;
const int MAX_R = 200005; 
// Giới hạn max của 2a+1 là khoảng 400,000.
const int MAX_VAL = 2 * MAX_R + 7;

// --- SÀNG NGUYÊN TỐ (Độ chính xác tuyệt đối) ---
vector<bool> is_prime(MAX_VAL, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_VAL; j += i)
                is_prime[j] = false;
        }
    }
}

// --- HÀM GIẢI (SOLVER) ---
// Đếm số lượng a trong [L, R-1] sao cho 2a+1 là nguyên tố
long long solve(int L, int R) {
    long long cnt = 0;
    for (int a = L; a < R; ++a) { // Vì b = a+1 <= R nên a <= R-1
        if (is_prime[2 * a + 1]) {
            cnt++;
        }
    }
    return cnt;
}

// --- HÀM SINH SỐ NGẪU NHIÊN ---
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int min_val, int max_val) {
    return uniform_int_distribution<int>(min_val, max_val)(rng);
}

// --- TẠO FOLDER VÀ GHI FILE ---
void make_test(int id, int min_r, int max_r) {
    // 1. Tạo tên folder: test01, test02...
    string dir_name = "test" + (id < 10 ? "0" + to_string(id) : to_string(id));
    
    // Tạo directory (hoạt động trên cả Windows/Linux qua lenh he thong cho don gian)
    string cmd = "mkdir " + dir_name; 
    system(cmd.c_str());

    // 2. Sinh Input
    // R phải >= 2 để tồn tại ít nhất 1 cặp (1,2)
    int R = rand_int(max(2, min_r), max_r);
    // L phải < R. Để đa dạng test, ta random L trong khoảng [1, R-1]
    int L = rand_int(1, R - 1);

    // Edge case cho vài test đầu: L rất gần R
    if (id % 5 == 0) L = max(1, R - rand_int(1, 10)); 
    // Edge case: L nhỏ, R lớn
    if (id % 5 == 1) L = rand_int(1, 10);

    string inp_path = dir_name + "/CAU1.INP";
    ofstream inp(inp_path);
    inp << L << " " << R;
    inp.close();

    // 3. Sinh Output
    long long ans = solve(L, R);
    string out_path = dir_name + "/CAU1.OUT";
    ofstream out(out_path);
    out << ans;
    out.close();

    cout << "Generated " << dir_name << ": L=" << L << ", R=" << R << " -> Ans=" << ans << endl;
}

int main() {
    // Chuẩn bị dữ liệu
    sieve();

    cout << "Bat dau sinh test..." << endl;

    // Subtask 1: 80% số điểm có R <= 500 (16 test đầu)
    // Chia nhỏ để có cả test rất nhỏ và test chạm mốc 500
    for (int i = 1; i <= 16; ++i) {
        if (i <= 5) make_test(i, 2, 50);      // Test cực nhỏ
        else if (i <= 10) make_test(i, 50, 200); // Test trung bình nhỏ
        else make_test(i, 200, 500);          // Test chạm biên subtask 1
    }

    // Subtask 2: 20% còn lại không ràng buộc thêm (R <= 2.10^5) (4 test cuối)
    for (int i = 17; i <= 20; ++i) {
        if (i == 17) make_test(i, 501, 5000);
        else make_test(i, 100000, 200000); // Test max cấu hình
    }

    cout << "Da hoan thanh sinh 20 test." << endl;
    return 0;
}