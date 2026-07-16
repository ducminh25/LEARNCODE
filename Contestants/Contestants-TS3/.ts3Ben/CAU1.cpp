#include <bits/stdc++.h>

using namespace std;
const int N=1e6;
int d[N+5];
void sang(){
    fill(d,d+N+1,1);
    d[0]=d[1]=0;
    for(int i=2;i*i<=N;i++){
        if(d[i]==1){
            for(int j=i*i;j<=N;j+=i)
                d[j]=0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
    sang();
    int l,r;
    cin >> l >> r;
    long long ans=0;
    for(int i=l+1;i<=r;i++){
        if(d[2*i-1]==1)
            ans++;
    }
    cout << ans;
    return 0;
}
