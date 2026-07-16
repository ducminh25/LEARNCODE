#include <bits/stdc++.h>
#include <sys/stat.h>
using namespace std;

// --- CẤU HÌNH ---
const int NUM_TESTS = 20;
const string FOLDER_PREFIX = "test";
const string INPUT_FILE = "CAU4.INP";
const string OUTPUT_FILE = "CAU4.OUT";

// --- TIỆN ÍCH FILE ---
void create_folder(string path) {
    #ifdef _WIN32
        string cmd = "mkdir " + path;
        system(cmd.c_str());
    #else
        mkdir(path.c_str(), 0777);
    #endif
}

long long randInt(long long l, long long r) {
    static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<long long>(l, r)(rng);
}

string randString(int n, int type) {
    string s = "";
    if (type == 0) { // Random A-Z
        for (int i = 0; i < n; i++) s += (char)('A' + randInt(0, 25));
    } else if (type == 1) { // A-C (tăng tỉ lệ lặp)
        for (int i = 0; i < n; i++) s += (char)('A' + randInt(0, 2));
    } else { // Pattern lặp
        string pat = "";
        int len = randInt(1, max(2, n/20));
        for(int i=0; i<len; i++) pat += (char)('A' + randInt(0, 5));
        while(s.size() < n) s += pat;
        s = s.substr(0, n);
    }
    return s;
}

// --- SOLVER: DOUBLE HASH + BINARY SEARCH ---
struct Solver {
    string S;
    int N;
    // Hash parameters
    const long long MOD1 = 1e9 + 7, BASE1 = 311;
    const long long MOD2 = 1e9 + 9, BASE2 = 317;
    vector<long long> pow1, pow2, hash1, hash2;

    Solver(string _S) : S(_S), N(_S.size()) {
        pow1.resize(N + 1); pow2.resize(N + 1);
        hash1.resize(N + 1); hash2.resize(N + 1);
        
        pow1[0] = 1; pow2[0] = 1;
        hash1[0] = 0; hash2[0] = 0;

        for (int i = 0; i < N; i++) {
            pow1[i+1] = (pow1[i] * BASE1) % MOD1;
            pow2[i+1] = (pow2[i] * BASE2) % MOD2;
            hash1[i+1] = (hash1[i] * BASE1 + S[i]) % MOD1;
            hash2[i+1] = (hash2[i] * BASE2 + S[i]) % MOD2;
        }
    }

    pair<long long, long long> getHash(int i, int len) {
        long long h1 = (hash1[i+len] - hash1[i] * pow1[len] % MOD1 + MOD1) % MOD1;
        long long h2 = (hash2[i+len] - hash2[i] * pow2[len] % MOD2 + MOD2) % MOD2;
        return {h1, h2};
    }

    bool check(int len, int K) {
        if (len == 0) return true;
        map<pair<long long, long long>, int> cnt;
        for (int i = 0; i <= N - len; i++) {
            pair<long long, long long> h = getHash(i, len);
            cnt[h]++;
            if (cnt[h] >= K) return true;
        }
        return false;
    }

    int solve(int K) {
        if (K == 1) return N;
        if (K > N) return -1;

        int low = 1, high = N, ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, K)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 1; i <= NUM_TESTS; ++i) {
        string folderName = FOLDER_PREFIX + (i < 10 ? "0" : "") + to_string(i);
        create_folder(folderName);
        
        int N, K;
        string S;

        // --- PHÂN BỐ TEST (Theo đề bài) ---
        if (i <= 8) { // 40% N <= 100
            N = randInt(10, 100);
            K = randInt(2, max(2, N/2));
            S = randString(N, i % 3);
            if (i == 1) K = 101; // Test K > N -> -1
        } 
        else if (i <= 14) { // 30% N <= 10^4
            N = randInt(1000, 10000);
            K = randInt(2, 50);
            S = randString(N, (i%2) + 1);
        } 
        else { // 30% N <= 10^5
            N = randInt(50000, 100000);
            if (i == 20) { // Max constraints
                N = 100000; K = 200; S = randString(N, 1);
            } else {
                K = randInt(10, 500);
                S = randString(N, 2); 
            }
        }

        // Tạo Input
        ofstream inp(folderName + "/" + INPUT_FILE);
        inp << N << " " << K << "\n" << S;
        inp.close();

        // Tạo Output
        Solver solver(S);
        int result = solver.solve(K);
        
        ofstream out(folderName + "/" + OUTPUT_FILE);
        out << result;
        out.close();

        cout << "Gen " << folderName << " OK. N=" << N << " K=" << K << " Ans=" << result << endl;
    }
    return 0;
}