// Cho đồ thị có hướng, tìm cách bổ sung thêm ít cung nhất để từ một đỉnh bất kì có thể đến đỉnh 1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, d = 0, k = 0;
int number[maxn], low[maxn], x[maxn], y[maxn], dai_dien[maxn], sc[maxn];
stack<int> st;
bool del[maxn];
vector<int> a[200005];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x[i] >> y[i];
        a[x[i]].push_back(y[i]);
    }
}

void benhanh(int u) {
    k++;
    while (st.top() != u) {
        del[st.top()] = true;
        sc[st.top()] = k;
        st.pop();
    }
    sc[u] = k;
    dai_dien[k] = u;
    del[u] = true;
    st.pop();
}

void dfs(int u) {
    d++;
    number[u] = d;
    low[u] = number[u];
    st.push(u);
    for (int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (del[v] == false) {
            if (number[v] > 0)
                low[u] = min(low[u], number[v]);
            else {
                // cha[v]=u;
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (number[u] == low[u]) benhanh(u); // u la chot
}

void solve() {
    for (int i = 1; i <= n; ++i) {
        if (del[i] == false) dfs(i);
    }
    for (int i = 1; i <= m; ++i) {
        if (sc[x[i]] != sc[y[i]]) dai_dien[sc[x[i]]] = 0;
    }
    int res = 0;
    for (int i = 1; i <= k; ++i) {
        if (dai_dien[i] > 0 && sc[1] != i) res++;
    }
    cout << res << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}

/* GIAINHAT.cpp
Kỳ thi VOI2050 có N thí sinh tham dự. Ban tổ chức cũng thay đổi cách thức xét giải.
Kỳ thi bây giờ có N giải: giải nhất, giải nhì, giải ba, giải tư, …, giải N và mỗi thí sinh sẽ đạt giải ứng với số điểm của mình xét từ cao đến thấp.
Các thí sinh cùng điểm sẽ đạt cùng giải, vì thế có những giải gồm nhiều thí sinh và có những giải sẽ không có thí sinh nào.
Chẳng hạn nếu có hai thí sinh cùng điểm đạt giải ba, thì thí sinh có điểm thấp tiếp theo sẽ đạt giải năm, không có thí sinh giải tư.

Bạn X của đội tuyển trường LTV đã hoàn thành xong bài thi của mình.
Bạn chỉ có một ước muốn nhỏ nhoi là giành giải Nhất.
Tuy nhiên, bản thân bạn cũng biết điều đó quá ư là xa vời. Vì vậy khi nộp bài thi, bạn X đã lén cài một đoạn mã độc nhằm thay đổi kết quả chấm của ban tổ chức.
Đoạn mã bạn viết là một tập M lệnh, mỗi lệnh gồm 2 số nguyên A B sẽ thay đổi kết quả của các thí sinh đang được giải A thành giải B.

Bạn X định sử dụng tập lệnh này để đạt được mục đích của mình.
Ví dụ nếu tập lệnh của bạn hiện có 2 lệnh: 4 1 và 3 4.
Nếu bạn X đạt giải ba, bạn sẽ chạy lệnh 2 trước, sau đó đến lệnh 1 để trở thành thí sinh đạt giải Nhất.

Tuy nhiên, điều bạn X lo lắng là bạn không biết mình sẽ đạt giải mấy và tập M lệnh hiện tại liệu có thể giúp bạn hoàn thành ước muốn hay không?
Em hãy giúp bạn bổ sung thêm một số ít nhất các lệnh để dù cho bạn X đạt bất kì giải nào đều có thể biến đổi thành giải Nhất.

Input
• Dòng 1: 2 số nguyên dương N, M (1 <= N, M, T <= 10^4)

• M dòng tiếp theo, dòng thứ i ghi hai số Ai, Bi của câu lệnh thứ i.

Output
Ghi 1 số nguyên dương duy nhất là số câu lệnh cần thêm. Nếu không cần thêm ghi 0.

INPUT:
6 4
1 3
2 3
4 5
6 5
--> OUTPUT: 2
Tóm tắt đề bài: Cho đồ thị có hướng, tìm cách bổ sung thêm ít cung nhất để từ một đỉnh bất kì có thể đến đỉnh 1.


Tìm xem lỗi sai ở đâu, khi mà output của tôi đối với test đề bài lại đang là 0, chứ không phải là 2
*/