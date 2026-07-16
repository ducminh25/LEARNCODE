#include <bits/stdc++.h>
using namespace std;
void solve (){
	
    int n, k;
    cin>>n>>k;
    vector<long long> h(n+1), pre(n+1), suf(n+2);
    
    for(int i=1; i<=n; i++){
        cin>>h[i];
        pre[i]=pre[i-1]+h[i];
    }
    
    for(int i=n;i>=1;i--){
    	suf[i]=suf[i+1]+h[i];
	}
	
	
    if(k==0){
        long long mxh=0;
        for(int i=1;i<=n;i++) mxh=max(mxh,h[i]);
        cout<<mxh*n-pre[n]<<"\n";
        return;
    }
    
    vector<long long> mxpre(n+1), mxsuf(n+2);
    for(int i=1; i<=n; i++) mxpre[i]=max(mxpre[i-1], h[i]);
    for(int i=n; i>=1; i--) mxsuf[i]=max(mxsuf[i+1], h[i]);

    long long ans=LLONG_MAX;

    if(k==-1){
        for(int i=1; i<=n; i++){
            long long L=max(h[1], mxsuf[i]);
            long long cost=h[1]*(i-1)-pre[i-1] + L*(n-i+1)-suf[i];
            ans=min(ans,cost);
        }
    }

    if(k==1){
        for(int i=1; i<=n; i++){
            long long cost=mxpre[i-1]*(i-1)-pre[i-1]+mxsuf[i]*(n-i+1)-suf[i];
            ans=min(ans, cost);
        }
    }

    cout<<ans<<"\n";
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	freopen("cau2.inp", "r", stdin);
    freopen("cau2.out", "w", stdout);
	solve();
	return 0;
}
