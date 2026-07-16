#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int , int>
#define endl '\n'
#define vii vector<int>
#define fi first
#define se second
#define mpii map<int , int>

int cnt[30];
int n;
void solve()
{
    memset(cnt , 0 , sizeof(cnt));
    cin>>n;
    for (int i = 1 ; i <= n ; i++)
    {
        string st;
        cin>>st;

        for (auto it : st)
        {
            cnt[it - 'a']++;
        }
    }

    for(int i = 'a' ; i <= 'z' ; i++)
    {
        if(cnt[i - 'a'] != 0 && cnt[i - 'a'] % n != 0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("TDX.INP","r",stdin);
    freopen("TDX.OUT","w",stdout);

    int test;
    cin>>test;
    while(test--)
    {
        solve();
    }
}
