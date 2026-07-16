#include <bits/stdc++.h>
using namespace std;

/*
  Generator for CAU4 (Xâu con): create stress tests.
  Output format:
    N K
    S (uppercase A..Z)
  You can modify patterns below.
*/

static mt19937_64 rng(20261216);
string rand_str(int n, const string &alph="ABCDEFGHIJKLMNOPQRSTUVWXYZ"){
    uniform_int_distribution<int> dist(0,(int)alph.size()-1);
    string s; s.reserve(n);
    for(int i=0;i<n;i++) s.push_back(alph[dist(rng)]);
    return s;
}

int main(){
    // Example: print one random large test
    int N=100000, K=2;
    string S = rand_str(N);
    cout << N << " " << K << "\n" << S << "\n";
    return 0;
}
