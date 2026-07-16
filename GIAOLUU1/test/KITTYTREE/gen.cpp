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
const string problemName = "KITTYTREE"; // Đã đổi tên bài
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
    long long max_val;  // Phạm vi giá trị (trọng số)
    int type;           // 0: Random Tree, 1: Line (thẳng), 2: Star (sao)
};

void create_test(char filepath[], GenConfig cfg) {
    freopen(filepath, "w", stdout);

    // 1. Sinh N
    int n = randLong(cfg.min_n, cfg.max_n);
    cout << n << "\n";

    // 2. Sinh mảng a[i] (giá trị trên đỉnh)
    // a[i] >= 1
    for (int i = 1; i <= n; i++) {
        cout << randLong(1, cfg.max_val) << (i == n ? "" : " ");
    }
    cout << "\n";

    // 3. Sinh các cạnh (n-1 dòng)
    // Theo đề: Dòng thứ i mô tả cạnh nối đỉnh (i+1) và p_i
    // Loop từ node 2 đến node n để tạo cha cho nó.
    
    // Để tạo cây liên thông, cha của đỉnh i thường được chọn trong đoạn [1, i-1]
    // Nếu muốn hoán vị ngẫu nhiên tên đỉnh (shuffling labels) thì phức tạp hơn, 
    // nhưng với CP thông thường, p thuộc [1, i-1] là đủ tốt.

    for (int i = 2; i <= n; i++) {
        int p;
        if (cfg.type == 1) { 
            // Cây thẳng (1-2-3-4...) -> Cha của i là i-1
            p = i - 1; 
        } 
        else if (cfg.type == 2) { 
            // Cây sao (1 nối với tất cả) -> Cha của i luôn là 1
            p = 1; 
        } 
        else { 
            // Random Tree: Cha của i là một nút bất kỳ đã xuất hiện trước đó
            p = randLong(1, i - 1);
        }

        // Trọng số cạnh c có thể âm (-10^9 đến 10^9)
        long long c = randLong(-cfg.max_val, cfg.max_val);
        
        cout << p << " " << c << "\n";
    }
}

void process_config(GenConfig cfg) {
    for (int i = cfg.start_id; i <= cfg.end_id; ++i) {
        ostringstream folderName;
        folderName << baseFolderName;
        if (i < 10) folderName << "00" << i;
        else if (10 <= i < 100) folderName << "0" << i;
        else folderName << i;

        // Tạo folder
        #ifdef _WIN32
            _mkdir(folderName.str().c_str());
        #else 
            mkdir(folderName.str().c_str(), 0777);
        #endif

        char filename[256];
        // Tạo đường dẫn file input: testXX/KITTYTREE.INP
        #ifdef _WIN32
            sprintf(filename, "%s\\%s.INP", folderName.str().c_str(), problemName.c_str());
        #else
            sprintf(filename, "%s/%s.INP", folderName.str().c_str(), problemName.c_str());
        #endif
        
        create_test(filename, cfg);
        
        cerr << "Generated Test " << i << ": N=" << cfg.max_n << ", Type=" << cfg.type << endl;
    }
}

int main() {
    // =================================================================
    // KHU VỰC ĐIỀU CHỈNH CẤU HÌNH TEST
    // Constraints: N <= 10^5; Val <= 10^9
    // =================================================================

    // GROUP 1: Test nhỏ (Random) - Để debug tay
    GenConfig group1 = {
        1, 15,           // test01 -> test15
        5, 20,          // N nhỏ
        100,            // Val nhỏ
        0               // Type 0: Random
    };
    process_config(group1);

    // GROUP 2: Test trung bình (Random)
    GenConfig group2 = {
        16, 30,
        100, 1000,      // N
        1000000000LL,   // Val full
        0               // Type 0: Random
    };
    process_config(group2);

    // GROUP 3: Test lớn (Random) - Full constraints
    GenConfig group3 = {
        31, 60,
        50000, 100000,  // N Max
        1000000000LL,   // Val Max
        0               // Type 0: Random
    };
    process_config(group3);

    // GROUP 4: Test đặc biệt - Cây thẳng (Line/Bamboo)
    // Test Stack Overflow hoặc TLE nếu thuật toán O(N^2) xấu
    GenConfig group4 = {
        61, 80,
        90000, 100000,
        1000000000LL,
        1               // Type 1: Line
    };
    process_config(group4);

    // GROUP 5: Test đặc biệt - Cây hình sao (Star)
    // Test cha là 1 hết
    GenConfig group5 = {
        81, 100,
        90000, 100000,
        1000000000LL,
        2               // Type 2: Star
    };
    process_config(group5);

    return 0;
}