// #include <bits/stdc++.h>
// using namespace std;

// using T = uint64_t;
// const int SZ = 1 << 18;

// struct LazySeg {
//     T sum[2 * SZ], lazy[2 * SZ], num_active[2 * SZ];
//     LazySeg() {
//         for (int i = 0; i < SZ; ++i)
//             num_active[SZ + i] = 1;
//         for (int i = SZ - 1; i > 0; --i)
//             num_active[i] = num_active[2 * i] + num_active[2 * i + 1];
//     }
//     void push(int ind, int L, int R) {
//         sum[ind] += num_active[ind] * lazy[ind];
//         if (L != R)
//             for (int i = 0; i < 2; ++i)
//                 lazy[2 * ind + i] += lazy[ind];
//         lazy[ind] = 0;
//     }
//     void pull(int ind) {
//         sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
//         num_active[ind] = num_active[2 * ind] + num_active[2 * ind + 1];
//     }
//     void increment(int lo, int hi, int val, int ind = 1, int L = 0, int R = SZ - 1) {
//         push(ind, L, R);
//         if (hi < L || R < lo) return;
//         if (lo <= L && R <= hi) {
//             lazy[ind] = val;
//             push(ind, L, R);
//             return;
//         }
//         int M = (L + R) / 2;
//         increment(lo, hi, val, 2 * ind, L, M);
//         increment(lo, hi, val, 2 * ind + 1, M + 1, R);
//         pull(ind);
//     }
//     T query(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1) {
//         push(ind, L, R);
//         if (lo > R || L > hi) return 0;
//         if (lo <= L && R <= hi) return sum[ind];
//         int M = (L + R) / 2;
//         return query(lo, hi, 2 * ind, L, M) + query(lo, hi, 2 * ind + 1, M + 1, R);
//     }
//     void deactivate(int pos, int ind = 1, int L = 0, int R = SZ - 1) {
//         push(ind, L, R);
//         if (pos > R || L > pos) return;
//         if (pos <= L && R <= pos) {
//             assert(num_active[ind] == 1);
//             sum[ind] = num_active[ind] = 0;
//             return;
//         }
//         int M = (L + R) / 2;
//         deactivate(pos, 2 * ind, L, M);
//         deactivate(pos, 2 * ind + 1, M + 1, R);
//         pull(ind);
//     }
// } Seg;

// int main() {
//     cin.tie(0)->sync_with_stdio(0);
//     int N;
//     cin >> N;
//     vector<int> B(N);
//     for (int& b : B) cin >> b;
//     vector<int> last(N + 1, -1), prev_oc(N);
//     int64_t ans = 0;
//     for (int r = 0; r < N; ++r) {
//         int& last_oc = last[B[r]];
//         ans += Seg.query(last_oc + 1, SZ - 1);
//         if (last_oc != -1) {
//             Seg.deactivate(last_oc);
//             Seg.increment(prev_oc[last_oc], last_oc - 1, -1);
//         }
//         Seg.increment(last_oc, r - 1, 1);
//         prev_oc[r] = last_oc;
//         last_oc = r;
//     }
//     cout << ans << "\n";
// }

#include <bits/stdc++.h>
using namespace std;

#define long long long
const int MAXN = 200005;

int n;
int b[MAXN];
int L[MAXN], R[MAXN];
int last_pos[MAXN];
vector<int> events[MAXN];

struct FenwickTree {
    long tree[MAXN];
    
    void reset() {
        fill(tree, tree + MAXN, 0);
    }

    void update(int idx, long val) {
        for (; idx < MAXN; idx += idx & -idx)
            tree[idx] += val;
    }

    long query(int idx) {
        long sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += tree[idx];
        return sum;
    }

    long query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
} bit_cnt, bit_sum;

void precomputeLR() {
    fill(last_pos, last_pos + MAXN, 0);
    for (int i = 1; i <= n; ++i) {
        L[i] = last_pos[b[i]];
        last_pos[b[i]] = i;
    }

    fill(last_pos, last_pos + MAXN, n + 1);
    for (int i = n; i >= 1; --i) {
        R[i] = last_pos[b[i]];
        last_pos[b[i]] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("TroChoi.Inp", "r")) {
        freopen("TroChoi.Inp", "r", stdin);
        freopen("TroChoi.Out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];

    precomputeLR();

    long total_ans = 0;

    for (int k = 1; k <= n; ++k) {
        long left_len = k - 1 - L[k];
        long right_len = R[k] - 1 - k;
        if (left_len > 0 && right_len > 0) {
            total_ans += left_len * right_len;
        }
    }

    bit_cnt.reset();
    bit_sum.reset();
    for(int i=0; i<MAXN; ++i) events[i].clear();

    for (int i = 1; i <= n; ++i) {
        if (R[i] <= n) events[R[i]].push_back(i);
    }

    long bad_i_count = 0;
    
    for (int k = 1; k <= n; ++k) {
        if (k > 1) {
            int i = k - 1;
            bit_cnt.update(i, 1);
            bit_sum.update(i, R[i]);
        }

        if (k + 1 <= n) {
            for (int idx : events[k + 1]) {
                bit_cnt.update(idx, -1);
                bit_sum.update(idx, -R[idx]);
            }
        }

        int l_bound = L[k] + 1;
        int r_bound = k - 1;
        if (l_bound <= r_bound) {
            long count_large = bit_cnt.query(l_bound, r_bound);
            long sum_R_large = bit_sum.query(l_bound, r_bound);
            bad_i_count += count_large * R[k] - sum_R_large;

            long total_elements = r_bound - l_bound + 1;
            long count_small = total_elements - count_large;
            if (R[k] > k + 1) {
                bad_i_count += count_small * (R[k] - (k + 1));
            }
        }
    }

    bit_cnt.reset();
    bit_sum.reset();
    for(int i=0; i<MAXN; ++i) events[i].clear();

    for (int j = 1; j <= n; ++j) {
        if (L[j] >= 1) events[L[j]].push_back(j);
    }

    long bad_j_count = 0;

    for (int k = n; k >= 1; --k) {
        if (k < n) {
            int j = k + 1;
            bit_cnt.update(j, 1);
            bit_sum.update(j, L[j]);
        }

        if (k - 1 >= 1) {
            for (int idx : events[k - 1]) {
                bit_cnt.update(idx, -1);
                bit_sum.update(idx, -L[idx]);
            }
        }

        int l_bound = k + 1;
        int r_bound = R[k] - 1;

        if (l_bound <= r_bound) {
            long count_small = bit_cnt.query(l_bound, r_bound);
            long sum_L_small = bit_sum.query(l_bound, r_bound);
            bad_j_count += sum_L_small - count_small * L[k];

            long total_elements = r_bound - l_bound + 1;
            long count_large = total_elements - count_small;
            if (k - 1 > L[k]) {
                bad_j_count += count_large * (k - 1 - L[k]);
            }
        }
    }

    cout << total_ans - bad_i_count - bad_j_count;

    return 0;
}