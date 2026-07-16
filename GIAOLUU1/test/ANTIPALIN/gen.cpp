#include <bits/stdc++.h>
#include <sys/stat.h> // Thư viện để tạo thư mục (Windows/Linux)
#include <direct.h>   // Dùng cho Windows (_mkdir)
using namespace std;

// ================= CẤU HÌNH BÀI TOÁN ================= //
const string PROBLEM_NAME = "ANTIPALIN";
const int TOTAL_TESTS = 50;

// Hàm tạo số ngẫu nhiên trong đoạn [min, max]
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// ================= CORE GIẢI BÀI (SOLVER) ================= //
// Dùng lại code chuẩn O(N) đã viết trước đó
inline bool isValid(int pos, char c, const string& current_s) {
    if (pos - 1 >= 0 && current_s[pos - 1] == c) return false;
    if (pos - 2 >= 0 && current_s[pos - 2] == c) return false;
    return true;
}

string solve(int n, int k, string s) {
    int pivot = -1;
    // Bước 1: Tìm Pivot
    for (int i = n - 1; i >= 0; --i) {
        for (char c = s[i] + 1; c < 'a' + k; ++c) {
            if (isValid(i, c, s)) {
                s[i] = c;
                pivot = i;
                goto BUILD_SUFFIX;
            }
        }
    }
    return "NO";

BUILD_SUFFIX:
    // Bước 2: Điền suffix nhỏ nhất
    for (int i = pivot + 1; i < n; ++i) {
        bool found = false;
        for (char c = 'a'; c < 'a' + k; ++c) {
            if (isValid(i, c, s)) {
                s[i] = c;
                found = true;
                break;
            }
        }
        if (!found) return "NO"; // Phòng hờ K=2
    }
    return s;
}

// ================= HÀM SINH INPUT HỢP LỆ ================= //
// Sinh chuỗi S độ dài n, k ký tự, đảm bảo không phải palindrome
string generateValidS(int n, int k) {
    string s = "";
    for (int i = 0; i < n; ++i) {
        vector<char> candidates;
        for (char c = 'a'; c < 'a' + k; ++c) {
            if (isValid(i, c, s)) {
                candidates.push_back(c);
            }
        }
        if (candidates.empty()) return ""; // Fallback (hiếm khi xảy ra với K>=3)
        // Random chọn 1 ký tự hợp lệ để tạo tính ngẫu nhiên cho đề
        s += candidates[randInt(0, candidates.size() - 1)];
    }
    return s;
}

// Hàm sinh S đặc biệt (gần giới hạn) để test trường hợp NO hoặc Backtrack sâu
string generateHardS(int n, int k) {
    // Tạo chuỗi dạng cba cba... (lớn nhất có thể)
    string s = "";
    // Đơn giản hóa: cố gắng điền ký tự lớn nhất có thể tại mọi vị trí
    for(int i=0; i<n; ++i) {
        for(char c = 'a' + k - 1; c >= 'a'; --c) {
            if(isValid(i, c, s)) {
                s += c;
                break;
            }
        }
    }
    // Lùi lại một chút để nó không phải là NO ngay lập tức (với test 49-50 thì giữ nguyên)
    return s;
}

// ================= MAIN GENERATOR ================= //
int main() {
    // Tạo thư mục gốc chứa test

    for (int i = 1; i <= TOTAL_TESTS; ++i) {
        // 1. Tạo thư mục con Test01, Test02...
        string dirName = "Test" + (i < 10 ? "0" + to_string(i) : to_string(i));
        _mkdir(dirName.c_str());

        // 2. Thiết lập thông số theo chiến lược
        int n, k;
        string s;

        if (i <= 25) { 
            // DỄ: N nhỏ, K to. Học sinh dễ kiếm điểm.
            n = randInt(5, 100);
            k = randInt(5, 15); // K đủ lớn để dễ điền
            s = generateValidS(n, k);
        } 
        else if (i <= 35) {
            // TRUNG BÌNH: N to, K to. Test time.
            n = 100000; // Max N
            k = 26;     // Max K
            s = generateValidS(n, k);
        }
        else if (i <= 48) {
            // KHÓ: N to, K nhỏ (K=3). Test logic backtracking.
            n = 100000; // Có thể random từ 50000 -> 100000
            k = 3;      // Nguy hiểm
            s = generateValidS(n, k);
        }
        else {
            // CỰC KHÓ / BIÊN: Trường hợp gần NO hoặc NO hẳn
            n = 100000;
            k = 3;
            s = generateHardS(n, k); // Chuỗi lớn nhất
            // Nếu là test 49 thì giảm nhẹ 1 chút để có đáp án
            if (i == 49) {
                // Sửa vài ký tự cuối để đảm bảo có nghiệm
                s = s.substr(0, n - 5) + generateValidS(5, k); 
            }
        }

        // 3. Ghi file Input
        string inpFile = dirName + "/" + PROBLEM_NAME + ".INP";
        ofstream outInp(inpFile);
        outInp << n << " " << k << "\n" << s;
        outInp.close();

        // 4. Ghi file Output (Chạy giải thuật)
        string outFile = dirName + "/" + PROBLEM_NAME + ".OUT";
        ofstream outOut(outFile);
        string result = solve(n, k, s);
        outOut << result;
        outOut.close();

        cout << "Generated Test " << i << " | N=" << n << " K=" << k << endl;
    }

    cout << "\n=== DONE 50 TESTS SUCCESSFULLY ===" << endl;
    return 0;
}