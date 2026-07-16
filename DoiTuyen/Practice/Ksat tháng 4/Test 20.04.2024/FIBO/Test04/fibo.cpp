#include<bits/stdc++.h>
using namespace std;
bool f[1000000001];
long long x,dem,n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   freopen("FIBO.INP","r",stdin);
   freopen("FIBO.OUT","w",stdout);
    // Tạo dãy fibonaci
    f[0]=true;
	f[1]=true;
	 int f0=0;
	 int f1=1;
	 int f2=f0+f1;
	while (f2<1000000000)
	{
		f[f2]=true;
		f0=f1;
		f1=f2;
		f2=f0+f1;
	}
	cin>>n;
	
    for (int i = 0; i < n ; i++) { cin>>x;  if  (f[x])  dem++;
	}
      
    cout<<dem;
    return 0;
}
