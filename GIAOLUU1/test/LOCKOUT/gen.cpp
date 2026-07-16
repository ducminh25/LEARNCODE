/*
    author: mon
    created: 27-Nov-2025
    updated: Flexible Generator
*/
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <unistd.h>
#include <direct.h> // Windows specific

using namespace std;

// =========================================================
// GLOBAL SETTINGS
const string baseFolderName = "test";
const string problemName = "LOCKOUT";
const int LIMIT_SUM_N = 300000; // Tổng N tối đa cho phép của đề bài
// =========================================================

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    if (l > r) return l;
    return uniform_int_distribution<int>(l, r)(rng);
}

// Cấu trúc định nghĩa một đợt sinh test
struct GenConfig {
    int start_id;       // Bắt đầu từ test folder nào
    int end_id;         // Kết thúc ở test folder nào
    int fixed_t;        // Số lượng test case trong 1 file (-1 để tự động tối đa hóa)
    int min_n;          // N nhỏ nhất mỗi case
    int max_n;          // N lớn nhất mỗi case
    string array_type;  // "random", "dense" (dày đặc), "asc" (tăng dần), "mixed"
};

// Hàm sinh mảng dựa trên type
vector<int> generate_array(int n, string type) {
    vector<int> a(n);
    if (type == "asc") { 
        // Tăng dần hoặc bằng nhau (dễ tạo ra b_j - b_i = 1)
        a[0] = randInt(1, min(n, 10)); // Start nhỏ
        for(int i=1; i<n; i++) {
            int gap = randInt(0, 2); // 0, 1, hoặc 2
            a[i] = a[i-1] + gap;
            if(a[i] > n) a[i] = n;
        }
    } 
    else if (type == "dense") {
        // Giá trị nhỏ, lặp lại nhiều
        int limit = max(1, (int)sqrt(n) * 3);
        for(int i=0; i<n; i++) a[i] = randInt(1, limit);
    }
    else { 
        // Random "mixed"
        for(int i=0; i<n; i++) a[i] = randInt(1, n);
    }
    
    // Đảm bảo không quá giới hạn đề bài a[i] <= n (mặc dù logic trên đã cover, check lại cho chắc)
    for(int &x : a) x = min(x, n);
    
    return a;
}

void create_test(char filepath[], GenConfig cfg) {
    freopen(filepath, "w", stdout);
    
    vector<pair<int, vector<int>>> all_tests; // Lưu {n, array}
    int current_sum_n = 0;
    int t_count = 0;

    // QUYẾT ĐỊNH SỐ LƯỢNG TEST CASE (T)
    int target_t = cfg.fixed_t;
    if (target_t == -1) target_t = 10000; // Số lớn tượng trưng, sẽ bị chặn bởi LIMIT_SUM_N

    while (t_count < target_t) {
        // Tính toán N cho case này
        int remaining_budget = LIMIT_SUM_N - current_sum_n;
        if (remaining_budget <= 0) break;

        // Xác định N
        int n_upper = min(cfg.max_n, remaining_budget);
        int n_lower = min(cfg.min_n, n_upper);
        
        if (n_lower == 0) break; // Không còn đủ chỗ cho min_n

        int n = randInt(n_lower, n_upper);
        
        // Nếu mode là max test (chỉ 1 test), ép n = remaining_budget luôn nếu config cho phép
        if (cfg.fixed_t == 1 && cfg.max_n >= LIMIT_SUM_N) {
            n = remaining_budget;
        }

        // Sinh mảng
        string type = cfg.array_type;
        if (type == "mixed") {
            int r = randInt(1, 100);
            if (r < 40) type = "random";
            else if (r < 80) type = "dense";
            else type = "asc";
        }

        vector<int> a = generate_array(n, type);
        
        all_tests.push_back({n, a});
        current_sum_n += n;
        t_count++;

        // Nếu đã đạt fixed_t thì dừng
        if (cfg.fixed_t != -1 && t_count >= cfg.fixed_t) break;
    }

    // Ghi ra file
    cout << all_tests.size() << "\n";
    for (auto &test : all_tests) {
        cout << test.first << "\n";
        for (int i = 0; i < test.first; i++) {
            cout << test.second[i] << (i == test.first - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

void process_config(GenConfig cfg) {
    for (int i = cfg.start_id; i <= cfg.end_id; ++i) {
        ostringstream folderName;
        folderName << baseFolderName;
        if (i < 10) folderName << "0" << i;
        else folderName << i;

        #ifdef _WIN32
            _mkdir(folderName.str().c_str());
        #else 
            mkdir(folderName.str().c_str(), 0777);
        #endif

        char filename[256];
        sprintf(filename, "%s\\%s.INP", folderName.str().c_str(), problemName.c_str());
        // Lưu ý: Nếu chạy trên Linux hãy đổi "\\" thành "/"
        
        create_test(filename, cfg);
        cerr << "Generated Test " << i << ": T=" << (cfg.fixed_t == -1 ? "Auto" : to_string(cfg.fixed_t)) 
             << ", N range=[" << cfg.min_n << "," << cfg.max_n << "]" << endl;
    }
}

int main() {
    srand(time(NULL));

    // =================================================================
    // KHU VỰC ĐIỀU CHỈNH CẤU HÌNH (Sửa ở đây để sinh test)
    // =================================================================

    // KỊCH BẢN 1: Sinh test nhỏ (Test 01 -> 10)
    // - Tự động số lượng test case, N nhỏ (5 -> 50)
    GenConfig small_tests = {
        1, 12,      // start_id, end_id
        10,         // fixed_t (-1: auto max fit)
        10, 100,      // min_n, max_n
        "mixed"     // type
    };
    process_config(small_tests);


    // KỊCH BẢN 2: Sinh test vừa (Test 11 -> 20)
    // - Mỗi file khoảng 10 test case, N vừa (100 -> 3000)
    GenConfig medium_tests = {
        13, 30,
        20,         // Cố định 20 test case mỗi file
        100, 3000,
        "mixed"
    };
    process_config(medium_tests);


    // KỊCH BẢN 3: Sinh test MAX N (Test 21 -> 25)
    // - Chỉ 1 test case duy nhất, N = 300,000 (Max Sum)
    GenConfig max_tests = {
        31, 40,
        1,              // Chỉ 1 test case
        LIMIT_SUM_N,    // min_n = 300000
        LIMIT_SUM_N,    // max_n = 300000
        "dense"        // Hoặc "dense" để test TLE
    };
    process_config(max_tests);

    
    // KỊCH BẢN 4: Sinh test MAX T (Test 26 -> 30)
    // - Rất nhiều test case nhỏ (N=1), kiểm tra input/output speed
    GenConfig max_t_tests = {
        41, 50,
        60000,           // max t
        1, 10,         // N cực nhỏ
        "mixed"
    };
    process_config(max_t_tests);
    
    return 0;
}