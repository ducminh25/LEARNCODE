#include <bits/stdc++.h>
#define N 100000000
using namespace std;
long long n,i,a[N+3],d=0;
bool sth(long long n1)
{  long long t=0,i1;
    for(i1=1;i1*i1<=n1;i1++)
        if(n1%i1==0)
        { t=t+i1;
          if((n1/i1 != i1)&&(n1/i1 != n1)) t=t + n1/i1;
        }
    if(t>n1) return true;
    return false;
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   freopen("TIHON.inp","r",stdin);
    freopen("TIHON.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=n;i++)
        if(sth(a[i])) d++;
        cout<<d;
    return 0;
}
