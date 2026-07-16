/**
 * Generator for Problem: CNTPATHS
 * Author: Mon's Assistant
 * Standard: C++14, Competitive Programming Style
 */
#include <bits/stdc++.h>
#include <sys/stat.h> // For mkdir (Linux/Windows compat attempt)
#include <direct.h>   // For _mkdir (Windows specific)

using namespace std;

// --- Cấu hình ---
const int NUM_TESTS = 40;
const string PROBLEM_NAME = "cntpaths";

// --- Random Engine ---
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

// --- Giải thuật chuẩn (Reference Solution) ---
// Được nhúng vào để sinh output ngay lập tức
// --- Giải thuật chuẩn (Reference Solution) - KHỬ ĐỆ QUY ---
namespace Solver {
    const int MAXN = 200005;
    vector<int> adj[MAXN];
    int color[MAXN];
    int S[MAXN];    // Mảng đếm toàn cục
    
    // Các mảng hỗ trợ khử đệ quy
    int parent[MAXN];      // Lưu cha của node
    int head[MAXN];        // Lưu vị trí cạnh đang xét trong adj
    int entry_S[MAXN];     // Lưu giá trị S[color[u]] lúc mới vào u
    int before_S[MAXN];    // Lưu S[color[cha]] trước khi xuống con u
    
    long long ans;
    int n;

    void solve(ifstream &in, ofstream &out) {
        if (!(in >> n)) return;
        
        // Reset dữ liệu
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            S[i] = 0;
            head[i] = 0; // Reset vị trí duyệt cạnh
        }

        for (int i = 1; i <= n; ++i) in >> color[i];
        
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            in >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // --- BẮT ĐẦU ITERATIVE DFS ---
        // Mô phỏng lại chính xác logic đệ quy
        vector<int> st; // Stack thủ công
        st.push_back(1);
        parent[1] = 0;
        
        // Bước chuẩn bị cho Root (tương đương Pre-order của Root)
        entry_S[1] = S[color[1]];

        while (!st.empty()) {
            int u = st.back();

            // Tìm con chưa duyệt tiếp theo
            bool pushed_child = false;
            while (head[u] < adj[u].size()) {
                int v = adj[u][head[u]];
                head[u]++; // Tăng index để lần sau không xét lại cạnh này nữa
                
                if (v == parent[u]) continue;

                // Chuẩn bị xuống con v
                parent[v] = u;
                
                // Lưu trạng thái S của màu cha (u) trước khi duyệt con (v)
                // Để sau này tính được sự chênh lệch (L)
                before_S[v] = S[color[u]]; 
                
                // "Gọi đệ quy" -> Push v vào stack
                // Pre-order logic cho v
                entry_S[v] = S[color[v]];
                
                st.push_back(v);
                pushed_child = true;
                break; // Break để xử lý v ngay lập tức (Depth First)
            }

            if (pushed_child) continue;

            // --- POST-ORDER (Khi đã duyệt xong hết con của u) ---
            // 1. Logic chặn tầm nhìn: u chặn các đỉnh màu color[u] bên dưới
            S[color[u]] = entry_S[u] + 1;

            // 2. Cập nhật kết quả cho CHA của u (nếu u không phải root)
            // Logic: Sau khi duyệt xong subtree u, ta tính xem u đóng góp bao nhiêu
            // đỉnh màu "color[parent]" cho cha.
            if (u != 1) {
                int p = parent[u];
                int c_p = color[p];
                
                int prev = before_S[u]; // S[c_p] trước khi vào u
                int curr = S[c_p];      // S[c_p] sau khi thoát u
                
                long long L = curr - prev;
                ans += L * (L + 1) / 2;
            }

            // Xong u, pop khỏi stack
            st.pop_back();
        }
        // --- KẾT THÚC DFS ---

        // Xử lý các TPLT chứa gốc cây (root component)
        // Phần này giữ nguyên như logic cũ
        for (int i = 1; i <= n; ++i) {
            long long L = S[i];
            ans += L * (L - 1) / 2;
        }

