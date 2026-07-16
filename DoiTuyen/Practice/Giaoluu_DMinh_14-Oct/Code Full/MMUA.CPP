#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int , int>
#define endl '\n'
#define vii vector<int>
#define fi first
#define se second
#define mpii map<int , int>
int n , m , x;
const int N = 1e5 + 7;
vector<int>ke[N];
bool visit[N];

void dfs(int u)
{
    visit[u] = 1;

    for (auto v : ke[u])
    {
        if(!visit[v]) dfs(v);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("MMUA.INP","r",stdin);
    freopen("MMUA.OUT","w",stdout);

    cin>>n>>m>>x;
    for (int i = 1 ; i <= n ; i++)
    {
        visit[i] = 0;
    }
    for (int i = 1 ; i <= m ; i++)
    {
        int u , v , c;
        cin>>u>>v>>c;

        if(c < x) continue;

        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    int res = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if(!visit[i])
        {
            res++;
            dfs(i);
        }
    }

    cout<<res<<endl;
}
