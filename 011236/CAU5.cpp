#include <bits/stdc++.h>
using namespace std;

int minstacks(int n, vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; ++i) {
        books[i] = {a[i], b[i]};
    }

    sort(books.begin(), books.end());
    multiset<int> stacks;
    
    for (auto& book : books) {
        int bi = book.second;
        
        auto it = stacks.upper_bound(bi);
        if (it != stacks.end()) {
            stacks.erase(it);
        }
        stacks.insert(bi);
    }
    
    return stacks.size();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU5.inp", "r")) {
        freopen("CAU5.inp", "r", stdin);
        freopen("CAU5.out", "w", stdout);
    }

    int t;
    cin >> t;
    vector<int> res;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        res.push_back(minstacks(n, a, b));
    }
    
    for (int r : res) {
        cout << r << endl;
    }

    return 0;
}

/*
Ngăn xếp
Hà có N cuốn sách mới, đánh số từ 1 đến N, em sẽ xếp N cuốn sách này vào các ngăn xếp. Là một người rất nguyên tắc nên mỗi cuốn sách khi xếp vào (và lấy ra) đều sẽ được Hà thực hiện theo thứ tự xác định, cuốn thứ i có thứ tự xếp vào là ai (i=1..N). Mỗi lần lấy sách ra đọc, Hà cũng sẽ lấy cả N cuốn ra và cuốn thứ i có thứ tự lấy ra là bi (i=1..N).
Với hai cuốn sách thứ i, j khác nhau bất kỳ (i, j=1..N) khi được xếp vào chung một ngăn xếp, nếu thứ tự xếp vào của cuốn i bé hơn thứ tự xếp vào của cuốn j thì thứ tự lấy ra của cuốn i phải lớn hơn thứ tự lấy ra của cuốn j (hoặc ngược lại). Tức là nếu ai < aj và bi > bj (hoặc ai > aj và bi < bj) thì hai cuốn i, j mới có thể xếp chung một ngăn xếp.
Yêu cầu: Tính số ngăn xếp ít nhất để Hà có thể xếp vào và lấy ra được N cuốn sách như mô tả trên.

Dữ liệu: Vào từ tệp văn bản CAU5.INP gồm:
- Dòng đầu chứa số nguyên dương T là số test (T ≤ 3);
- Tiếp theo là T test, mỗi test gồm:
  o Dòng đầu chứa số nguyên dương N (N ≤ 2.10^5);
  o Dòng thứ hai chứa N số nguyên dương a1, a2,..., aN (ai ≤ N và khác nhau đối với mỗi i = 1..N).
  o Dòng thứ ba chứa N số nguyên dương b1, b2,..., bN (bi ≤ N và khác nhau đối với mỗi i = 1..N).

Kết quả: Ghi ra tệp văn bản CAU5.OUT gồm T dòng là kết quả của T test, mỗi test ghi ra một số nguyên là số ngăn xếp ít nhất tìm được.

*/