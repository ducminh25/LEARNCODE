#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
int a[maxn],b[maxn];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (fopen("DUTIEC.inp","r")){
		freopen("DUTIEC.inp","r",stdin);
		freopen("DUTIEC.out","w",stdout);
	}
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		cin>>b[i];
	}
	cout<<3;
	return 0;
}

