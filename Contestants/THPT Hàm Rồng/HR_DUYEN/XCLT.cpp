#include <bits/stdc++.h>

using namespace std;

string s,kq1;
vector<string> h;
long long dem,cnt;
bool cmp(string a,string b){
    if(a.size()!=b.size()) return a.size()>b.size();
    return a>b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen("XCLT.INP", "r")) {
        freopen("XCLT.INP", "r", stdin);
        freopen("XCLT.OUT", "w", stdout);
    }

    cin>>s;
    s='#'+s;
    s+=s[s.size()-1];
    for(int i=1;i<s.size();i++){
        if(isalpha(s[i])&&isalpha(s[i-1])){
            if(s[i]!=s[i-1]) {
                kq1+=s[i];
            }
                else {
                    h.push_back(kq1);
                    kq1="";
                    kq1+=s[i];
            }
        }
    }
    sort(h.begin(),h.end(),cmp);
    cout<<h[0];
}
