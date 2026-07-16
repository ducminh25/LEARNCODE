#include <bits/stdc++.h>
using namespace std;

void phanTichSoNguyen(long long n, vector<pair<long long, long long>>& factors) {
    for (long long i = 2; i * i <= n; i++) {
        int dem = 0;
        while (n % i == 0) {
            dem++;
            n /= i;
        }
        if (dem > 0) {
            factors.push_back({i, dem});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
}

int main() 
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    freopen ("uocso.inp", "r", stdin);
    freopen ("uocso.out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) 
    {
        long long a, b;
        cin >> a >> b;
        vector<pair<long long, long long>> factorsA, factorsB;
        phanTichSoNguyen (a, factorsA);
        phanTichSoNguyen (b, factorsB);

        map <long long, long long> chung;
        for (auto& factor : factorsA) {
            chung [factor.first] += factor.second;
        }
        for (auto& factor : factorsB) {
            chung [factor.first] += factor.second;
        }

        long long demUocSo = 1;
        for (auto& factor : chung) {
            demUocSo *= (factor.second + 1);
        }

        cout << demUocSo << endl;
    }
    return 0;
}