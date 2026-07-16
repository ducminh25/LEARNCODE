#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("cau4.INP","r",stdin);
    freopen("cau4.OUT","w",stdout);
    int n,k;cin>>n>>k;
    string s;cin>>s;
    map<string,int>m;
    int len=-1;
    for(int i=0;i<n;i++){
      string c="";
      for(int j=i;j<n;j++){
        c+=s[j];
        m[c]++;
        if(m[c]>=k)
          len=max(len,(int)c.size());
      }
    }
    cout<<len;
    return 0;
}
