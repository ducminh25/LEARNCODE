#include <bits/stdc++.h>
using namespace std;

int t;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen("VOTE.INP", "r")) {
        freopen("VOTE.INP", "r", stdin);
        freopen("VOTE.OUT", "w", stdout);
    }

    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int votes[n + 1] = {0}, selfVote[n + 1] = {0};
        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            int vt;
            cin >> vt;
            votes[vt]++;

            if (vt == i) selfVote[vt] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            if (votes[i] >= k && selfVote[i] == 0) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

/*
bầu cử, phiếu bầu, được bầu ít nhất k phiếu và không tự bỏ phiếu cho chính mình, mỗi học sinh được bỏ đúng 1 phiếu bầu
in ra số người được bầu vào ban chấp hành theo test
*/