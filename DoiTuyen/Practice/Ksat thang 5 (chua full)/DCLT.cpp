#include <bits/stdc++.h>
using namespace std;

pair<int, int> timMangNN(vector<int> &a, int m) {
    int n = a.size();
    long long sum = 0;
    unordered_map<int, int> mods;
    pair<int, int> result = {9999999, -1};

    for (int i = 0; i < n; ++i) {
        sum = (sum + a[i]) % m;
        if (sum == 0) {
            result = min(result, {i + 1, 0});
        }
        if (mods.find(sum) != mods.end()) {
            if (i - mods[sum] < result.first) {
                result = {i - mods[sum], mods[sum] + 1};
            }
        } else {
            mods[sum] = i;
        }
    }

    if (result.second == -1) {
        return {-1, -1};
    }
    return {result.first, result.second + 1};
}

int main() 
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);
    // freopen ("DCLT.INP", "r", stdin);
    // freopen ("DCLT.OUT", "w", stdout);
    vector <int> a;
    long long m;
    cin >> m;
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    
    pair<int, int> result = timMangNN(a, m);

    if (result.first == -1) {
        cout << -1 << endl;
    } else {
        cout << result.first << " " << result.second << endl;
    }
    return 0;
}

/*
Dãy con liên tiếp
Cho số nguyên dương M và N số nguyên dương a1, a2, ... , aN.
Yêu cầu: Hãy chọn ra k số liên tiếp trong N số đã cho sao cho tổng của chúng chia hết cho m và k là nhỏ nhất.
Dữ liệu vào: DCLT.INP
- Dòng đầu chứa số M và N (M, N<32767)
- Dòng thứ hai chứa N số a1, a2, ... , aN (a<32767)
Dữ liệu ra: ghi vào tệp DCLT.OUT hai số nguyên K và J trong đó:
- K là số phần tử của dãy con liên tiếp có tổng chia hết cho M có ít phần tử nhất
- J là chỉ số của phần tử đầu tiên trong dãy con liên tiếp tìm được (nếu có nhiều dãy con thỏa mãn thì J là chỉ số của phẩn tử trong dãy con đầu tiên).
Nếu có nhiều dãy con thõa mãn thì ghi ra dãy con đầu tiên, nếu không tìm được dãy con nào thì ghi số -1.
*/