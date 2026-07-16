#include <bits/stdc++.h>
#define N 2000003
using namespace std;
vector<bool> b(N,true);
void sang()
{
    b[0]=false;
    b[1]=false;
    for(int i=2;i*i<=N;i++)
    {
        if(b[i]==true)
            for(int j=i*i;j<=N;j+=i)
             b[j]=false;
    }
}
long long l,r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cau1.inp","r",stdin);
    freopen("cau1.out","w",stdout);
    cin>>l>>r;
    sang();
    long long dem=0;
    for(int i=l;i<r;i++)
    {
        if(b[(i+1)+i]==true)
        {
            dem++;
        }
    }
    cout<<dem;
    return 0;
}
