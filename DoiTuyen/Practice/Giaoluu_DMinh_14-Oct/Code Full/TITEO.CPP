#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int , int>
#define endl '\n'
#define vii vector<int>
#define fi first
#define se second
#define mpii map<int , int>
int n , k;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("TITEO.INP","r",stdin);
    freopen("TITEO.OUT","w",stdout);

    int test;
    cin>>test ;
    while(test--)
    {
        cin>>n>>k;
        int sodu = n - 1;

        int thuong = k/sodu;
        int du = k%sodu;
        int res = 0 ;
        if(du == 0)
        {
            res = thuong*n - 1;
        }
        else res = thuong*n + du;

         cout<<res<<endl;

    }
}
