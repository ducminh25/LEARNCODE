#include <bits/stdc++.h>
#define N int(5e6)
using namespace std;
int n,k;
int a[N+6];
int minl[N+6],minr[N+6];
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CAU5.INP","r",stdin);
    freopen("CAU5.OUT","w",stdout);
   cin>>n>>k;
   minl[0]=INT_MAX;
   for(int i=1;i<=n;i++)
   {
        cin>>a[i];
        minl[i]=min(minl[i-1],a[i]);
   }
   if(k==1)
   {
       cout<<*min_element(a+1,a+n+1);
       return 0;
   }
   if(k==2)
   {
        minr[n]=a[n];
       for(int i=n-1;i>=1;i--)
        minr[i]=min(minr[i+1],a[i]);
        int t=0;
       for(int i=1;i<n;i++)
       {
           t=max(t,minl[i]+minr[i+1]);
       }
       cout<<t;
   }
    return 0;
}
