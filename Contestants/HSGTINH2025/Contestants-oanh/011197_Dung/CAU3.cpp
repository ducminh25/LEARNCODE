#include<bits/stdc++.h>
using namespace std;
int n , m , a[1000005] , b[1000005] , dem = 0;
bool ktnt(int n){
    if(n<2) return false;
    for(int i = 2 ; i*i<=n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int dema = 0 , demb = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU3.inp" , "r" , stdin);
    freopen("CAU3.out" , "w", stdout);
    cin>>n>>m;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
        if(ktnt(a[i])) dema++;
    }
    for(int i = 0 ; i < m ; i++){
        cin>>b[i];
        if(ktnt(b[i])) demb++;
    }
    if(dema == n && demb == m){
        cout<<n;
        return 0;
    }
    if(dema == 0 && demb  == 0){
        cout<< 0;
        return 0;
    }
    int dem1 = 0;
    for(int i = 0 ; i < n ;i++){
        for(int j = 0 ; j < m ;j++){
            if(__gcd(a[i] , b[j]) == 1) dem1++;
        }
        if(dem1 == m){
                dem++;
        }
        dem1 = 0;
    }
    cout<<dem;
    return 0;
}
