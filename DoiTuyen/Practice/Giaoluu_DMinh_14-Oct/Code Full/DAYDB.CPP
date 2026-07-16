#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int , int>
#define endl '\n'
#define vii vector<int>
#define fi first
#define se second
#define mpii map<int , int>
int n ;
const int N = 1e6 + 7;
int pre[N];
int a[N];
int sum = 0;
int tong[N];
void sub1()
{
    for (int i = 1 ;i <= n ; i++)
    {
        tong[i] = tong[i-1] + a[i];
    }
    int res = -1e18;
    for(int i = 1 ;i <= n ; i++)
    {
        for (int j = 1 ; j < i ; j++)
        {
            if(a[i] == a[j])
                res = max(res , tong[i] - tong[j-1]);
        }
    }

    cout<<res<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("DAYDB.INP","r",stdin);
    freopen("DAYDB.OUT","w",stdout);

    cin>>n;
    int res = 0;
    for (int i = 0 ; i <= 1e6 ; i++) pre[i] = -1;
    bool kt = true;
    for (int i = 1 ; i <= n ; i++)
    {
        cin>>a[i];
        if(a[i] < 0) kt = false;
    }

    if(!kt)
    {
        sub1();
        return 0;
    }

    for (int i = 1 ; i <= n ;i++)
    {
        sum += a[i];

        if(pre[a[i]] != -1)
        {
            res = max(res , sum - pre[a[i]]);
        }

        if(pre[a[i]] == -1) pre[a[i]] = sum - a[i];
        else pre[a[i]] = min(pre[a[i]] , sum - a[i]);
    }

    cout<<res<<endl;


}
