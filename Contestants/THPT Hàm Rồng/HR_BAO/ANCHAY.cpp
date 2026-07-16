#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
long long kq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (fopen("ANCHAY.inp","r")){
		freopen("ANCHAY.inp","r",stdin);
		freopen("ANCHAY.out","w",stdout);
	}
	long long n,m;
	cin>>n>>m;
	m--;
	long long sotuan=m/7;
	kq+=sotuan*2;
	long long du=m%7;
	for (int i=n;i<=n+du;i++){
		if (i==7||i==8||i==14||i==15)
			kq++;
	}
	cout<<kq;
	return 0;
}

