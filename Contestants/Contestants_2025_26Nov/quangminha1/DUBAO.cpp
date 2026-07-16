#include <bits/stdc++.h>
using namespace std;
#define pi pair<long long,long long>
long long a[1000005];
pair<long long,long long>b[1000005];
struct aa
{
    long long first,second,dai;
};
aa p[1000005];
int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      freopen("DUBAO.inp","r",stdin);
      freopen("DUBAO.out","w",stdout);
long long n,i,j,dem=0,dau,cuoi,q=0,dainhat=0,m=0,khong=1,kq,d,kqq=0;
cin>>n;
for(i=1;i<=n;i++)
{
    cin>>a[i];
    if(a[i]>=0)
    {
        a[i]=1;
    }
    else
    {
        a[i]=-1;
    }
}
a[n+1]=1;
for(i=1;i<=n+1;i++)
{
    if(a[i]==-1&&a[i-1]==1)
    {
        dau=i;
    }
    if(a[i]==1&&a[i-1]==-1)
    {
        cuoi=i-1;
        q++;
        p[q].first=dau;
        p[q].second=cuoi;
        p[q].dai=cuoi-dau+1;
        dainhat=max(dainhat,p[q].dai);
    }
}
for(i=q;i>=1;i--)
{
    if(p[i].dai==dainhat)
    {
        m=0;
            for(j=1;j<=q;j++)
            {
                if(i!=j)
                {
                    m++;
                    b[m].first=max(khong,p[j].first-2*p[j].dai);
                    b[m].second=-1;
                    m++;
                    b[m].first=max(khong,p[j].first);
                    b[m].second=1;
                }
            }
                    m++;
                    b[m].first=max(khong,p[i].first-3*p[i].dai);
                    b[m].second=-1;
                    m++;
                    b[m].first=max(khong,p[i].first);
                    b[m].second=1;
           sort(b+1,b+m+1,[&](pi &x,pi &y)
                {
                    if(x.first==y.first)
                    {
                        return x.second<y.second;
                    }
                    else
                    {
                        return x.first<y.first;
                    }
                });
                dau=b[1].first;
                kq=0;
                d=0;
            for(j=1;j<=m;j++)
            {
                d=d+b[j].second;
                if(d==0)
                {
                    kq=kq+b[j].first-dau;
                    dau=b[j+1].first;
                }
            }
            kqq=max(kqq,kq);
    }
    else
    {
        break;
    }
}
cout<<kqq;
}


