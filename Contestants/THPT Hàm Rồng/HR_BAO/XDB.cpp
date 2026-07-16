#include<bits/stdc++.h>
#define maxn 1000006
using namespace std;
int x,y,kq;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	if (fopen("XDB.inp","r")){
		freopen("XDB.inp","r",stdin);
		freopen("XDB.out","w",stdout);
	}
	string a,b,s;
	getline(cin,a);
	getline(cin,b);
	getline(cin,s);
	s=s+'#';
	unordered_map<char,int>da;
	unordered_map<char,int>db;
	for (int i=0;i<a.size();i++){
		da[a[i]]++;
	}
	for (int i=0;i<b.size();i++){
		db[b[i]]++;
	}
	for (int i=0;i<s.size();i++){
		x=0;y=0;
		for (int j=i;j<=s.size();j++){
			if (da[s[j]]>0||db[s[j]]>0||s[j]==' '){
				if (da[s[j]]>0){
					x++;
				}
				if (db[s[j]]>0){
					y++;
				}
				if (x==y)
					kq++;
			}
			else
				break;
		}
	}
	cout<<kq;
	return 0;
}

