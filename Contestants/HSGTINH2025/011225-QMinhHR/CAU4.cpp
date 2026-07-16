#include<bits/stdc++.h>
using namespace std;
string tao(string s,long long dau,long long dai)
{
    long long i;
    string t="";
    for(i=dau;i<=dau+dai-1;i++)
    {
        t=t+s[i];
    }
    return t;
}
unordered_map<string,long long>d;
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();cout.tie();
    freopen("CAU4.inp","r",stdin);
    freopen("CAU4.out","w",stdout);
    long long n,k,i,j,dem=0,ab,kq=-1,l,mid,r,ans=-1;
    string s,a;
    cin>>n>>k;
    cin>>s;
    s="#"+s;
    if(n<=100)
    {
        for(i=n;i>=1;i--)
    {
        d.clear();
        for(j=1;j<=n-i+1;j++)
        {
           a=tao(s,j,i);
            d[a]++;
            if(d[a]>=k)
            {
                kq=i;
                break;
            }
        }
        if(kq!=-1)
        {
            break;
        }
    }
    cout<<kq;
    }
    else
    {
        l=1;
        r=n;
        while(l<=r)
        {
            mid=(l+r)/2;
            ab=0;
            for(j=1;j<=n-mid+1;j++)
            {
               a=tao(s,j,mid);
                d[a]++;
                if(d[a]>=k)
                {
                    ab=1;
                    break;
                }
            }
            if(ab==1)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        cout<<ans;
    }
}
