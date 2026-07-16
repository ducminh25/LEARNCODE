#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define Name "cau1"
using namespace std;
ll l,r,a[1000001],d,k;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen(Name".INP","r",stdin);
	freopen(Name".OUT","w",stdout);
	cin >>l>>r;
	a[0]=1;
	a[1]=1;
    for (int i=2;i<=1000;i++)
    {
        if(a[i]==0)
        {
            for (int j=2*i;j<=1000000;j+=i)
                a[j]=1;
        }
    }
    for (int i=l;i<r;i++)
    {
        k=2*i+1;
        if (a[k]==0)
            d++;
    }
    cout <<d;
	return 0;
}
