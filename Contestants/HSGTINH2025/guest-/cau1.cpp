#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool prime(int n){
	if(n<2) return false;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	freopen("cau1.inp", "r", stdin);
    freopen("cau1.out", "w", stdout);
    int l, r;
    cin>>l>>r;
	long long ans=0;
    for(int a=l; a<=r; a++){
        int b=a+1;
        if(b>r) continue;
        long long v=1LL*b*b-1LL*a*a;
        if(v<=N && prime(v)) ans++;
    }
    cout<<ans;
	return 0;
}
