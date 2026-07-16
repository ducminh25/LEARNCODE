#include<bits/stdc++.h>
#define M 1000005
using namespace std;
int n , k;
long long a[M] , tong = 0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0);
    freopen("CAU2.inp" , "r" , stdin);
    freopen("CAU2.out" , "w" , stdout);
    cin>>n>>k;
    vector<long long>p;
    for(int i = 0 ; i < n ;i++){
        cin>>a[i];
        p.push_back(a[i]);
    }
    if(k == 0){
        sort(a , a+n , greater<>());
        long long m = a[0];
        for(int i = 0 ; i < n ; i++){
            tong+=(m - a[i]);
        }
        cout<<tong;
        return 0;
    }
    if(k == -1){
        long long m = a[0];
        int dem = 0 , dd;
        vector<long long>c;
        for(int i = 0 ; i < n ; i++){
            if(m >= a[i]){
                tong+=(m - a[i]);
            }
            if(m < a[i]){
                dd = i;
                break;
            }
        }
        for(int i = dd ; i < n ; i++){
            c.push_back(a[i]);
        }
        sort(c.begin() , c.end() , greater<>());
        long long u = c[0];
        for(int i = 0 ; i < (int)c.size() ;i++){
            tong+=u-c[i];
        }
        cout<<tong;
        return 0;
    }
    if(k == 1){
        long long tong =0;
        sort(a , a+n);
        int giua , dd;
        if(n%2 == 1){
            giua = n/2;
        }
        else{
            int giua1 = n /2;
            if(a[giua1] < a[giua1-1]) giua = giua1;
            else{
                giua = giua -1;
            }
        }
        long long o = a[giua];
        for(int i = 0 ; i < n ; i++){
            if(p[i] <= o){
                tong+=(o - p[i]);
            }
            else{
                dd = i;
                break;
            }
        }
        vector<long long>l;
        for(int i = dd ; i < n ; i++){
            l.push_back(p[i]);
        }
        sort(l.begin() , l.end() , greater<>());
        long long b = l[0];
        for(int i = 0 ; i < (int)l.size(); i++){
            tong+=(b-l[i]);
        }
        cout<<tong;
        return 0;
    }
    return 0;
}
