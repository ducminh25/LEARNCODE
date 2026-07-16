#include <bits/stdc++.h>
using namespace std;

const string PROBLEM_ID = "MEXARRAY";
const string INPUT_EXT = ".INP";
const string OUTPUT_EXT = ".OUT";

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

int main() {
    string testDir = safeGetline(cin);
    string workDir = safeGetline(cin);

    if (testDir.empty() || workDir.empty()) {
        testDir = "";
        workDir = "";
    }

    string inpPath = testDir + PROBLEM_ID + INPUT_EXT;
    string outPath = workDir + PROBLEM_ID + OUTPUT_EXT;

    ifstream inp(inpPath);
    ifstream out(outPath);

    if (!inp.is_open()) finish(0.0, "Loi Checker: Khong tim thay file Input: " + inpPath);
    if (!out.is_open()) finish(0.0, "Loi Checker: Khong tim thay file Output cua thi sinh: " + outPath);

    int t;
    if (!(inp >> t)) finish(0.0, "Loi Input: File Input rong hoac sai dinh dang.");

    for (int iTest = 1; iTest <= t; ++iTest) {
        int n, k, q;
        inp >> n >> k >> q;

        struct Constraint {
            int c, l, r;
        };
        vector<Constraint> cons;
        for (int i = 0; i < q; ++i) {
            int c, l, r;
            inp >> c >> l >> r;
            cons.push_back({c, l, r});
        }

        // Read output
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (!(out >> a[i])) {
                finish(0.0, "Loi Output: Test " + to_string(iTest) + " doc khong du " + to_string(n) + " phan tu.");
            }
            if (a[i] < 0 || a[i] > 1000000000) {
                 finish(0.0, "Loi Output: Test " + to_string(iTest) + " phan tu thu " + to_string(i) + " nam ngoai gioi han.");
            }
        }

        // Check constraints
        for (int i = 0; i < q; ++i) {
            int type = cons[i].c;
            int l = cons[i].l;
            int r = cons[i].r;

            if (type == 1) { // MIN = k
                bool found_k = false;
                bool found_smaller = false;
                int val_smaller = -1;

                for (int j = l; j <= r; ++j) {
                    if (a[j] < k) {
                        found_smaller = true;
                        val_smaller = a[j];
                        break;
                    }
                    if (a[j] == k) found_k = true;
                }

                if (found_smaller) {
                    finish(0.0, "WA Test " + to_string(iTest) + ": Doan [" + to_string(l) + "," + to_string(r) + "] (MIN) co so " + to_string(val_smaller) + " < " + to_string(k));
                }
                if (!found_k) {
                    finish(0.0, "WA Test " + to_string(iTest) + ": Doan [" + to_string(l) + "," + to_string(r) + "] (MIN) khong co so " + to_string(k));
                }

            } else { // MEX = k
                // 1. Khong duoc co k
                for (int j = l; j <= r; ++j) {
                    if (a[j] == k) {
                        finish(0.0, "WA Test " + to_string(iTest) + ": Doan [" + to_string(l) + "," + to_string(r) + "] (MEX) chua so cam " + to_string(k));
                    }
                }
                
                // 2. Co du 0..k-1
                vector<bool> has(k, false);
                for (int j = l; j <= r; ++j) {
                    if (a[j] < k) has[a[j]] = true;
                }
                
                for (int val = 0; val < k; ++val) {
                    if (!has[val]) {
                        finish(0.0, "WA Test " + to_string(iTest) + ": Doan [" + to_string(l) + "," + to_string(r) + "] (MEX) thieu so " + to_string(val));
                    }
                }
            }
        }
    }

    // AC
    finish(1.0, "AC with " + to_string(t) + " test cases.");
    return 0;
}