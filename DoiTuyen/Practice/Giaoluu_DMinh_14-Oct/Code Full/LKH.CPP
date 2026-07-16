#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int , int>
#define endl '\n'
#define vii vector<int>
#define fi first
#define se second
#define mpii map<int , int>
int n;
int k;
const int N = 1e5 + 7;
pair<int , int> a[N];

int chiso[N];

int dp[N];

int maxx[N];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("LKH.INP","r",stdin);
    freopen("LKH.OUT","w",stdout);

    cin>>n>>k;
    for (int i = 1 ; i <= n ; i++)
    {
        cin>>a[i].fi;
    }

    for (int i = 1 ; i<= n ; i++)
    {
        cin>>a[i].se;
    }

    sort(a + 1 , a + 1  + n);


    for (int i = 1 ; i <= n ; i++)
    {
        chiso[i] = a[i].fi;
    }
    dp[1] = a[1].se;
    int vt = 1;
    for (int i = 2 ; i <= n ; i++)
    {
        if(a[i].fi - a[1].fi >= k)
        {
            vt = i - 1;
            break;
        }
        dp[i] = a[i].se;
    }

    for (int i = 1 ; i <= vt ; i++)
    {

        maxx[i] = max(maxx[i - 1] , dp[i]);
    }

    for (int i = vt + 1 ; i <= n ; i++)
    {
        int thu = a[i].fi - k;
        int pos = upper_bound(chiso + 1 , chiso + 1 + n , thu) - chiso  - 1;

        dp[i] = max(a[i].se , maxx[pos] + a[i].se);

//        cout<<thu << ' ' << pos << ' ' << maxx[pos]<<endl;
        maxx[i] = max(maxx[i - 1] , dp[i]);
    }

    int ans = 0;

    for (int i = 1 ;i <= n ;i++)
    {
        ans  = max(ans , dp[i]);
    }

    cout<<ans<<endl;

}
