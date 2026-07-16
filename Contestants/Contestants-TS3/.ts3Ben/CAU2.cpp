#include <bits/stdc++.h>

using namespace std;
const int N=1e6;
int h[N+5];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);
    int n,k;
    cin >> n >> k;
    int hmax=0;
    set<int> s;
    for(int i=1;i<=n;i++){
        cin >> h[i];
        hmax=max(hmax,h[i]);
        s.insert(h[i]);
    }
    if(k==0){
        long long sum=0;
        for(int i=1;i<=n;i++)
            sum+=hmax-h[i];
        cout << sum;
    }
    else if(k==-1){
        long long sum=0;
        if(h[1]==hmax){
            for(int i=1;i<=n;i++)
                sum+=hmax-h[i];
        }
        else{
            int vt;
            for(int i=1;i<=n;i++){
                if(h[i]<=h[1])
                    sum+=h[1]-h[i];
                else{
                    vt=i;
                    break;
                }

            }
            for(int i=vt;i<=n;i++)
                sum+=hmax-h[i];
        }
        cout << sum;
    }
    else if(k==1){
        long long ans=LLONG_MAX;
        for(int x:s){
            long long sum=0;
            if(x==hmax){
                for(int i=1;i<=n;i++)
                    sum+=hmax-h[i];
            }
            else{
                int vt;
                for(int i=1;i<=n;i++){
                    if(h[i]<=x)
                        sum+=x-h[i];
                    else{
                        vt=i;
                        break;
                    }
                }
                for(int i=vt;i<=n;i++)
                    sum+=hmax-h[i];
            }
            ans=min(ans,sum);
        }
        cout << ans;
    }
    return 0;
}
