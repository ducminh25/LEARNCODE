#include <bits/stdc++.h>

using namespace std;
int n,k,dem=0,d=0,n2;
string s,t,a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){
        t=t+s[i];
        d=0;
        n2=t.size();
        for(int j=0;j<n-t.size()+1;j++){
            a=s.substr(j,n2);
            if(a==t) d++;
            if(d==k){
                    dem=max(dem,n2);
                break;
        }
    }
    }
    if(dem==0) {
        cout<<-1;
        return 0;
    }
    else cout<<dem;
    return 0;
}
