#include <bits/stdc++.h>
using namespace std;
long long n,k,tong,somax,v=-1,dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cau3.inp","r",stdin);
    freopen("cau3.out","w",stdout);
    cin>>n>>k;
    vector<int>a(n),b(k);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<k; i++)
    {
        cin>>b[i];
    }

        for(int i=0; i<n; i++)
        {
            bool kt=true;
            for(int j=0; j<k; j++)
            {
                if(__gcd(a[i],b[j])!=1)
                {
                    kt=false;
                    break;
                }
            }
            if(kt==true)
            {
                dem++;
            }
        }
        cout<<dem;

    return 0;
}
