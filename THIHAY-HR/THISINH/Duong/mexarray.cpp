#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> res(n+5,0);
    vector<int> ok(n+5,0);
    vector<int> ban(n+5,0);
    while(q--){
      int c,l,r;
      cin >> c >> l >> r;
      l--; r--;
      if(c==1){
        ok[l]++;
        ok[r+1]--;
      }
      else{
        ban[l]++;
        ban[r+1]--;
      }
    }
    for(int i=1;i<n;i++){ok[i]+=ok[i-1];}
    for(int i=1;i<n;i++){ban[i]+=ban[i-1];}
    for(int i=0;i<n;i++){
      if(ok[i]>0){
        if(ban[i]==0){res[i]=k;}
        else{res[i]=k+1;}
      }
    }
    int pt=0;
    for(int i=0;i<n;i++){
      if(res[i]==0){
        res[i]=pt;
        pt++; pt%=k;
      }
    }
    for(int i=0;i<n;i++){
      if(i){cout << " ";}
      cout << res[i];
    }cout << "\n";
  }
  return 0;
}
