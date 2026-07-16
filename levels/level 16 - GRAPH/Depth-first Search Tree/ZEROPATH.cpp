/*
input: 12 --> output: 6 \n 0 3 4 6 7 10
         12
       / | \
      0  7  10
           /  \
          0    6
               / \
              0   4
                   \
                    3
*/
#include <bits/stdc++.h>
using namespace std;

int n, d[100005];
vector<int> ans;

void dfs(int u) {
    // cout << endl << "u = " << u;
    int v;
    double sqU = sqrt(u);
    for (int i = 1; i <= sqU; ++i) {
        if (u % i == 0) {
            // cout << "i = " << i << endl;
            v = (i - 1) * (u / i + 1);
            // cout << "v = " << v << endl;
            if (d[v] == 0) {
                d[v] = 1;
                dfs(v);
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("ZEROPATH.INP", "r")) {
        freopen("ZEROPATH.INP", "r", stdin);
        freopen("ZEROPATH.OUT", "w", stdout);
    }

    cin >> n;
    d[0] = 1;
    d[n] = 1;
    dfs(n);
    for (int i = 0; i <= n; ++i) {
        if (d[i] == 1) ans.push_back(i);
    }

    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; ++i)
        cout << ans[i] << " ";

    return 0;
}

/*
Mỗi một số nguyên dương đều có thể biểu diễn dưới dạng tích của 2 số nguyên dương X, Y sao cho X <= Y .
Nếu như trong phân tích này ta thay X bởi X-1 còn Y bởi Y+1 thì sau khi tính tích của chúng ta thu được hoặc là một số nguyên dương mới hoặc là số 0 .

Ví dụ: Số 12 có 3 cách phân tích 1*12 ,3*4 , 2*6. Cách phân tích thứ nhất cho ta tích mới là 0: (1-1)*(12+1) = 0 , cách phân tích thứ hai cho ta tích mới 10: (3-1)*(4+1) = 10 , còn cách phân tích thứ ba cho ta 7: (2-1)*(6+1)=7 .
Nếu kết quả là khác 0 ta lại lặp lại thủ tục này đối với số thu được .
Rõ ràng áp dụng liên tiếp thủ tục trên, cuối cùng ta sẽ đến được số 0, không phụ thuộc vào việc ta chọn cách phân tích nào để tiếp tục

Yêu cầu: Cho trước số nguyên dương N, hãy đưa ra tất cả các số nguyên dương khác nhau có thể gặp trong việc áp dụng thủ tục đã mô tả đối với N.

Input
ghi số nguyên dương N. (1 <= N <= 10^5)

Output
Gồm 2 dòng:
• Dòng đầu tiên ghi K là số lượng số tìm được
• Dòng tiếp theo chứa K số tìm được theo thứ tự tăng dần bắt đầu từ số 0.

Lưu ý: Có thể có số xuất hiện trên nhiều đường biến đổi khác nhau, nhưng nó chỉ được tính một lần trong kết quả.

Ví dụ:
input: 12 --> output: 6 \n 0 3 4 6 7 10
*/