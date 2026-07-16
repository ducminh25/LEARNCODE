#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define Name "cau3"
using namespace std;
ll n,m,a[1000001],b[1000001],c[1000001],d[1000001],k,h,z;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen(Name".INP","r",stdin);
	freopen(Name".OUT","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++)
        cin >>a[i];
    for (int i=1;i<=m;i++)
        cin >>b[i];
    d[1]=1;
    d[0]=1;
    for (int i=2;i<=1000;i++)
    {
        if (d[i]==0)
            for (int j=2*i;j<=1000000;j+=i)
                d[j]=1;
    }
    for (int i=1;i<=m;i++)
    {
        k=b[i];
        if (d[k]==0)
            c[k]++;
        else
        {
            for (int j=2;j*j<=k;j++)
                while (k%j==0)
                {
                    k=k/j;
                    c[j]++;
                }
            if (k>1)
                c[k]++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        h=0;
        k=a[i];
        if (d[k]==0)
        {
            if (c[k]==0)
                z++;
        }
        else
        {
            for (int j=2;j*j<=k;j++)
                if (k%j==0)
                {
                    if (c[j]>0)
                    {
                        h++;
                        break;
                    }
                    while (k%j==0)
                    {
                        k=k/j;
                    }
                }
            if (h==0)
                z++;
        }
    }
    cout <<z;
	return 0;
}
