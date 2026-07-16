#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define Name "cau5"
using namespace std;
ll n,k,a[100001],l,min1=10000000001,max1,b[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen(Name".INP","r",stdin);
	freopen(Name".OUT","w",stdout);
	cin >>n>>k;
	for (int i=1;i<=n;i++)
        cin >>a[i];
    if (k==1)
    {
        l=*min_element(a+1,a+n+1);
        cout <<l;
        return 0;
    }
    if (k==2)
    {
        for (int i=1;i<=n;i++)
        {
            min1=min(min1,a[i]);
            b[i]=min1;
        }
        min1=10000000001;
        for (int i=n;i>=1;i--)
        {
            min1=min(min1,a[i]);
            max1=max(max1,min1+b[i-1]);
        }
        cout <<max1;
        return 0;
    }
	return 0;
}
