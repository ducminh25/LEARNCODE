#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);

    if(fopen("SUBATOMIC.inp", "r")) {
        freopen("SUBATOMIC.inp", "r", stdin);
        freopen("SUBATOMIC.out", "w", stdout);
    }
    
    int N, K;
    cin >> N >> K;
    string particles;
    cin >> particles;

    int distance = N - 1;
    for (int i = 0; i < N - 1; ++i) {
        if (particles[i] == particles[i + 1]) {
            distance += 1;
        }
    }

    for (int i = 0; i < K; ++i) {
        int A;
        cin >> A;
        A--;
        if (A > 0) {
            distance += (particles[A] == particles[A - 1]) ? -1 : 1;
        }
        if (A < N - 1) {
            distance += (particles[A] == particles[A + 1]) ? -1 : 1;
        }

        particles[A] = (particles[A] == '0') ? '1' : '0';

        cout << distance << endl;
    }

    return 0;
}