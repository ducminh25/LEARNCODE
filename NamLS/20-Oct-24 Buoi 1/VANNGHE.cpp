/*
Lớp 12A do cô Thảo chủ nhiệm có n học sinh, được đánh số từ 1 đến n.
Để chuẩn bị cho buổi biểu diễn văn nghệ của toàn trường, cô Thảo sẽ chọn ra x học sinh để biểu diễn hát đồng ca và y học sinh biểu diễn múa.
Do các em còn bận học văn hóa nên mỗi học sinh sẽ chỉ tham gia vào không quá một nhóm. Sau khi cẩn thận xem từng học sinh biểu diễn tài năng của mình,
cô giáo nhận thấy học sinh thứ i sẽ mang về điểm số ai nếu hát đồng ca, điểm số bi nếu biểu diễn múa (với mọi i = 1 .. n).

Yêu cầu: Hãy giúp cô Thảo chọn ra các học sinh trong lớp như mô tả trên để tổng điểm dự kiến của tất cả học sinh mang về cho lớp là cao nhất.
Dữ liệu vào:
· Dòng đầu chứa số nguyên dương N là số học sinh trong lớp (N <= 10^5);
· Dòng thứ hai chứa 2 số nguyên dương X, Y (X + Y <= N);
· Dòng thứ i trong n dòng tiếp theo mỗi dòng gồm 2 số nguyên ai, bi (0 <= ai, bi, <= 10^9 với mọi i = 1 .. N).
Kết quả: một số nguyên duy nhất là tổng số điểm tối đa mà cả lớp có thể có được.

Ví dụ:
INPUT:
6
3 2
4 0
3 3
6 8
5 9
6 0
4 8

OUTPUT: 33
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> diff(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        diff[i] = {b - a, i};
    }

    sort(diff.rbegin(), diff.rend());

    vector<bool> chosen(n, false);
    long long total = 0;

    // Choose students for dancing
    for (int i = 0; i < y; i++) {
        int idx = diff[i].second;
        chosen[idx] = true;
        total += diff[i].first + diff[i].second;
    }

    // Choose remaining students for singing
    int sing_count = 0;
    for (int i = 0; i < n && sing_count < x; i++) {
        int idx = diff[i].second;
        if (!chosen[idx]) {
            total += diff[i].second;
            sing_count++;
        }
    }

    cout << total << endl;

    return 0;
}