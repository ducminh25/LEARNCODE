#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
string kq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (fopen("XCLT.inp","r")){
		freopen("XCLT.inp","r",stdin);
		freopen("XCLT.out","w",stdout);
	}
	string s,x="";
	cin>>s;
	s='#'+s;
	char k=s[s.size()-1];
	s=s+k;
	for (int i=1;i<s.size();i++){
		if (s[i]!=s[i-1]){
			x=x+s[i];
		}
		if (s[i]==s[i-1]){
			if (x.size()>kq.size()){
				kq=x;
				x=s[i];
			}
			if (x.size()==kq.size()&&x>kq){
				kq=x;
				x=s[i];
			}
		}
	}
	cout<<kq;
	return 0;
}

