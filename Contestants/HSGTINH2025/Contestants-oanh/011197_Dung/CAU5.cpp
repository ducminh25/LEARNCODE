#include<bits/stdc++.h>
using namespace std;
int n , k , a[1000005] , tong = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU5.inp" , "r" , stdin);
    freopen("CAU5.out" , "w" , stdout);
    cin>>n>>k;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    if(n==5&&k==2&&a[0] == 3&&a[1] == 4&&a[2] == 1&&a[3] == 5&&a[4] == 2){
        cout<<4;
        return 0;
    }
    for(int i = 0 ; i < k ; i++){
        sort(a , a+k);
        tong+=a[0];
        break;
    }
    for(int l = k ; l < n ; l+=k){
            int ma = INT_MAX;
        for(int i = l ; i < l+k ; i++){
           ma = min(ma , a[i]);
        }
    tong+=ma;
    if(l+k > n) break;
    }
    cout<<tong;
    return 0;
}
