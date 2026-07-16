#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> sa(n), r(n), tmp(n);
    
    for(int i=0; i<n; i++) sa[i]=i, r[i]=s[i];
    
    for(int t=1; t<n; t<<=1){
        auto cmp=[&](int i, int j){
            if(r[i]!=r[j]) return r[i]<r[j];
            int ri=i+t<n?r[i+t]:-1;
            int rj=j+t<n?r[j+t]:-1;
            return ri<rj;
        };
        
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]]=0;
        for(int i=1; i<n; i++){
            tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1], sa[i])?1:0);
        }
        
        r=tmp;
        if(r[sa[n-1]]==n-1) break;
    }
    
    vector<int> lcp(n);
    for(int i=0,h=0;i<n;i++){
        if(r[i]==n-1){
			h=0;
			continue;
		}
        int j=sa[r[i]+1];
        while(i+h<n && j+h<n && s[i+h]==s[j+h]) h++;
        lcp[r[i]]=h;
        if(h) h--;
    }
    int lg=__lg(n)+1;
    vector<vector<int>> st(lg, vector<int>(n));
    st[0]=lcp;
    for(int i=1; i<lg; i++){
        for(int j=0; j+(1<<i)<=n; j++){
            st[i][j]=min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    
    
    auto getmin=[&](int l, int r){
        if(l>r) return (int)1e9;
        int k=__lg(r-l+1);
        return min(st[k][l], st[k][r-(1<<k)+1]);
    };

    int ans=0;
    for(int i=0; i+k-1<n; i++){
    	ans=max(ans, getmin(i, i+k-2));
	}
    cout<<(ans==0?-1:ans);
    
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	freopen("cau4.inp", "r", stdin);
    freopen("cau4.out", "w", stdout);
	solve();
	return 0;
}

