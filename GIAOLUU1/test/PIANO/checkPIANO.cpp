#include <bits/stdc++.h>
using namespace std;

const string PROBLEM_ID = "piano";
const string INPUT_EXT = ".inp";
const string OUTPUT_EXT = ".out";

string safeGetline(istream& is) {
    string t;
    if (getline(is, t)) {
        while (!t.empty() && (t.back() == '\r' || t.back() == '\n')) t.pop_back();
    }
    return t;
}

void finish(double score, const string& msg) {
    cout << msg << endl;
    cout << fixed << setprecision(2) << score << endl;
    exit(0);
}

// Check tồn tại nghiệm
bool checkExists(int n, const vector<int>& a) {
    vector<bool> possible(6, false); // Trạng thái tại bước i-1
    for(int j=1; j<=5; ++j) possible[j] = true; // Bước 1 luôn chọn được

    for (int i = 2; i <= n; ++i) {
        vector<bool> next_possible(6, false);
        bool has_path = false;
        
        for (int cur = 1; cur <= 5; ++cur) {
            for (int prev = 1; prev <= 5; ++prev) {
                if (!possible[prev]) continue;

                bool ok = false;
                if (a[i] > a[i - 1]) {     
                    if (cur > prev) ok = true;
                } else if (a[i] < a[i - 1]) { 
                    if (cur < prev) ok = true;
                } else {                    
                    if (cur != prev) ok = true;
                }

                if (ok) {
                    next_possible[cur] = true;
                    has_path = true;
                }
            }
        }
        possible = next_possible;
        if (!has_path) return false;
    }
    return true;
}

int main() {
    // 1. SETUP I/O
    string testDir = safeGetline(cin);
    string workDir = safeGetline(cin);
    if (testDir.empty()) testDir = "."; // Fallback cho debug local
    if (workDir.empty()) workDir = ".";

    string inpPath = testDir + "/" + PROBLEM_ID + INPUT_EXT;
    string outPath = workDir + "/" + PROBLEM_ID + OUTPUT_EXT;

    ifstream inp(inpPath);
    ifstream out(outPath);

    if (!inp.is_open()) finish(0.0, "Loi Checker: Khong tim thay file Input.");
    if (!out.is_open()) finish(0.0, "Loi Checker: Khong tim thay file Output.");

    // Read input
    int n;
    if (!(inp >> n)) finish(0.0, "Loi Input: Khong doc duoc N.");
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) inp >> a[i];

    // Read output
    int first_val;
    if (!(out >> first_val)) finish(0.0, "Loi Output: File rong.");

    // TRƯỜNG HỢP 1: THÍ SINH BÁO VÔ NGHIỆM
    if (first_val == -1) {
        // Kiểm tra xem có thừa dữ liệu
        int garbage;
        if (out >> garbage) {
            finish(0.0, "WA: Output in -1 nhung van con du lieu thua phia sau.");
        }

        // Kiểm tra thực tế bài toán có nghiệm hay không
        if (checkExists(n, a)) {
            finish(0.0, "WA: Bai toan CO NGHIEM (tim duoc cach xep), nhung Output lai in -1.");
        } else {
            finish(1.0, "AC: Dung (-1).");
        }
    } 
    
    // TRƯỜNG HỢP 2: THÍ SINH BÁO CÓ NGHIỆM
    else {
        vector<int> b(n + 1);
        b[1] = first_val;

        // Đọc tiếp
        for (int i = 2; i <= n; ++i) {
            if (!(out >> b[i])) {
                finish(0.0, "WA: Output khong du " + to_string(n) + " so (moi doc duoc " + to_string(i-1) + ").");
            }
        }

        // Check dữ liệu thừa
        int garbage;
        if (out >> garbage) {
            finish(0.0, "WA: Output thua du lieu sau khi da doc du N so.");
        }

        // Check miền giá trị [1..5]
        for (int i = 1; i <= n; ++i) {
            if (b[i] < 1 || b[i] > 5) {
                finish(0.0, "WA: Ngon tay thu " + to_string(i) + " co gia tri " + to_string(b[i]) + " (khong nam trong [1,5]).");
            }
        }
        // Check quy tắc di chuyển (Logic cốt lõi)
        // a[i] là nốt hiện tại, a[i+1] là nốt kế tiếp
        // b[i] là ngón hiện tại, b[i+1] là ngón kế tiếp
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i+1]) { // Nốt nhạc đi lên
                if (b[i] >= b[i+1]) // Ngón tay KHÔNG đi lên
                    finish(0.0, "WA: Vi tri " + to_string(i) + ": Not tang (" + to_string(a[i]) + "<" + to_string(a[i+1]) + ") nhung ngon giam/bang (" + to_string(b[i]) + ">=" + to_string(b[i+1]) + ").");
            }
            else if (a[i] > a[i+1]) { // Nốt nhạc đi xuống
                if (b[i] <= b[i+1]) // Ngón tay KHÔNG đi xuống
                     finish(0.0, "WA: Vi tri " + to_string(i) + ": Not giam (" + to_string(a[i]) + ">" + to_string(a[i+1]) + ") nhung ngon tang/bang (" + to_string(b[i]) + "<=" + to_string(b[i+1]) + ").");
            }
            else { // a[i] == a[i+1]
                if (b[i] == b[i+1]) // Dùng cùng 1 ngón
                     finish(0.0, "WA: Vi tri " + to_string(i) + ": Not lap lai nhung dung cung ngon (" + to_string(b[i]) + ").");
            }
        }

        finish(1.0, "AC: Ket qua hop le.");
    }

    return 0;
}