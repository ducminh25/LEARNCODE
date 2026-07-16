#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            int dem=1;
            string st=s.substr(i,j-i+1);
            for(int l=j+1;l<s.size();l++){
                string x=s.substr(l,j-i+1);
                if(x==st)
                    dem++;
                if(dem==k){
                    ans=max(ans,(int)st.size());
                    break;
                }
            }
        }
    }
    if(ans==0)
        cout << -1;
    else
        cout << ans;
    return 0;
}
