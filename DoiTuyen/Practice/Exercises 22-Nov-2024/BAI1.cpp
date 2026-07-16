#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    if(fopen("BAI1.INP", "r")) {
        freopen("BAI1.inp", "r", stdin);
        freopen("BAI1.out", "w", stdout);
    }

    priority_queue<double, vector<double>, greater<double>> pq;
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        pq.push(x);
    }
    
    double sum = 0;
    while (pq.size() > 1) {
        double a = pq.top(); pq.pop();
        double b = pq.top(); pq.pop();
        double tmp = (a + b) / 2;
        sum += tmp;
        pq.push(tmp);
    }

    double final = pq.top();
    double profit = N * final - sum;
    cout << fixed << setprecision(5) << profit << endl;
    
    return 0;
}