#include <bits/stdc++.h>
#define ll long long
#define N 2000005
using namespace std;
ll l,r,dem=0,x;
bool c[N+2];
void sl()
{
    fill(c+2,c+N,true);
    c[0]=c[1]=false;
    for(ll i=2;i<=N;i++){
        if(c[i]){
            for(ll j=i*i;j<=N;j+=i){
                c[j]=false;
            }
        }
    }
}
int main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);
     freopen("CAU1.INP","r",stdin);
     freopen("CAU1.OUT","w",stdout);
     cin>>l>>r;
     sl();
     for(ll i=l;i<=r;i++){
        x=0;
        x=i+(i+1);
        if(c[x]){
            dem++;
        }
     }
     cout<<dem;
    return 0;
}
