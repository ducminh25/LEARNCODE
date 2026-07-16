#include <bits/stdc++.h>
using namespace std;
int a[20], b[20], x[20], n;
long long tong, tich, minn;

void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
}

void vet(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        tong = tong + j * b[i];
        if (j == 1) tich = tich * a[i];
        if (i == n) {
            if (abs(tong - tich) < minn && tong > 0)
                minn = abs(tong - tich);
        } else vet(i + 1);
        tong = tong - j * b[i];
        if (j == 1) tich = tich / a[i];
    }
}

void giai() {
    minn = 1000000000;
    tong = 0; tich = 1;
    vet(1);
    cout << minn;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("GIAVI.INP", "r")) {
        freopen("GIAVI.INP", "r", stdin);
        freopen("GIAVI.OUT", "w", stdout);
    }
    
    nhap();
    giai();

    return 0;
}



/*
Bài 5. GIAVI Gia vị
Tại một nhà hàng truyền thống của Ấn Độ, đầu bếp đang phân vân trong việc chọn gia vị cho
món ăn của mình. Nhà hàng này rất nổi tiếng bởi bí quyết gia vị của họ, đặc biệt là vị chua và vị
cay. Các món ăn của họ có vị chua và cay xen lẫn nhau rất đặc biệt.
Hiện tại đang có tất cả N loại gia vị. Mỗi loại có độ chua Si và độ cay Bi đặc chưng. Khi trộn
K loại gia vị vào món ăn, độ chua của món ăn sẽ bằng tích độ chua của K loại gia vị, trong khi đó
độ cay sẽ bằng tổng độ cay của K loại gia vị.
Để cho món ăn được hấp dẫn và hài hòa, đầu bếp sẽ chọn các loại gia vị sao cho sự chênh
lệch giữa độ chua và độ cay của món ăn là nhỏ nhất.
Dĩ nhiên, cần phải chọn ít nhất một loại gia vị cho món ăn. Các bạn hãy giúp đầu bếp thực
hiện công việc này.
Input
· Dòng đầu tiên là số thành phần gia vị N (1 N ≤ 10).
· N dòng tiếp theo, mỗi dòng gồm 2 số Si, Bi mô tả đặc trưng vị chua và vị cay của gia vị đó.
Input được đảm bảo rằng nếu trộn tất cả các loại gia vị, thì độ cay và độ chua của món ăn sẽ nhỏ
hơn 109.
Output: In ra sự chênh lệch nhỏ nhất giữa vị chua và vị cay của món ăn.
*/