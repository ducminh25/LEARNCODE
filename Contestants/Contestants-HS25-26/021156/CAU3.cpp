#include <bits/stdc++.h>
#define N int(1e6)
using namespace std;
int n,m;
int a[N+5],b[N+4];
long long p[N+5];
int k[N+6],tam,h;
void sang()
{
    for(int i=2;i<=N;i++)
        p[i]=1;
    p[0]=p[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(p[i]==1)
        {
            //p[i]=i;
            for(int j=i*i;j<=N;j+=i)
            {
                p[j]=0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    sang();
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        if(p[b[i]]==1)
        {
            k[b[i]]++;
        }
        else{
        tam=b[i];
        h=(int)sqrt(tam);
        for(int j=2;j<=h;j++)
        {
            while(tam%j==0)
            {
                tam=tam/j;
                k[j]++;
            }
            if(j>tam)
                break;
        }
        if(tam>1)
            k[tam]++;
        }
    }
    long long d=0,kt;
    for(int i=1;i<=n;i++)
    {
        tam=a[i];
        kt=1;
        if(p[tam]==1)
        {
            if(k[tam]>0)
                kt=0;
        }else{
        h=(int)sqrt(tam);
        //kt=1;
        for(int j=2;j<=h;j++)
        {
            if(tam%j==0)
            {
                if(k[j]>0)
                {
                    kt=0;
                    break;
                }
                while(tam%j==0)
                {
                    tam=tam/j;
                }
            }
            if(j>tam)
                break;
        }
        if(tam>1)
        {
            if(k[tam]>0)
                kt=0;
        }}
        if(kt==1)
            d++;
    }
    cout<<d;
    return 0;
}
