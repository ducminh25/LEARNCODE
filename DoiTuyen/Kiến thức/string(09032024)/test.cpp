#include <bits/stdc++.h>
using namespace std;
bool sx(int a,int b)
{
    return a>b;
}
int main ()
{
    int n[10];
    for(int i=0;i<10;i++) cin>>n[i];
    sort(n,n+10,sx);
    for(int i=0;i<10;i++) cout<<n[i]<<" ";
    return 0;
}