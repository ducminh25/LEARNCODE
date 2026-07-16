#include <bits/stdc++.h>
using namespace std;

int gcd (long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd (b, a % b);
}

int lcm (long long a, long long b)
{
    return a * b / gcd (a, b);
}

void solve ()
{
    int n;
    cin >> n;
    vector <long long> a (n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vector <long long> b (n + 1);
    b [0] = a [0];
    b [n] = a [n - 1];
    
    for (int i = 1; i < n; ++i) {
        b [i] = lcm(a [i - 1], a [i]);
    }
    
    for (int i = 0; i <= n; ++i) 
    {
        cout << b [i] << " ";
    }
    cout << endl;
}
int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);
    
    freopen ("dayucln.inp", "r", stdin);
    freopen ("dayucln.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("dayucln.inp","r",stdin);
    //freopen("xephang.out","w",stdout);
    ll t,n;
    cin>>t;
    while(t--){
        cin >> n;
        ll a[n];
        for (ll i=0;i<n;i++) cin>>a[i];
        cout<<a[0]<<" "<<a[0]*a[1]/__gcd(a[0],a[1])<<" ";
        for(ll i=1;i<n-1;i++) cout<<a[i]*a[i+1]/__gcd(a[i],a[i+1])<<" ";
        cout<<"\n";}
    return 0;
}
*/