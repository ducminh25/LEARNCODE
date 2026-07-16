#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, card;
    cin >> N;
    map<int, bool> duongsCards;

    for (int i = 0; i < N / 2; ++i) {
        cin >> card;
        duongsCards[card] = true;
    }

    int longestDuong = 0, longestTung = 0;
    int currentStreak = 0;

    for (int i = 1; i <= N; ++i) {
        if (duongsCards[i]) {
            currentStreak++;
            longestDuong = max(longestDuong, currentStreak);
        } else {
            currentStreak = 0;
        }
    }
    currentStreak = 0;

    for (int i = 1; i <= N; ++i) {
        if (!duongsCards[i]) {
            currentStreak++;
            longestTung = max(longestTung, currentStreak);
        } else {
            currentStreak = 0;
        }
    }

    if (longestDuong > longestTung || (longestDuong == longestTung && duongsCards[N])) {
        cout << "DUONG" << endl;
    } else {
        cout << "TUNG" << endl;
    }

    return 0;
}