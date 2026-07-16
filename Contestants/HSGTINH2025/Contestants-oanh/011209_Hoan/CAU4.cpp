#include <bits/stdc++.h>
using namespace std;
int n,k,l,t;
string s,st;
unordered_map<string,int>m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU4.inp","r",stdin);
    freopen("CAU4.out","w",stdout);
    cin>>n>>k>>s;
    l=n/k;
    if(k>n) {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<=n;i++) {
        st="";
        for(int j=i;j<i+l;j++) {
            st+=s[j];
            if(st.size()>=t) m[st]++;
            if(m[st]>=k&&st.size()>t) {
                t=st.size();
            }
        }
    }
    if(t==0) cout<<-1;
    else cout<<t;
    return 0;
}
