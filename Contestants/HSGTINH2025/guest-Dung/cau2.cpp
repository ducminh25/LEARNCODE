#include <bits/stdc++.h>
using namespace std;
long long n,k,tong,somax,v=-1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cau2.inp","r",stdin);
    freopen("cau2.out","w",stdout);
    cin>>n>>k;
    vector<long long>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(somax<a[i])
        {
            somax=a[i];
            v=i;
        }
    }
    if(k==0)
    {
        for(int i=0; i<n; i++)
        {
            tong+=abs(somax-a[i]);
        }
        cout<<tong;
    }
    else if(k==-1)
    {
        long long u=-1;
        for(int i=1; i<n; i++)
        {
            if(a[i]<a[0])
            {
                tong+=abs(a[i]-a[0]);
            }
            else if(a[i]>a[0])
            {
                u=i;
                break;
            }
        }
        if(u!=-1)
        {
            for(int i=u; i<n; i++)
            {
                tong+=abs(somax-a[i]);
            }
        }
        cout<<tong;
    }
    else if(k==1)
    {
        long long tongmin=LLONG_MAX,v1=-1;
        for(int i=v; i<n; i++)
        {
            tong+=abs(a[i]-somax);
        }
        for(int i=0;i<v;i++)
        {
            long long o=-1;
            long long tong1=tong;
            for(int j=0;j<v;j++)
            {
                if(a[i]>=a[j]&&j>=o)
                {
                    tong1+=abs(a[i]-a[j]);
                }
                else
                {
                   tong1+=abs(somax-a[j]);
                }
            }
           if(tongmin>tong1)
           {
               tongmin=tong1;
           }
        }
        cout<<tongmin;
    }
    return 0;
}
