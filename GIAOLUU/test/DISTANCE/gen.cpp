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
const string problemName = "DISTANCE";
// =========================================================

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Hàm sinh số ngẫu nhiên trong đoạn [l, r]
int randInt(int l, int r) {
    if (l > r) return l;
    return uniform_int_distribution<int>(l, r)(rng);
}

// Cấu trúc định nghĩa một đợt sinh test
struct GenConfig {
    int start_id;       // Bắt đầu từ test folder nào
    int end_id;         // Kết thúc ở test folder nào
    int min_n;          // Độ dài N nhỏ nhất (số lượng chữ số)
    int max_n;          // Độ dài N lớn nhất
};

// Hàm sinh chuỗi số ngẫu nhiên có độ dài length
string generate_number_string(int length) {
    if (length <= 0) return "";
    string res = "";
    
    // Chữ số đầu tiên không được là 0 (để đảm bảo là số nguyên dương chuẩn)
    // Trừ khi length = 1 thì có thể cho phép tùy bài, nhưng bài này N > 0 nên ta random 1-9
    int first_digit = randInt(1, 9);
    res += to_string(first_digit);

    // Các chữ số còn lại random từ 0-9
    for (int i = 1; i < length; ++i) {
        res += to_string(randInt(0, 9));
    }
    return res;
}

void create_test(char filepath[], GenConfig cfg) {
    freopen(filepath, "w", stdout);

    // Chọn ngẫu nhiên độ dài N trong khoảng [min_n, max_n]
    int N = randInt(cfg.min_n, cfg.max_n);

    // Sinh hai số X và Y có cùng độ dài N
    string X = generate_number_string(N);
    string Y = generate_number_string(N);

    // Ghi ra file theo format đề bài
    cout << X << "\n";
    cout << Y; // Không in xuống dòng cuối cùng để tránh dư thừa (tùy thói quen)
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
        // Tạo đường dẫn file input: testXX/DISTANCE.INP
        #ifdef _WIN32
            sprintf(filename, "%s\\%s.INP", folderName.str().c_str(), problemName.c_str());
        #else
            sprintf(filename, "%s/%s.INP", folderName.str().c_str(), problemName.c_str());
        #endif
        
        create_test(filename, cfg);
        
        cerr << "Generated Test " << i << ": N length range=[" << cfg.min_n << "," << cfg.max_n << "]" << endl;
    }
}

int main() {
    // =================================================================
    // KHU VỰC ĐIỀU CHỈNH CẤU HÌNH THEO SUBTASK
    // Đề bài: 0 < N <= 150
    // =================================================================

    // SUBTASK 1 (20% số test): 1 <= N <= 9
    // Sinh từ test 01 -> 05
    GenConfig subtask1 = {
        1, 15,       // start_id, end_id
        1, 9        // min_n, max_n (độ dài chuỗi)
    };
    process_config(subtask1);

    // SUBTASK 2 (25% số test): 10 <= N <= 18
    // Sinh từ test 06 -> 10
    GenConfig subtask2 = {
        16, 35,
        10, 18
    };
    process_config(subtask2);

    // SUBTASK 3 (50% số test): Không giới hạn thêm (tức là 19 <= N <= 150)
    // Sinh test ngẫu nhiên trong khoảng lớn: Test 11 -> 15
    GenConfig subtask3_random = {
        36, 45,
        19, 100     // Random các độ dài tầm trung
    };
    process_config(subtask3_random);

    // Sinh test cực đại (Max test): Test 16 -> 20
    // Ép N luôn ở mức cao (140 - 150)
    GenConfig subtask3_max = {
        46, 50,
        145, 150
    };
    process_config(subtask3_max);

    return 0;
}