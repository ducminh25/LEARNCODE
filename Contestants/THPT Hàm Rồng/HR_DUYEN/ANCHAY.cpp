#include <bits/stdc++.h>

using namespace std;
long long n,m,kq;;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen("ANCHAY.INP", "r")) {
        freopen("ANCHAY.INP", "r", stdin);
        freopen("ANCHAY.OUT", "w", stdout);
    }

    cin>>n>>m;
    long long temp=m;
    kq=(m/8)*2;
    m=m%8;
    if(n==7) {
        if((m+n)%8==0) kq+=1;
        else if((m+n)%8==1) kq+=2;
        else if((m+n)%8==2) kq+=2;
        else kq+=2;
    }
    else if(n==8) {
        if(m%7==0) kq+=2;
        else kq+=1;}
    else{
    if((m+n)%8==0) kq+=1;
    else if((m+n)%8==1) kq+=2;
    else if((m+n)%8==2) kq+=2;}
    if(temp%8==0&&n==8) kq-=1;
    if(temp%8==0&&n==7) kq-=1;
    if(temp%8==1&&n==7) kq+=1;
    cout<<kq;
}
