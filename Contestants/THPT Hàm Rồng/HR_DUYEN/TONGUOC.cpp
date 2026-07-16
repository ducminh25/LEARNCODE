#include <bits/stdc++.h>

using namespace std;

const int N=1e6;
int n;
long long check[N+5],a[N+5],kq[N+5];
void sang(){
    for(int i=2;i*i<=N;i++){
        if(check[i]==0){
            for(int j=i*i;j<=N;j+=i) check[j]=i;
        }
    }
    for(int i=1;i<=N;i++) {
        if(check[i]==0) check[i]=i;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen("TONGUOC.INP", "r")) {
        freopen("TONGUOC.INP", "r", stdin);
        freopen("TONGUOC.OUT", "w", stdout);
    }

    //sang();
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i];}
    for(int i=1;i<=n;i++){
        //kq[i]+=1;
            if(a[i]>1E6){

            }
            else {
                for(int j=1;j*j<=a[i];j++){
                    if(a[i]%j==0) {
                        if(j*j!=a[i]) {kq[i]+=j;kq[i]+=(a[i]/j);}
                        else kq[i]+=j;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<kq[i]<<" ";
}
