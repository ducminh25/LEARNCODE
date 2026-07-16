#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
int a[maxn],mx;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (fopen("TONGUOC.inp","r")){
		freopen("TONGUOC.inp","r",stdin);
		freopen("TONGUOC.out","w",stdout);
	}
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++){
		long long kq=0;
		for (int j=1;j*j<=a[i];j++){
			if (a[i]%j==0){
				if (j*j!=a[i]){
					kq+=j;
					kq+=a[i]/j;
				}
				else
					kq+=j;
			}
		}
		cout<<kq<<' ';
	}
	return 0;
}

