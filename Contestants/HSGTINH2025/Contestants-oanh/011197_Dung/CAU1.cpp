#include<bits/stdc++.h>
using namespace std;
int l , r , dem = 0;
bool ktnt(long long n){
    if(n<2) return false;
    for(int i = 2 ; i*i<= n ; i++){
        if(n%i == 0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU1.INP" , "r" , stdin);
    freopen("CAU1.OUT" , "w" , stdout);
    cin>>l>>r;
    int dema = 0;
     long long b = l+1;
    while(l<r){
        if(b > r){
            l++;
            b = l+1;
        }
        long long hieu = b*b - l*l;
        if(ktnt(hieu)){
            dem++;
        }
        b++;
    }
    cout<<dem;
}
