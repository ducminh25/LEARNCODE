#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ifstream fin("DEMSO.INP");
    ofstream fout("DEMSO.OUT");
    vector<int> numbers;
    int num;

    while (fin >> num) {
        numbers.push_back(num);
    }
    fin.close();

    if (!numbers.empty()) {
        int middleIndex = numbers.size() / 2;
        fout << numbers[middleIndex];
    }
    
    fout.close();
    return 0;
}