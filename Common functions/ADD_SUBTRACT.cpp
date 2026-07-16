#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;

// Cân bằng hai số a và b bằng cách thêm các số 0 vào đầu
void balance (string &a, string &b) {
    while (a.size() < b.size()) a = '0' + a;
    while (b.size() < a.size()) b = '0' + b;
}

// Phép cộng với hai số cực lớn
string Add(const string &a, const string &b) {
    string res;
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    
    while(i >= 0 || j >= 0){
        int x = carry;
        if(i >= 0){
            x += a[i] - 48;
            i--;
        }
        if(j >= 0){
            x += b[j] - 48;
            j--;
        }
        carry = x / 10;
        x %= 10;
        res.push_back(x + 48);
    }
    if(carry != 0){
        res.push_back(carry + 48);
    }
    reverse(res.begin(), res.end());
    return res;
}

// Hàm so sánh hai số nguyên lớn dưới dạng string
int compare (string a, string b) {
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

// Phép trừ với hai số cực lớn
string subtract(string &a, string &b) {
    // Xác định dấu của kết quả
    bool negative = false;
    if (compare(a, b) < 0) {
        swap(a, b);
        negative = true;
    }

    string res = "";
    int carry = 0;

    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;
        int digitB = (j >= 0) ? b[j] - '0' : 0;

        int diff = digitA - digitB - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } 
        else
            carry = 0;

        res.push_back(diff + '0');
    }

    // Xóa các số 0 ở đầu kết quả
    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }

    reverse(res.begin(), res.end());

    if (negative && res != "0") {
        res.insert(res.begin(), '-');
    }

    return res;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    balance (a, b);
    c = Add (a, b);
    d = subtract(a, b);
    cout << c << endl;
    cout << d << endl;
    return 0;
}

/*
123456789012345678901234567890123
987654321098765432109876543210987

==> 1111111110111111111011111111101110
-864197532086419753208641975320864
*/