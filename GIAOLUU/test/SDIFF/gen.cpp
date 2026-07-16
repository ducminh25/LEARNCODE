#include <bits/stdc++.h>
#include <sys/stat.h>
#include <unistd.h>
#include <chrono>
#include <random>

// Windows specific headers
#ifdef _WIN32
#include <direct.h>
#endif

using namespace std;

// =========================================================
// GLOBAL SETTINGS
const string baseFolderName = "test";
const string problemName = "SDIFF";
// =========================================================

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// Hàm sinh số nguyên (long long) ngẫu nhiên trong đoạn [l, r]
long long randLong(long long l, long long r) {
    if (l > r) return l;
    return uniform_int_distribution<long long>(l, r)(rng);
}

// Cấu trúc định nghĩa một đợt sinh test
struct GenConfig {
    int start_id;       // Bắt đầu từ test folder nào
    int end_id;         // Kết thúc ở test folder nào
    int min_n, max_n;   // Phạm vi N
    long long max_val;  // Phạm vi tối đa cho p, q, m, t (10^9)
    long long min_m;    // Giá trị m nhỏ nhất (để test chu kỳ ngắn)
};

void create_test(char filepath[], GenConfig cfg) {
    freopen(filepath, "w", stdout);

    // 1. Sinh N
    int n = randLong(cfg.min_n, cfg.max_n);

    // 2. Sinh p, q, m (m > 0)
    // Lưu ý: m tối thiểu phải là 1 (theo đề bài) hoặc cfg.min_m tùy config
    long long m = randLong(max(1LL, cfg.min_m), cfg.max_val);
    long long p = randLong(0, cfg.max_val);
    long long q = randLong(0, cfg.max_val);

    // 3. Sinh T
    long long t = randLong(0, cfg.max_val);

    // Ghi ra file
    cout << n << "\n";
    cout << p << " " << q << " " << m << "\n";
    cout << t; 
}

void process_config(GenConfig cfg) {
    for (int i = cfg.start_id; i <= cfg.end_id; ++i) {
        ostringstream folderName;
        folderName << baseFolderName;
        if (i < 10) folderName << "0" << i;
        else folderName << i;

        // Tạo folder
        #ifdef _WIN32
            _mkdir(folderName.str().c_str());
        #else 
            mkdir(folderName.str().c_str(), 0777);
        #endif

        char filename[256];
        // Tạo đường dẫn file input: testXX/SDIFF.INP
        #ifdef _WIN32
            sprintf(filename, "%s\\%s.INP", folderName.str().c_str(), problemName.c_str());
        #else
            sprintf(filename, "%s/%s.INP", folderName.str().c_str(), problemName.c_str());
        #endif
        
        create_test(filename, cfg);
        
        cerr << "Generated Test " << i << ": N=" << cfg.max_n << ", MaxVal=" << cfg.max_val << endl;
    }
}

int main() {
    // =================================================================
    // KHU VỰC ĐIỀU CHỈNH CẤU HÌNH TEST
    // Constraints: N <= 5.10^6; p,q,m,t <= 10^9
    // =================================================================

    // GROUP 1: Test nhỏ (để debug/verify thủ công)
    // N [10, 100], giá trị nhỏ
    GenConfig group1 = {
        1, 18,           // test01 -> test05
        10, 100,        // N
        1000,           // Val (p,q,m,t <= 1000)
        1               // min_m
    };
    process_config(group1);

    // GROUP 2: Test trung bình
    // N [10^3, 10^4], giá trị lớn 10^9
    GenConfig group2 = {
        19, 30,
        1000, 10000,
        1000000000LL,
        100
    };
    process_config(group2);

    // GROUP 3: Test lớn (Full constraints)
    // N [10^5, 5.10^6], giá trị full 10^9``
    GenConfig group3 = {
        31, 40,
        100000, 5000000,
        1000000000LL,
        10000
    };
    process_config(group3);

    // GROUP 4: Edge cases (m nhỏ -> chu kỳ lặp lại nhiều)
    // N lớn, nhưng m nhỏ (ví dụ m <= 100) để các số lặp lại nhiều
    GenConfig group4 = {
        41, 50,
        2000000, 5000000,
        1000000000LL, // Max val cho p,q,t vẫn lớn
        1             // min_m thấp, nhưng ta sẽ trick ở hàm create nếu cần, 
                      // hoặc đơn giản set max_val ở đây thấp xuống.
                      // Tuy nhiên để giữ structure đơn giản, ta set max_val thấp cho group này:
    };
    // Sửa lại logic cho group 4 một chút bằng cách gọi hàm riêng hoặc config riêng:
    // Ta set max_val nhỏ lại cho group 4 để ép m nhỏ.
    group4.max_val = 500; 
    process_config(group4);

    return 0;
}