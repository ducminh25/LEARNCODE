#include <bits/stdc++.h>

using namespace std;
string s1,s2,s;
long long dem1[250],dem2[250];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen("XDB.INP", "r")) {
        freopen("XDB.INP", "r", stdin);
        freopen("XDB.OUT", "w", stdout);
    }

    long long kq;
    cin>>s1;
    cin.ignore();
    cin>>s2;
    cin.ignore();
    getline(cin,s);
    for(char c:s1){
        dem1[c-'a']++;
    }
    for(char c:s2){
        dem2[c-'a']++;
    }
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            bool hi=false;
            for(int h=i;h<=i;h++){
                if(dem1[i-'a']&&dem2[i-'a']) hi=true;
            }
            if(hi) kq++;
        }
    }
    for(char c:s) {if(c==' ') kq++;}
    cout<<kq;
}
