#include <bits/stdc++.h>
using namespace std;
int L[] = {3,0,1,2};
int R[] = {1,2,3,0};
int B[] = {2,3,0,1};
int tx[] = {0,1,0,-1};
int ty[] = {1,0,-1,0};
int n;
string s;
int main()
{
 cin >> n >> s;
 int x=0, y=0, h=0;
 for (int i=0;i<s.size();i++)
 {
  if (s[i] == 'L') h = L[h];
  if (s[i] == 'R') h = R[h];
  if (s[i] == 'B') h = B[h];
  x+=tx[h];
  y+=ty[h];
 }
 cout << x << " " << y;
 return 0;
}