#include <bits/stdc++.h>
#include <sys/stat.h>
#include <direct.h> // Windows only. Nếu dùng Linux đổi thành <sys/stat.h> và mkdir(path, 0777)

using namespace std;

// --- CẤU HÌNH TUYỆT ĐỐI ---
const string PROBLEM_NAME = "CAU3";
const int NUM_TESTS = 20;
const int MAX_VAL = 1000000; // Giá trị phần tử tối đa theo đề
const int MAX_N = 1000000;   // Số lượng phần tử tối đa theo đề

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// =================================================================
// LOGIC GIẢI (SOLVER) - CHUẨN MỰC
// =================================================================

// Mảng SPF (Smallest Prime Factor) dùng để phân tích thừa số siêu nhanh
int spf[MAX_VAL + 5];

// Mảng đánh dấu toàn cục (tránh cấp phát động nhiều lần gây chậm)
bool blocked[MAX_VAL + 5];

void sieve() {
    // Khởi tạo spf[i] = i
    iota(spf, spf + MAX_VAL + 5, 0);
    
    // Sàng Eratosthenes cải tiến
    // Chạy chính xác đến căn bậc 2 của MAX_VAL
    for (int i = 2; i * i <= MAX_VAL; i++) {
        if (spf[i] == i) { // Nếu i là số nguyên tố
            for (int j = i * i; j <= MAX_VAL; j += i)
                if (spf[j] == j) spf[j] = i; // Gán ước nguyên tố nhỏ nhất
        }
    }
}

// Hàm giải tối ưu (AC Solution)
int solveOptimized(int n, int m, const vector<int>& a, const vector<int>& b) {
    // 1. Reset mảng đánh dấu
    // Lưu ý: Chỉ reset các vị trí cần thiết sẽ nhanh hơn, nhưng memset an toàn hơn cho logic
    // Với 20 test, memset 10^6 byte vẫn rất nhanh (vài mili giây).
    memset(blocked, 0, sizeof(blocked));

    // 2. Đánh dấu các ước nguyên tố từ mảng B
    for (int x : b) {
        if (x <= 1) continue; // 1 không có ước nguyên tố
        int temp = x;
        while (temp > 1) {
            int p = spf[temp];
            blocked[p] = true;
            while (temp % p == 0) temp /= p;
        }
    }

    // 3. Đếm số phần tử A thỏa mãn
    int count = 0;
    for (int x : a) {
        if (x == 1) {
            // 1 nguyên tố cùng nhau với tất cả (GCD(1, any) = 1)
            count++;
            continue;
        }
        
        bool ok = true;
        int temp = x;
        while (temp > 1) {
            int p = spf[temp];
            if (blocked[p]) { // Nếu ước nguyên tố này đã xuất hiện trong B
                ok = false;
                break;
            }
            while (temp % p == 0) temp /= p;
        }
        
        if (ok) count++;
    }
    return count;
}

// Hàm giải trâu bò (Brute force) - Dùng để kiểm chứng test nhỏ
int solveBrute(int n, int m, const vector<int>& a, const vector<int>& b) {
    int count = 0;
    for (int x : a) {
        bool ok = true;
        for (int y : b) {
            if (__gcd(x, y) != 1) {
                ok = false;
                break;
            }
        }
        if (ok) count++;
    }
    return count;
}

// =================================================================
// GENERATOR
// =================================================================

void genTest(int id) {
    string idStr = (id < 10 ? "0" : "") + to_string(id);
    string dir = "test" + idStr;
    _mkdir(dir.c_str());

    string inpFile = dir + "/" + PROBLEM_NAME + ".INP";
    string outFile = dir + "/" + PROBLEM_NAME + ".OUT";

    int n, m;
    vector<int> a, b;

    // --- PHÂN LOẠI SUBTASK THEO ẢNH ĐỀ BÀI ---
    
    // SUB 1 (30%): n, m <= 1000
    if (id <= 6) {
        n = randInt(10, 1000);
        m = randInt(10, 1000);
        for (int i = 0; i < n; i++) a.push_back(randInt(1, 10000));
        for (int i = 0; i < m; i++) b.push_back(randInt(1, 10000));
    }
    // SUB 2 (30%): Toàn bộ là số nguyên tố
    else if (id <= 12) {
        n = randInt(5000, 10000); // Tăng kích thước sub 2 lên chút cho chắc
        m = randInt(5000, 10000);
        
        // Lọc số nguyên tố thực sự
        vector<int> primes;
        for (int i = 2; i <= MAX_VAL; i++) if (spf[i] == i) primes.push_back(i);
        
        for (int i = 0; i < n; i++) a.push_back(primes[randInt(0, primes.size() - 1)]);
        for (int i = 0; i < m; i++) b.push_back(primes[randInt(0, primes.size() - 1)]);
    }
    // SUB 3 (40%): Không ràng buộc (Max 10^6)
    else {
        // Đây là chỗ Code 1 làm đúng còn Code 2 làm nhẹ.
        // Ta quay lại làm "nặng" đúng đề: N, M tới 1 triệu.
        n = randInt(800000, 1000000); 
        m = randInt(800000, 1000000);
        
        // Để tránh file Output luôn là 0 hoặc N, ta cần mix dữ liệu thông minh:
        // 50% số ngẫu nhiên hoàn toàn
        // 50% số là bội của các số nguyên tố nhỏ (2, 3, 5, 7) để tạo va chạm
        for (int i = 0; i < n; i++) {
            if (randInt(0, 1)) a.push_back(randInt(1, MAX_VAL));
            else a.push_back(randInt(1, MAX_VAL / 2) * 2);
        }
        for (int i = 0; i < m; i++) {
            if (randInt(0, 1)) b.push_back(randInt(1, MAX_VAL));
            else b.push_back(randInt(1, MAX_VAL / 2) * 2);
        }
    }

    // --- KIỂM CHỨNG LOGIC (VALIDATION) ---
    // Chỉ chạy kiểm tra với test nhỏ (n, m <= 2000) để không treo máy
    if (n <= 2000 && m <= 2000) {
        int ansOpt = solveOptimized(n, m, a, b);
        int ansBrute = solveBrute(n, m, a, b);
        if (ansOpt != ansBrute) {
            cerr << "!!! FATAL ERROR at Test " << id << " !!!" << endl;
            cerr << "Optimized: " << ansOpt << " | Brute: " << ansBrute << endl;
            exit(1);
        }
    }

    // --- GHI INPUT ---
    ofstream inp(inpFile);
    inp << n << " " << m << "\n";
    // Tối ưu I/O khi ghi file lớn
    for (int i = 0; i < n; i++) inp << a[i] << (i == n - 1 ? "" : " ");
    inp << "\n";
    for (int i = 0; i < m; i++) inp << b[i] << (i == m - 1 ? "" : " ");
    inp.close();

    // --- GHI OUTPUT ---
    ofstream out(outFile);
    out << solveOptimized(n, m, a, b);
    out.close();

    cout << "Generated Test " << idStr << " | N=" << n << " M=" << m << " [OK]" << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cout << "Initializing Sieve..." << endl;
    sieve();
    
    cout << "Generating 20 tests..." << endl;
    for (int i = 1; i <= NUM_TESTS; i++) {
        genTest(i);
    }
    
    cout << "DONE." << endl;
    return 0;
}