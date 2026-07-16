#include<bits/stdc++.h>
using namespace std;
#define NAME "CAU4"
#define msi map<string,int>
#define ll long long
#define psi pair<string,int>
#define fi first
#define se second
msi mp;
int n,k,kq=-1;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(NAME".INP","r")){
        freopen(NAME".INP","r",stdin);
        freopen(NAME".OUT","w",stdout);
    }
    cin>>n>>k>>s;
    if(n>1e4){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n;i++){
        string l="";
        for(int j=i;j<n;j++){
            l+=s[j];
            mp[l]++;
        }
    }
    for(psi p:mp){
        if(p.se>=k) kq=max(kq,(int)p.fi.size());
    }
    cout<<kq;
    return 0;
}
