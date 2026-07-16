#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define Name "cau4"
using namespace std;
ll n,k,a[200],d,l,r,max1,hehe;
string s,s1;
map<string,ll>m;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen(Name".INP","r",stdin);
	freopen(Name".OUT","w",stdout);
	cin >>n>>k;
	cin >>s;
    for (int i=0;i<n;i++)
    {
        a[int(s[i])]++;
    }
    for (int i=65;i<=97;i++)
    {
        if (a[i]>=k)
            d++;
    }
    if (d==0)
    {
        cout <<-1;
        return 0;
    }
    r=n-k+1;
    l=1;
    while (l<=r)
    {
        d=0;
        hehe=(l+r)/2;
        for (int i=0;i<n-hehe+1;i++)
        {
            s1=s.substr(i,hehe);
            m[s1]++;
            if (m[s1]==k)
            {
                d++;
                break;
            }
        }
        if (d==1)
        {
            max1=max(max1,hehe);
            l=hehe+1;
        }
        else
        {
            r=hehe-1;
        }
    }
    cout <<max1;
	return 0;
}
