#include <bits/stdc++.h>
using namespace std;
/** Cách làm nâng cao (của BingAI)
int diChuyenVienGach(vector<int>& h) {
    int total = accumulate(h.begin(), h.end(), 0);
    if (total % h.size() != 0) {
        return -1;
    }

    int average = total / h.size();
    int moves = 0;
    for (int i = 0; i < h.size(); i++) {
        if (h[i] > average) {
            moves += h[i] - average;
        }
    }

    return moves;
}

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int result = diChuyenVienGach(h);
    if (result == -1) {
        cout << "-1";
    } else {
        cout << result;
    }

    return 0;
}
**/
//Cần tính tổng số viên gạch (s)
//Nếu s không chia hết cho số chồng gạch (n) thì không thể xếp (cout<<"-1";)
//Tính trung bình số gạch sau khi xếp bằng nhau ở mỗi chồng gạch (s/n)
/* Duyệt qua các chồng gạch (for):
Nếu chồng thứ i cao hơn trung bình thì chuyển số gạch đi sao cho bằng với trung bình
*/
int n, a[1000005], s, average;
int main ()
{
    cin>>n;
    s = 0;
    for (int i = 1; i<=n; i++)
    {
        cin>>a[i];
        s = s + a[i];
    }
    if (s % n !=0) cout<<"-1";
    else
    {
        long long res = 0;
        average = s/n;
        for (int j = 1; j <=n; j++)
        {
            if (a[j] > average) res = res + (a[j] - average);
        }
        cout<<res;
    }
    return 0;
}

int sochinhphuong(int a,b)
{

}
