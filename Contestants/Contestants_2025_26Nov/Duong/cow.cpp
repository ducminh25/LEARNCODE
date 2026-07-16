#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define io(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define FOR(i,a,b) for(ll i = a;i <= b;++i)
#define FOD(i,a,b) for(ll i = a;i < b;++i)
#define all(v) v.begin(),v.end()

const int N = 1e5;
string s;
ll n,res,c,o,w,t,cnt;
vector<pair<ll,ll>> vc,vo,vw;
void sub1()
{
    FOD(i,0,n){
        if(s[i] == 'C'){
            c = 1;
            while(i + 1 < n && s[i + 1] == 'C'){
                c++;
                i++;
            }
            FOD(j,i + 1,n){
                if(s[j] != 'O') continue;
                o = 1;
                while(j + 1 < n && s[j + 1] == 'O'){
                    o++;
                    j++;
                }
                FOD(k,j + 1,n){
                    if(s[k] != 'W') continue;
                    w = 1;
                    while(k + 1 < n && s[k + 1] == 'W'){
                        k++;
                        w++;
                    }
                    res += c * o * w;
                }
            }
        }
    }
    cout<<res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("cow")
    cin>>n>>s;
    if(n <= 225){
        sub1();
        return 0;
    }
    FOD(i,0,n){
        if(s[i] == 'C'){
            t = i;
            cnt = 1;
            while(i + 1 < n && s[i + 1] == 'C'){
                cnt++;
                i++;
            }
            vc.push_back({t,cnt});
        }
        if(s[i] == 'O'){
            t = i;
            cnt = 1;
            while(i + 1 < n && s[i + 1] == 'O'){
                cnt++;
                i++;
            }
            vo.push_back({t,cnt});
        }
        if(s[i] == 'W'){
            t = i;
            cnt = 1;
            while(i + 1 < n && s[i + 1] == 'W'){
                cnt++;
                i++;
            }
            vw.push_back({t,cnt});
        }
    }
    for(auto &i : vc){
        ll pos = i.first,f = i.second;
        pair<ll,ll> a = {pos,0};
        ll l = upper_bound(all(vo),a) - vo.begin();
        if(l == vc.size()) break;
        FOD(j,l,vo.size()){
            ll q = vo[j].second;
            a = {vo[j].first,0};
            ll u = upper_bound(all(vw),a) - vw.begin();
            if(u == vw.size()) break;
            FOD(k,u,vw.size()) res += f * q * vw[k].second;
        }
    }
    cout<<res;
    return 0;
}

//10
//CCOOWOWCCW

