#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll  n,k,h[1000002],d=0,x=0;
ll mal=0,a[1000002],b[1000001];
ll d1=1,mal2,x1=0;
map<ll,ll>m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
            cin>>h[i];
            mal=max(mal,h[i]);
            a[i]=h[i];
    }
    if(k==0){
        for(ll i=1;i<=n;i++){
            d+=mal-h[i];
        }
        cout<<d;
        return 0;
    }
    if(k==-1){
        for(int i=2;i<=n;i++){
            if(h[i-1]>=h[i]&& x==0)
            {
                d+=h[i-1]-h[i];
            }
            else {
                d+=mal-h[i];
                x=1;
            }
        }
        cout<<d;
        return 0;
    }
    if(k==1)
    {
        sort(h+1,h+n+1);
        for(int i=1;i<=n;i++){
           if(h[i]==h[i-1]){
            m[h[i]]=m[h[i-1]];
           }
           else m[h[i]]=i;
        }
       for(int i=1;i<n;i++){
           if(m[a[i]]<m[a[i+1]]) {
            mal2=a[i+1];
            break;
           }
       }
       for(int i=1;i<=n;i++){
        if(mal2>=a[i]){
            d+=mal2-a[i];
        }
        else {
            d+=mal-a[i];
            mal2=0;
        }
       }
       cout<<d;
       return 0;
    }
    return 0;
}
