#include <bits/stdc++.h>
#define int long long
using namespace std;

bool ktnt(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2){
        if (n % i == 0) return false;
    }
    return true;
}

int l, r;

void sub1(){
    int ans = 0;
    for (int i = l; i <= r; i++){
        for (int j = i + 1; j <= r; j++){
            if (ktnt(j * j - i * i)){
                ans++;
//                cout << i << ' ' << j << ' ' << j * j - i * i << '\n';
            }
        }
    }

    cout << ans << '\n';
}

void sub2(){
    int ans = 0;
    for (int i = l; i <= r; i++){
        if (ktnt((i + 1) * (i + 1) - i * i)){
            ans++;
        }
    }

    cout << ans;
}

main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("cau1.inp", "r")){
        freopen("cau1.inp", "r", stdin);
        freopen("cau1.out", "w", stdout);
    }

    cin >> l >> r;

//    if (r <= 500) sub1();
//    else{
//        sub2();
//    }

//    sub1();
    sub2();
    return 0;
}
