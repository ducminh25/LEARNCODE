#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct Edge {
    int to;
    int w;
};

const int maxN = 1e5 + 10;
const ll vc = 10000000000000007; // Giá trị vô cùng lớn để đánh dấu đã cắt nhánh

// Dùng vector thay vì mảng Edge + Head để code gọn và dễ BFS hơn
// Với N = 10^5, vector hoàn toàn nhanh và đủ bộ nhớ.
vector<Edge> adj[maxN];
ll a[maxN];
ll dist[maxN];
int n, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("KITTYTREE.INP", "r")) {
        freopen("KITTYTREE.INP", "r", stdin);
        freopen("KITTYTREE.OUT", "w", stdout);
    }
    
    if (!(cin >> n)) return 0;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // Reset danh sách kề (nếu chạy nhiều test case, ở đây chỉ có 1)
    for(int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 2; i <= n; i++) {
        int p, c;
        cin >> p >> c; 
        // Đề bài: p là cha của i (nghĩa là cạnh nối p -> i)
        // Ta chỉ cần add cạnh 1 chiều từ p -> i để duyệt từ gốc xuống lá
        // Vì i là đỉnh đang xét (chạy từ 2 đến n tương ứng i trong vòng lặp gốc)
        // Input gốc: i từ 1..n, dòng i mô tả cạnh nối i+1 và p_i.
        // Tức là cạnh nối (i) và p. Với i chạy từ 2..n.
        adj[p].push_back({i, c});
    }

    ans = 0;
    
    // BFS KHỬ ĐỆ QUY
    // Sử dụng queue để duyệt cây (Level order traversal)
    // Vì tính chất bài toán duyệt từ trên xuống, BFS hay DFS đều ra kết quả như nhau
    queue<int> q;
    q.push(1);
    
    // Khởi tạo dist cho gốc
    dist[1] = 0; 

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Xử lý logic tại đỉnh u (tương tự đoạn đầu hàm dfs cũ)
        if (a[u] < dist[u]) {
            dist[u] = vc; // Đánh dấu cắt bỏ nhánh này
            ans++;
        }

        // Duyệt các con v của u
        for (Edge &e : adj[u]) {
            int v = e.to;
            int w = e.w;

            // Logic tính dist[v]
            // dist[v] = max(0, dist[u] + w)
            // Nếu dist[u] đã là vc (đã bị cắt), thì dist[v] cũng sẽ >= vc -> con cũng bị cắt
            if (dist[u] >= vc) {
                dist[v] = vc;
            } else {
                dist[v] = max(0LL, dist[u] + w);
            }
            
            q.push(v);
        }
    }

    cout << ans;
    
    return 0;
}