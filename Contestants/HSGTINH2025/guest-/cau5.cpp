#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	freopen("cau5.inp", "r", stdin);
    freopen("cau5.out", "w", stdout);
	int n, k;
    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    static long long dp[505][505];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j]=-1e18;
        }
    }
    dp[0][0]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            int mn=a[i];
            for(int t=i; t>=1; t--){
                mn=min(mn, a[t]);
                if(dp[t-1][j-1]<0) continue;
                dp[i][j]=max(dp[i][j], dp[t-1][j-1]+mn);
            }
        }
    }
    cout<<dp[n][k];
	return 0;
}
