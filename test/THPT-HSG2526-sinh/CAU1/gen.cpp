/**
 * Generator cho bài: Số đặc biệt
 * Output: 20 folder test01 -> test20
 * Logic chuẩn: O(1) mathematical formula
 * Author: Gemini
 */

#include <bits/stdc++.h>
#include <sys/stat.h> // Dùng cho mkdir (Linux/Windows MinGW)
#include <direct.h>   // Dùng cho _mkdir (Windows MSVC) - Nếu lỗi, xem note bên dưới

using namespace std;

// Cấu hình số lượng test
const int NUM_TESTS = 20;

// Hàm sinh số ngẫu nhiên trong đoạn [L, R]
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long get_random(long long min_val, long long max_val) {
    return uniform_int_distribution<long long>(min_val, max_val)(rng);
}

// Hàm tính số lượng số đặc biệt trong đoạn [1, n]
// Logic: K^2 - 1 chia hết cho 5 <=> K % 5 == 1 hoặc K % 5 == 4
long long countSpecial(long long n) {
    if (n <= 0) return 0;
    long long groups = n / 5;
    long long rem = n % 5;
    long long ans = groups * 2;
    
    // Xử lý phần dư
    for (int i = 1; i <= rem; ++i) {
        if (i % 5 == 1 || i % 5 == 4) ans++;
    }
    return ans;
}

// Hàm giải quyết bài toán (Solver chuẩn)
long long solve(long long L, long long R) {
    return countSpecial(R) - countSpecial(L - 1);
}

void createTest(int testIdx, long long L, long long R) {
    // 1. Tạo tên thư mục (VD: test01, test02...)
    string dirName = "test" + string(testIdx < 10 ? "0" : "") + to_string(testIdx);
    
    // Lệnh tạo thư mục (Windows dùng mkdir, Linux dùng mkdir -p)
    string cmd = "mkdir " + dirName; 
    system(cmd.c_str());

    // 2. Ghi file Input
    string inpFile = dirName + "/CAU1.INP";
    ofstream fo(inpFile);
    fo << L << " " << R;
    fo.close();

    // 3. Ghi file Output (Dùng logic chuẩn)
    string outFile = dirName + "/CAU1.OUT";
    ofstream fa(outFile);
    fa << solve(L, R);
    fa.close();

    cout << "Gen " << dirName << ": [" << L << ", " << R << "] -> Done." << endl;
}

int main() {
    // Tắt đồng bộ để chạy nhanh hơn (không quan trọng lắm với generator)
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    for (int i = 1; i <= NUM_TESTS; ++i) {
        long long L, R;

        // --- PHÂN PHỐI TEST CASE ---
        
        // Test 01: Test ví dụ trong đề
        if (i == 1) {
            L = 2; R = 8;
        }
        // Test 02 - 16: Subtask 1 (80% số điểm) -> R <= 10^6
        else if (i <= 16) {
            // Chia nhỏ để cover các trường hợp nhỏ và biên 10^6
            long long limit = 1000000;
            if (i <= 5) limit = 100; // Test rất nhỏ
            
            L = get_random(2, limit - 10);
            R = get_random(L, limit);
            
            // Một vài test L = R
            if (i == 4) R = L; 
            // Test biên max subtask 1
            if (i == 16) { L = 2; R = 1000000; } 
        }
        // Test 17 - 20: Subtask 2 (20% số điểm) -> R <= 10^18
        else {
            long long limit = 1e18;
            L = get_random(1e12, limit - 1000000); // L lớn hẳn
            R = get_random(L, limit);

            // Test biên cực đại
            if (i == 20) { L = 2; R = 1e18; }
            // Test L, R sát nhau ở giá trị lớn
            if (i == 19) { L = 1000000000000000000 - 5; R = 1e18; }
        }

        createTest(i, L, R);
    }

    cout << "Hoan tat sinh 20 test." << endl;
    return 0;
}