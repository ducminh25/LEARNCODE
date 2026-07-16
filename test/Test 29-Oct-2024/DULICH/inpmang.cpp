#include    <bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fore(i,a)  for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i-1))&1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
using namespace std;
int test,n,m,k,i,c,u,b,x,y,w,d;
int a[10000001][2];
///--------------------------
int random(int l, int r) {
    long long x = 1ll * rand() * rand() * rand() + 1ll * rand() * rand() + rand();
    return int(x % (r - l + 1) + l);
}
///--------------------------
string changenum(int X){
    string XX = "";
    while (X) XX = (char)(X % 10 + '0') + XX, X/=10;
    return XX;
}
///--------------------------
void	make_test(){
	n = random(5,6);
	//cout<<n;
   m = random(3,6);
   cout << n<<" "<<m<<endl;
	 i=1;
	 while(i<=m){
            d=0;
    k=random(1,3);
    if(k==1){
    x = random(1,1);
    y = random(x+1,n);
    w = random(1,10);
     }
    else
        {
    x = random(1,n-1);
    y = random(x+1,n);
    w = random(1,10);
      }
      for(int j=1;j<i;j++)
        if (a[j][1] == x &&a[j][2]==y)
         { d=1;
             break;}
      if(d==0)
        {a[i][1]=x;
         a[i][2]=y;
         i++;}
    }
     for(i=1;i<=m;i++)
        {w = random(1,10);
      cout<<a[i][1] <<" "<<a[i][2]<<" "<<w<<endl;}
	 //cout<<endl;
     //for(i=1;i<=k;i++)
    // {
    //     c=random(1,999) ;
    //     cout<<c<<" "<< c+random(1,999)<<endl;
    // }

  //  fd(i,n,1) cout << random(1,1E4) <<" "; cout<<endl;
   // fd(i,n,1) cout << random(1,1E4) <<" "; cout<<endl;//'\n';" "<<random(1001,1420) << '\n';
}
///--------------------------
int main(void) {
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (test = 16; test <= 16; ++test) {
        string name = "DULICH";
        name += changenum(test);
        cerr << name << endl;
        string inp = name + ".inp";
        freopen(inp.c_str(), "w", stdout);
        make_test();
        cout << '\n';
    }
    return 0;
}


