#include <bits/stdc++.h>
#define N 1000002
#define int long long
using namespace std;
int n,k;
string s;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("cau4.inp","r",stdin);
    freopen("cau4.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    int maxso=-1;
    unordered_map<string,int>dem;
    for(int i=0;i<n;i++)
    {
        string st="";
        for(int j=i;j<n;j++)
        {
            st+=s[j];
            dem[st]++;
            if(dem[st]>=k)
            {
                maxso=max(maxso,(int)st.size());
            }
        }
    }
    cout<<maxso;
    return 0;
}
