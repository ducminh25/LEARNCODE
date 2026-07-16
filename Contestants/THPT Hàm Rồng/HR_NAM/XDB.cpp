#include <bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
ll i,j,a[1000],b[1000],t1,t2,ans=0,k;
str s1,s2,s,s3;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("XDB.inp","r",stdin);
    freopen("XDB.out","w",stdout);
    cin>>s1>>s2;
    cin.ignore();
    getline(cin,s);
    s='#'+s+'#';
    cin.ignore();
    for(i=0;i<s1.size();i++)
        a[s1[i]]++;
    for(i=0;i<s2.size();i++)
        b[s2[i]]++;
    for(i=1;i<s.size();i++)
        for(j=i;j<s.size();j++)
    {
        t1=t2=0;
        s3=s.substr(i,j-i);
        for(k=0;k<s.size();k++)
        {
            if(a[s3[k]]>0)
                t1++;
            if(b[s3[k]]>0)
                t2++;
            if(a[s3[k]]==0&&b[s3[k]]==0)
                    break;
        }
        if(t1+t2==s3.size()&&t1==t2&&t1!=0)
            {
                cout<<s3<<' ';
                ans++;
            }
        else if(s3.size()==1&&s3[0]==' ')
            ans++;
    }
    cout<<ans;

}
