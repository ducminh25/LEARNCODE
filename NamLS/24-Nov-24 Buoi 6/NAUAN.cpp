#include <bits/stdc++.h>
using namespace std;

int minCookingTime(vector<int>& A) {
    int n = A.size();
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;

    int minTime = INT_MAX;

    do {
        int stove1 = 0, stove2 = 0;
        for (int i : perm) {
            if (stove1 <= stove2) {
                stove1 += A[i];
            } else {
                stove2 += A[i];
            }
        }
        minTime = min(minTime, max(stove1, stove2));
    } while (next_permutation(perm.begin(), perm.end()));

    return minTime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("NAUAN.inp", "r")) {
        freopen("NAUAN.inp", "r", stdin);
        freopen("NAUAN.out", "w", stdout);
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << minCookingTime(A) << "\n";
    }

    return 0;
}

/*
Để chuẩn bị cho buổi liên hoan, Hà phải nấu N món ăn, món thứ i có thời gian nấu đúng bằng Ai phút (i=1..N), các món ăn có thể nấu theo thứ tự bất kì. Hà có 2 cái bếp có thể sử dụng cùng lúc nhưng vào một thời điểm mỗi bếp chỉ nấu được một món ăn.

Yêu cầu: Giúp Hà sắp xếp thứ tự nấu các món ăn sao cho thời gian hoàn thành cả N món là ít nhất. Biết rằng thời gian từ lúc nấu xong món này đến lúc đưa món khác lên bếp là không đáng kể.

Input

● Dòng đầu chứa số T là số bộ test (T ≤ 1000);

● Tiếp theo là T test, mỗi test gồm:

- Dòng đầu chứa số nguyên dương N (N ≤ 4).

- Dòng tiếp theo chứa N số nguyên dương A1, A2, ..AN (Ai ≤ 5 với i=1..N).

Output gồm T dòng, mỗi dòng một số nguyên dương là kết quả một test.
*/