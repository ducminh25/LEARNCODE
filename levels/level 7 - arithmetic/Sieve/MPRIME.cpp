#include <bits/stdc++.h>
using namespace std;
int k,m,d;
int const maxx=2000000;
long long t;

int a[maxx+1]; long long p[maxx+1];
int ktnt(long long c)
{
   if(c<2) return 0;
    else
   {
        for(int i=2;i<=int (sqrt(c));i++)
           {if(c%i==0)
               return 0;}
        return 1;
    }
}
void sang_nguyen_to()
{
    for(int i=1;i<=maxx;i++)
    {
        p[i]=1;
    }
    p[0]=0;
    p[1]=0;
    for(int i=2;i<=int(sqrt(maxx));i++)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=maxx;j+=i) p[j]=0;
        }
    }
}
void tao_mang_nt()
{
     d=0;
    for(int i=1;i<=maxx;i++)
    {
        if(p[i]==1)
        {
            d++;
            a[d]=i;
        }
    }
}
long long ghep(long long x, long long y)
{
        long long y1=y; 
        while(y1>0)
        {
            y1=y1/10;
            x=x*10;

        }
        return (x+y);
}
void giai()
{
     m=0;
    for(int i=1;i<=d/2;i++)
    {
        t=ghep(a[i*2-1],a[i*2]);
        if(t<maxx)
        {
            if(p[t]==1)

               {
                   m++;
               }
        }
        else if(ktnt(t)==1)
        {
            m++;
        }
        if(m==k)

            {
                cout<<t;
                return;
            }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>k;
    sang_nguyen_to();
    tao_mang_nt();
    giai();
    return 0;

}