        out << ans << "\n";
    }
}
// --- Hàm sinh Test ---

// Hàm tạo thư mục đa nền tảng
void makeDir(string path) {
    #ifdef _WIN32
        _mkdir(path.c_str());
    #else
        mkdir(path.c_str(), 0777);
    #endif
}

void generate_input(int test_id, string filename) {
    ofstream out(filename);
    
    int t, n_min, n_max;
    string type = "random";

    // Phân loại test
    if (test_id <= 12) { // 30% Easy
        t = randInt(5, 10);
        n_min = 10; n_max = 100;
    } else if (test_id <= 30) { // Random Large
        t = 1;
        n_min = 150000; n_max = 200000;
    } else if (test_id <= 35) { // Line Graph (Deep recursion)
        t = 1;
        n_min = 150000; n_max = 200000;
        type = "line";
    } else { // Star Graph
        t = 1;
        n_min = 150000; n_max = 200000;
        type = "star";
    }

    out << t << "\n";
    while (t--) {
        int n = randInt(n_min, n_max);
        out << n << "\n";

        // Sinh màu: Để có nhiều đường đẹp, số lượng màu nên ít hơn N
        // Nếu mỗi đỉnh 1 màu -> ans = 0.
        int num_colors = randInt(1, max(2, n / 5)); 
        for (int i = 0; i < n; ++i) {
            out << randInt(1, num_colors) << (i == n - 1 ? "" : " ");
        }
        out << "\n";

        // Sinh cây
        vector<pair<int, int>> edges;
        if (type == "line") {
            // Shuffle labels để không bị lộ pattern 1-2-3...
            vector<int> p(n);
            iota(p.begin(), p.end(), 1);
            shuffle(p.begin(), p.end(), rng);
            for (int i = 0; i < n - 1; ++i) {
                edges.push_back({p[i], p[i+1]});
            }
        } else if (type == "star") {
             // Đỉnh 1 nối với tất cả, shuffle thứ tự
            vector<int> p(n);
            iota(p.begin(), p.end(), 1);
            shuffle(p.begin(), p.end(), rng); // p[0] là tâm
            for (int i = 1; i < n; ++i) {
                edges.push_back({p[0], p[i]});
            }
        } else { // Random tree
            // Prufer sequence hoặc nối vào node ngẫu nhiên trước đó
            // Cách đơn giản hiệu quả: node i (2..n) nối vào rand(1..i-1)
            // Cần shuffle lại label để tránh cây bị bias về index nhỏ
            vector<int> p(n);
            iota(p.begin(), p.end(), 1);
            shuffle(p.begin(), p.end(), rng);
            
            for (int i = 1; i < n; ++i) {
                int u = p[i];
                int v = p[randInt(0, i - 1)];
                edges.push_back({u, v});
            }
        }

        // Shuffle thứ tự cạnh
        shuffle(edges.begin(), edges.end(), rng);
        for (auto &edge : edges) {
            out << edge.first << " " << edge.second << "\n";
        }
    }
    out.close();
}

int main() {
    cout << "Bat dau sinh " << NUM_TESTS << " test..." << endl;

    for (int i = 1; i <= NUM_TESTS; ++i) {
        // 1. Tạo tên thư mục test01, test02...
        string id_str = (i < 10 ? "0" : "") + to_string(i);
        string dir_name = "test" + id_str;
        makeDir(dir_name);

        string inp_file = dir_name + "/" + PROBLEM_NAME + ".inp";
        string out_file = dir_name + "/" + PROBLEM_NAME + ".out";

        // 2. Sinh Input
        generate_input(i, inp_file);

        // 3. Sinh Output bằng Solver
        ifstream in(inp_file);
        ofstream out(out_file);
        
        int t;
        if (in >> t) {
            while(t--) {
                Solver::solve(in, out);
            }
        }
        
        in.close();
        out.close();

        cout << "Generated: " << dir_name << endl;
    }

    cout << "Hoan thanh!" << endl;
    return 0;
}