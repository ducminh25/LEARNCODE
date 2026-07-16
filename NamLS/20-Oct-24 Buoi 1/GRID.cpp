#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("GRID.INP", "r")) {
        freopen("GRID.INP", "r", stdin);
        freopen("GRID.OUT", "w", stdout);
    }

    int N;
    cin >> N;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '.') {
                bool check = true;

                // ktra cell ở dưới
                for (int k = i + 1; k < N; k++) {
                    if (grid[k][j] == 'S') {
                        check = false;
                        break;
                    }
                }

                // ktra cell phải
                if (check) {
                    for (int k = j + 1; k < N; k++) {
                        if (grid[i][k] == 'S') {
                            check = false;
                            break;
                        }
                    }
                }

                if (check)
                    cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}

/*
Sân nhà Hà được xem như một lưới ô vuông có N hàng đánh số từ 1 đến N từ trên xuống
dưới và N cột đánh số từ 1 đến N từ trái sang phải. Ô ở hàng i, cột j (i, j = 1 .. N) gọi là ô (i,j). Mỗi
ô có thể đang bỏ trống hoặc bị đặt một viên đá (vừa đủ chiếm trọn ô). Hà muốn đặt một thanh gỗ
với góc nghiêng 45 độ so với cạnh ngang của lưới vào một ô (i,j) đang trống, sao cho khi đứng ở
phía nam của sân, tại cột j, Hà đá một quả bóng thẳng theo hướng nam - bắc, bóng chạm được vào
thanh gỗ rồi phản xạ đi thằng theo hướng tây - đông và đi ra được phía đông của sân (như hình
dưới, ô tô đậm là ô có đá). Tất nhiên, bóng chỉ lăn được qua những ô trống và dừng lại khi gặp
một ô có đá.

Phía đông

Phía nam của sân
Yêu cầu: Đếm số ô trong sân nhà Hà có thể đặt được thanh gỗ như mô tả ở trên.
Dữ liệu: Vào từ file GRID.INP gồm:
· Dòng đầu là số nguyên dương N (N <= 1000);
· Dòng thứ i trong N dòng tiếp theo chứa một xâu kí tự độ dài N, kí tự thứ j bằng '.' có nghĩa
là ô (i,j) là ô trống, còn bằng 'S' là ô có đá.
Kết quả: Ghi ra file văn bản GRID.OUT gồm một số nguyên là kết quả tìm được.

4
. S . .
. . . S
. . . .
. . S .

--> 4
*/