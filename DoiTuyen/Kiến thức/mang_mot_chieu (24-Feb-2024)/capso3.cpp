#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1e3 + 5;

int n, a[MAXN], cnt[MAXN];
bool isPrime[MAXN];

void sangNguyenTo() {
  for (int i = 2; i * i <= MAXN; i++) {
    if (!isPrime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        isPrime[j] = true;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sangNguyenTo();
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (isPrime[a[i] + a[j]]) {
        res++;
      }
    }
  }
  cout << res << endl;
  return 0;
}
