/**
 * Generator for Problem: Xau ki tu (String)
 * Author: Mon's Assistant
 * Language: C++14
 * Strategy: Strict constraints adherence, rigorous solver logic.
 */

#include <bits/stdc++.h>
#include <sys/stat.h> // For mkdir (works on Windows/Linux with modification)
#include <windows.h>  // For CreateDirectory on Windows

using namespace std;

// --- CẤU HÌNH ---
const int NUM_TESTS = 20;
const string FOLDER_PREFIX = "test";
const string PROBLEM_NAME = "CAU2";

// Random engine chuẩn xác cao
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long randInt(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rng);
}

// --- LOGIC GIẢI (SOLVER) ---
// Hàm này đảm bảo tính đúng đắn của Output
int solve(string s) {
    int max_len = 0;
    int current_len = 0;
    bool found_valid = false; // Kiểm tra xem có ký tự nào thỏa mãn không

    for (char c : s) {
        if (c == 'A' || c == 'N' || c == 'H') {
            current_len = 0;
        } else {
            current_len++;
            if (current_len > max_len) max_len = current_len;
            found_valid = true;
        }
    }

    if (!found_valid) return -1;
    return max_len;
}

// --- HÀM HỖ TRỢ SINH ---

// Tập ký tự hợp lệ (Không chứa A, N, H)
const string VALID_CHARS = "BCDEFGIJKLMOPQRSTUVWXYZ"; // 23 chars
// Tập ký tự đặc biệt
const string BAN_CHARS = "ANH";
// Tất cả ký tự in hoa
const string ALL_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Sinh chuỗi chỉ toàn ký tự hợp lệ
string genValidString(int len) {
    string res = "";
    for (int i = 0; i < len; ++i) {
        res += VALID_CHARS[randInt(0, VALID_CHARS.size() - 1)];
    }
    return res;
}

// Sinh chuỗi ngẫu nhiên hoàn toàn
string genRandomString(int len) {
    string res = "";
    for (int i = 0; i < len; ++i) {
        res += ALL_CHARS[randInt(0, ALL_CHARS.size() - 1)];
    }
    return res;
}

// Sinh chuỗi chỉ toàn A, N, H (để test output -1)
string genFailString(int len) {
    string res = "";
    for (int i = 0; i < len; ++i) {
        res += BAN_CHARS[randInt(0, BAN_CHARS.size() - 1)];
    }
    return res;
}

// --- MAIN GENERATOR ---

void makeTest(int testID) {
    // 1. Tạo folder
    string dirName = FOLDER_PREFIX + (testID < 10 ? "0" : "") + to_string(testID);
    CreateDirectory(dirName.c_str(), NULL); // Windows specific

    string inpFile = dirName + "/" + PROBLEM_NAME + ".INP";
    string outFile = dirName + "/" + PROBLEM_NAME + ".OUT";

    ofstream inp(inpFile);
    ofstream out(outFile);

    // Số lượng test case trong 1 file (T <= 10)
    int T = randInt(5, 10);
    inp << T << "\n";

    for (int t = 0; t < T; ++t) {
        string S;
        int len;

        // PHÂN LOẠI SUBTASK
        if (testID <= 6) { 
            // Subtask 1 (30%): Có 1 'A', ko 'N', ko 'H'. Len <= 10^5
            len = randInt(1, 100000);
            if (testID <= 2) len = randInt(1, 100); // Vài test nhỏ
            
            S = genValidString(len);
            // Chèn 1 ký tự 'A'
            int pos = randInt(0, len - 1);
            S[pos] = 'A';

        } else if (testID <= 12) {
            // Subtask 2 (30%): 1 'A', 1 'H', ko 'N'. Len <= 100
            len = randInt(5, 100); // Subtask yêu cầu len <= 100 (10^2)
            S = genValidString(len);
            
            // Chèn A và H tại 2 vị trí khác nhau
            int posA = randInt(0, len - 1);
            int posH = randInt(0, len - 1);
            while (posH == posA) posH = randInt(0, len - 1);
            
            S[posA] = 'A';
            S[posH] = 'H';

        } else {
            // Subtask 3 (40%): Không ràng buộc. Len <= 10^5
            len = randInt(100, 100000);
            if (testID == 20) len = 100000; // Test max load
            
            if (testID == 19 && t == 0) {
                // Testcase đặc biệt: Toàn bộ là ký tự cấm (Output -1)
                S = genFailString(len);
            } else {
                S = genRandomString(len);
            }
        }

        // Ghi Input
        inp << S << "\n";

        // Tính và ghi Output ngay lập tức
        out << solve(S) << "\n";
    }

    inp.close();
    out.close();
    cout << "Generated " << dirName << endl;
}

int main() {
    // Tăng tốc I/O không cần thiết cho generator nhưng quen tay thì để
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 1; i <= NUM_TESTS; ++i) {
        makeTest(i);
    }
    
    cout << "Done generating 20 tests." << endl;
    return 0;
}