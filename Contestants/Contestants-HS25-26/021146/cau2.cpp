#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define Name "cau2"
using namespace std;
ll n,k,a[1000001],l,h,tong,min1=100000000000000;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen(Name".INP","r",stdin);
	freopen(Name".OUT","w",stdout);
	cin >>n>>k;
	for (int i=1;i<=n;i++)
        cin >>a[i];
    if (k==0)
    {
        l=*max_element(a+1,a+n+1);
        for (int i=1;i<=n;i++)
            tong+=l-a[i];
        cout <<tong;
        return 0;
    }
    if (k==-1)
    {
        l=a[1];
        for (int i=1;i<=n;i++)
        {
            if (a[i]<=l)
                tong+=l-a[i];
            else
            {
                l=*max_element(a+1,a+n+1);;
                tong+=l-a[i];
            }
        }
        cout <<tong;
        return 0;
    }
    if (k==1)
    {
        h=*max_element(a+1,a+n+1);
        for (int i=1;i<=n;i++)
        {
            l=a[i];
            tong=0;
            for (int j=1;j<=n;j++)
            {
                if (l>=a[j])
                    tong+=l-a[j];
                else
                {
                    l=h;
                    tong+=l-a[j];
                }
            }
            min1=min(min1,tong);
        }
        cout <<min1;
    }
	return 0;
}
