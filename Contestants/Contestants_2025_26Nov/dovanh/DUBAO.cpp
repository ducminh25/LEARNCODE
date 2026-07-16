#include <bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
ll a[1000005],lanh[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("DUBAO.inp","r"))
    {
        freopen("DUBAO.inp","r",stdin);
        freopen("DUBAO.out","w",stdout);
    }
    ll n;
    cin>>n;
    ll kq=0;
    ll ln=0,d=0,ok=0,lnhat=0;

    for (ll i=1; i<=n; i++) cin>>a[i];
    for (ll i=n; i>=1; i--)
    {
        if (a[i]<0)
        {
            lanh[i]=lanh[i+1]+1;
            lnhat=max(lnhat,lanh[i]);
        }
        else
        {
            lanh[i]=0;
        }
    }
    ll dem=0;
    for (ll i=n; i>=1; i--)
    {
        if (lanh[i]==lnhat) dem++;
    }
    if (dem>1) ok=1;
    if (ok==1)
    {
        ll i=n,nong=0,dnong=0;
        while (i>0)
        {
            if (lanh[i]==lnhat)
            {
                i--;
                while (a[i]>=0)
                {
                    dnong++;
                    i--;
                }
                nong=max(nong,dnong);
                dnong=0;
            }
            else i--;
        }
        ll j=n,dl=0,dn=0;
        while(j>0)
        {
            if (a[j]<0)
            {
                dl++;
                j--;
            }
            else
            {
                ll j1=j;
                while (a[j]>=0)
                {
                    dn++;
                    j--;
                }
                if (dn==nong&&dl==lnhat) kq+=min(3*dl,j1);
                else kq+=min(2*dl,j1);
                dn=0;
                dl=0;
            }
        }
        cout<<kq;

    }
    else
    {
        ll j=n,dl=0,dn=0;
        while(j>0)
        {
            if (a[j]<0)
            {
                dl++;
                j--;
            }
            else
            {
                ll j1=j;
                while (a[j]>=0)
                {
                    dn++;
                    j--;
                }
                if (dl==lnhat) kq+=min(3*dl,j1);
                else kq+=min(2*dl,j1);
                dn=0;
                dl=0;
            }
        }
        cout<<kq;

    }


    return 0;
}

