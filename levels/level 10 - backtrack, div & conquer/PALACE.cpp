#include <bits/stdc++.h>
using namespace std;
int n, s=0, minn=1000000, a[17][17];
bool c[100], cheo1[100], cheo2[100];

void vet(int i) {
    for (int j=1; j<=n; j++) {
        if (c[j]==true && cheo1[i-j+(n-1)]==true && cheo2[i+j]==true) {
            c[j]=false;
            cheo1[i-j+(n-1)]=false;
            cheo2[i+j]=false;
            s += a[i][j];
            if (i==n || s>minn) {
                if (s<minn) minn=s;
            }
            else vet(i+1);
            s -= a[i][j];
            c[j]=true;
            cheo1[i-j+(n-1)]=true;
            cheo2[i+j]=true;
        }
    }
}

void nhap() {
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> a[i][j];
}

void xuli() {
    for (int i=0; i<=2*n; i++) {
        cheo2[i]=true;
        cheo1[i]=true;
    }
    for (int i=1; i<=n; i++) c[i]=true;
    vet(1);
    cout << minn;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    nhap();
    xuli();

    return 0;
}


/*
PALACE Cung điện
Ở vương quốc nọ, có một vị vua và ông có N quý phi. 
Trên miếng đất hình vuông kích thước N*N, nhà vua muốn xây dựng cho mỗi quý phi, mỗi người một cung điện (giả sử mỗi cung điện đều nằm trên 1 ô đất kích thước 1*1). 
Vấn đề là các quý phi này có tính ghen ghét nhau nên nhà vua không muốn các cung điện nhìn thấy nhau từ các hướng (ngang, dọc, chéo).
Chi phí xây dựng các cung điện trên mỗi ô đất có thể có giá thành khác nhau, nhà vua muốn xây dựng N cung điện với tổng chi phí thấp nhất.
Yêu cầu: Bạn hãy giúp nhà vua thực hiện công việc đó.
Input: gồm n+1 dòng
· Dòng đầu chứa số N (1 <= N <= 16)
· N dòng sau, mỗi dòng chứa N số là chi phí xây dựng lại ô đất tương ứng (chi phí xây dựng cung điện trong một ô có giá trị nguyên từ 1 đến 1000). 
Mỗi số cách nhau ít nhất một khoảng trắng.
Output: gồm 1 số duy nhất cho biết tổng chi phí thấp nhất cho việc xây dựng. Giả sử dữ liệu đã cho luôn có lời giải.
*/