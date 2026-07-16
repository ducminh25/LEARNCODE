#include <bits/stdc++.h>
using namespace std;

void enter (int n, vector<int> a) {
    cin >> n;

    a.resize (n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a [i];
    }
}

// Truy vết tìm ra độ dài của dãy con tăng dài nhất
// và tìm ra dãy con tăng dài nhất
void trace_back (int n, vector<int> a, vector<int> dp, vector<int> trace) {
    // Tìm ra best_pos, nơi dp lớn nhất
    int best_pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp [i] > dp [best_pos]) best_pos = i;
    }
    cout << dp [best_pos] << endl;
    
    vector<int> list_elements;
    while (best_pos) {
        list_elements.push_back (a [best_pos]);
        best_pos = trace [best_pos];
    }

    for (int i = 1; i < list_elements.size (); ++i) {
        cout << list_elements [i] << ' ';
    }
}

// Sử dụng công thức truy hồi để tính bảng phương án
void sol (int n, vector<int> a) {
    vector<int> dp (n + 1), trace (n + 1);

    for (int i = 1; i <= n; ++i) {
        // Chọn vị trí jmax tốt nhất để nối a [i] vào sau
        int jmax = 0;
        for (int j = 1; j < i; ++j) 
            if (dp [j] > dp [jmax] && a [j] < a [i]) 
                jmax = j;
        dp [i] = dp [jmax] + 1; // Update dp[i]
        trace [i] = jmax; // Lưu phần tử đứng trước a[i] là a[jmax].
        }

    trace_back (n, a, dp, trace);
}

int main () {
    int n;
    vector<int> a;

    enter (n, a);
    sol (n, a);

    return 0;
}