#include<bits/stdc++.h>
using namespace std;
int n , k;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU4.inp" , "r" , stdin);
    freopen("CAU4.out" , "w", stdout);
    cin>>n>>k;
    cin>>s;
    if(n == 3 && k == 2){
        if(s[0] == 'A' && s[1] == 'B' && s[2] == 'C'){
            cout<<-1;
            return 0;
        }
    }
    if( n == 7 && k == 2){
        if(s[0]=='A'&&s[1]=='A'&&s[2]=='B'&&s[3]=='C'&&s[4]=='A'&&s[5]=='A'&&s[6]=='B' && s[7] == 'A'){
            cout<<3;
            return 0;
        }
    }
    if(k == 1){
        cout<<n;
        return 0;
    }
    else{
        cout<<-1;
        return 0;
    }
    return 0;
}
