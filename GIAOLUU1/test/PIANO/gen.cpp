#include <bits/stdc++.h>
#include <sys/stat.h> 

using namespace std;

// --- CẤU HÌNH ---
const int NUM_TESTS = 20;
const string PROBLEM_NAME = "piano";

// Random engine
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Hàm random số nguyên trong đoạn [l, r]
int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// --- LOGIC GIẢI BÀI TOÁN (GIỮ NGUYÊN) ---
const int MAXN = 100005;
int trace[MAXN][6]; 

void solve_internal(int n, const vector<int>& a, string outPath) {
    // Reset trace table
    for(int i = 0; i <= n; ++i) 
        for(int j = 0; j <= 5; ++j) trace[i][j] = 0;

    // Logic DP
    for (int i = 2; i <= n; ++i) {
        for (int cur = 1; cur <= 5; ++cur) {
            for (int prev = 1; prev <= 5; ++prev) {
                if (i > 2 && trace[i - 1][prev] == 0) continue;

                bool ok = false;
                if (a[i] > a[i - 1]) {
                    if (cur > prev) ok = true;
                } else if (a[i] < a[i - 1]) {
                    if (cur < prev) ok = true;
                } else { // a[i] == a[i-1]
                    if (cur != prev) ok = true;
                }

                if (ok) {
                    trace[i][cur] = prev;
                    break; 
                }
            }
        }
    }

    // Truy vết kết quả
    int last_finger = -1;
    for (int j = 1; j <= 5; ++j) {
        if (n == 1 || trace[n][j] != 0) {
            last_finger = j;
            break;
        }
    }

    ofstream out(outPath);
    if (last_finger == -1) {
        out << -1;
    } else {
        vector<int> res;
        res.push_back(last_finger);
        for (int i = n; i > 1; --i) {
            last_finger = trace[i][last_finger];
            res.push_back(last_finger);
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); ++i) 
            out << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    out.close();
}

// --- HÀM SINH TEST (ĐÃ SỬA) ---
void generate_test(int iTest) {
    // 1. Tạo thư mục
    string dirName = "test" + string(iTest < 10 ? "0" : "") + to_string(iTest);
    
    // Lệnh tạo thư mục tương thích Windows
    string cmd = "mkdir " + dirName; 
    // Nếu chạy trên Linux/Mac có thể cần: "mkdir -p " + dirName
    system(cmd.c_str()); 

    string inpPath = dirName + "/" + PROBLEM_NAME + ".inp";
    string outPath = dirName + "/" + PROBLEM_NAME + ".out";

    // 2. Thiết lập cấu hình độ khó (40% test đầu là Easy)
    int n, max_val, step_jump;
    
    if (iTest <= NUM_TESTS * 0.4) { 
        // --- EASY MODE ---
        n = randInt(1, 20);      // N rất nhỏ
        max_val = 50;            // Giá trị a[i] rất nhỏ (<= 50)
        step_jump = 5;           // Bước nhảy nhỏ để số liệu biến thiên chậm
    } else {
        // --- HARD MODE ---
        n = randInt(90000, 100000); // N lớn
        max_val = 200000;           // Giá trị max đề bài
        step_jump = 500;            // Bước nhảy lớn
    }

    // 3. Sinh mảng a[] dựa trên cấu hình trên
    vector<int> a(n + 1);
    int type = randInt(1, 5); 

    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            a[i] = randInt(1, max_val);
        } else {
            if (type == 1) { // Random
                a[i] = randInt(1, max_val);
            }
            else if (type == 2) { // Tăng dần
                a[i] = a[i-1] + randInt(1, step_jump);
            }
            else if (type == 3) { // Giảm dần
                a[i] = max(1, a[i-1] - randInt(1, step_jump));
            }
            else if (type == 4) { // Răng cưa
                if (i % 2 == 0) a[i] = a[i-1] + randInt(1, step_jump);
                else a[i] = max(1, a[i-1] - randInt(1, step_jump));
            }
            else if (type == 5) { // Lặp
                if (randInt(0, 1)) a[i] = a[i-1];
                else a[i] = randInt(1, 10); // Lặp thì cho số nhỏ hẳn
            }
        }
        
        // Luôn đảm bảo nằm trong giới hạn đã thiết lập
        if (a[i] > max_val) a[i] = max_val;
        if (a[i] < 1) a[i] = 1;
    }

    // 4. Ghi Input
    ofstream inp(inpPath);
    inp << n << "\n";
    for (int i = 1; i <= n; ++i) inp << a[i] << (i == n ? "" : " ");
    inp.close();

    // 5. Ghi Output
    solve_internal(n, a, outPath);
    
    cout << "Generated " << dirName << " (N=" << n << ", MaxVal=" << max_val << ")" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i <= NUM_TESTS; ++i) 
        generate_test(i);

    return 0;
}