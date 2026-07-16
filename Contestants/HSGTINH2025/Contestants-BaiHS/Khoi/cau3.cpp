#include <bits/stdc++.h>
#define ll long long
const int N = 1e6 + 2;
using namespace std;

bool c[N];
void snt(){
    memset(c + 2, true, sizeof(c));

    for (int i = 2; i * i <= N; i++){
        if (c[i]){
            for (int j = i * i; j <= N; j += i){
                c[j] = false;
            }
        }
    }
}

int nt[N];
void unt(){
    for (int i = 1; i <= N; i++) nt[i] = i;

    for (int i = 2; i * i <= N; i++){
        for (int j = i * i; j <= N; j += i){
            if (nt[j] == j) nt[j] = i;
        }
    }
}

int n, m, a[N], b[N], ans;

void sub1(){
     for (int i = 1; i <= n; i++){
        bool kt = true;
        for (int j = 1; j <= m; j++){
            if (__gcd(a[i], b[j]) != 1){
                kt = false;
                break;
            }
        }
        if (kt){
//            cout << a[i] << '\n';
            ans++;
        }
    }

    cout << ans << '\n';
}

void sub2(){

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("cau3.inp", "r")){
        freopen("cau3.inp", "r", stdin);
        freopen("cau3.out", "w", stdout);
    }

    snt();
    unt();

    cin >> n >> m;

    int da = 0, db = 0, d1 = 0, d2 = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] == 2) d1++;
        if (c[a[i]]) da++;
    }

    for (int i = 1; i <= m; i++){
        cin >> b[i];
        if (b[i] == 2) d2++;
        if (c[b[i]]) db++;
    }

    if (da == n && db == m && (d1 == 0 || d2 == 0)){
        cout << n;
    }
    else if (n <= 1000 && m <= 1000){
        sub1();
    }
    else{
        sub1();
    }

//    sub2();
    return 0;
}
