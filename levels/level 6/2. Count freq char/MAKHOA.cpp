#include <bits/stdc++.h>
using namespace std;
 
int d1[100],d2[100];
string s1, s2;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<=s1.size()-1;i++)
        d1[int(s1[i])]++;
    for(int i=0;i<=s2.size()-1;i++)
        d2[int(s2[i])]++;
    for(int i=57;i>=48;i--)
	  if(d1[i]>0 && d2[i]>0) cout << char(i);
}