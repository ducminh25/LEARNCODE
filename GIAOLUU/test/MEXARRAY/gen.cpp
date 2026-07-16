#include <bits/stdc++.h>
#include <sys/stat.h> // for mkdir
#include <unistd.h>   // for access/mkdir on some systems
#include <direct.h>   // for _mkdir on Windows

using namespace std;

// =========================================================
// CẤU HÌNH TÊN BÀI VÀ SỐ LƯỢNG TEST
const string baseFolderName = "test";
const string problemName = "MEXARRAY";
const int NUM_CASES_PER_FILE = 500;     // num of testcase in a single input
// =========================================================

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int get_mex(const vector<int>& v) {
    set<int> s(v.begin(), v.end());
    int m = 0;
    while (s.count(m)) m++;
    return m;
}

int get_min(const vector<int>& v) {
    int m = 2e9;
    for (int x : v) m = min(m, x);
    return m;
}

// Reverse Generation Logic - single case at once
string generate_one_case(int n_limit, int k_limit) {
    stringstream ss;
    
    int n = randInt(5, n_limit);
    int k = randInt(1, min(n, k_limit));

    // ans
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int r = randInt(1, 100);
        if (r <= 40) a[i] = randInt(0, k - 1);       // Nhỏ hơn k (tốt cho MEX)
        else if (r <= 60) a[i] = k;                  // Bằng k (tốt cho MIN)
        else a[i] = randInt(k + 1, k + n + 5);       // Lớn hơn k
    }

    // find all [l, r] suitable for MEX or MIN
    struct Cons { int c, l, r; };
    vector<Cons> valid_min, valid_mex;

    for (int l = 0; l < n; ++l) {
        vector<int> sub;
        for (int r = l; r < n; ++r) {
            sub.push_back(a[r]);
            
            if (get_min(sub) == k) 
                valid_min.push_back({1, l + 1, r + 1});
            
            if (get_mex(sub) == k) 
                valid_mex.push_back({2, l + 1, r + 1});
        }
    }

    // no constraint --> redo
    if (valid_min.empty() && valid_mex.empty()) {
        return generate_one_case(n_limit, k_limit); // regenerate with recursion
    }

    // random q from available and suitable
    vector<Cons> final_cons;
    int max_possible = valid_min.size() + valid_mex.size();
    int q = randInt(1, min(100, max_possible));

    for (int i = 0; i < q; ++i) {
        bool pick_min;
        if (valid_mex.empty()) pick_min = true;
        else if (valid_min.empty()) pick_min = false;
        else pick_min = randInt(0, 1);

        if (pick_min) {
            int idx = randInt(0, valid_min.size() - 1);
            final_cons.push_back(valid_min[idx]);
        } else {
            int idx = randInt(0, valid_mex.size() - 1);
            final_cons.push_back(valid_mex[idx]);
        }
    }

    ss << n << " " << k << " " << q << "\n";
    for (auto p : final_cons) {
        ss << p.c << " " << p.l << " " << p.r << "\n";
    }
    
    return ss.str();
}

void create_test(char myfolder[], int id) {
    freopen(myfolder, "w", stdout);
    int n_lim, k_lim;

    if (id <= 35) {
        n_lim = 40; 
        k_lim = 20;
    } 
    else {
        // No constraint
        n_lim = 100;
        k_lim = 99;
    }

    cout << NUM_CASES_PER_FILE << "\n";

    for (int i = 0; i < NUM_CASES_PER_FILE; ++i) {
        cout << generate_one_case(n_lim, k_lim);
    }
}

int main() {
    srand(time(NULL));

    // Sinh từ test00 đến testi
    for (int i = 36; i <= 50; ++i) {
        ostringstream folderName;
        
        folderName << baseFolderName;
        if (i < 10) folderName << "0" << i;
        else folderName << i;

        #ifdef _WIN32
            _mkdir(folderName.str().c_str());
        #else 
            mkdir(folderName.str().c_str(), 0777);
        #endif

        char filename[100];
        strcpy(filename, folderName.str().c_str());
        strcat(filename, "\\"); 
        strcat(filename, problemName.c_str());
        strcat(filename, ".INP");

        create_test(filename, i);
        // Log
        cerr << "Generated: " << filename << endl;
    }
    return 0;
}