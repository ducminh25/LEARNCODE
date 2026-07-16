#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    // Calm down and stay cool
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("cau4.inp","r",stdin);
    freopen("cau4.out","w",stdout);

    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    s=" "+s;
    unordered_map<string,int> ump;
    for (int i=1;i<=n;i++){
        string t="";
        for (int j=i;j<=n;j++){
            t+=s[j];
            ump[t]++;
        }
    }
    int maxlen=0;
    for (auto &[u,v]:ump){
        if (v>=k){
            maxlen=max(maxlen,(int)u.size());
        }
    }
    if (maxlen==0){
        cout<<-1;
    }
    else cout<<maxlen;
    return 0;
}
