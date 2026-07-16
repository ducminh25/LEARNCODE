#include <bits/stdc++.h>
using namespace std;

/*
  CAU5 - BO HOA (partition into k contiguous groups, maximize sum of group minimums)
  This file is ONLY a sample generator. It prints ONE test to stdout.

  Format:
    n k
    a1 a2 ... an

  Constraints: 1 <= k <= n <= 1e5, 0 <= ai <= 1e9
*/

static mt19937_64 rng(20261216);

long long rnd(long long l, long long r){
    uniform_int_distribution<long long> dist(l, r);
    return dist(rng);
}

int main(){
    int n = 100000;
    int k = 2;
    cout << n << " " << k << "\n";
    for(int i=1;i<=n;i++){
        long long x = rnd(1, 1000); // many ties
        cout << x << (i==n?'\n':' ');
    }
    return 0;
}
