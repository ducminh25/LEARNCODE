#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(const string &s) {
    string result;
    for (char ch : s) {
        if (result.empty() || result.back() != ch) {
            result.push_back(ch);
        }
    }
    return result;
}

int main() 
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    // freopen ("Xoatrung.INP", "r", stdin);
    // freopen ("Xoatrung.OUT", "w", stdout);
    string input;
    getline (cin, input);
    string output = removeDuplicates(input);
    cout << output << endl;
    return 0;
}

/*
Viết chương trình xóa các ký tự liên tiếp giống nhau trong một xâu cho trước chỉ chứa lại 1 ký tự. Dữ liệu vào: Tệp văn bản ‘XOATRUNG.INP’ chứa một xâu ký tự không quá 500 ký tự Dữ liệu ra: Tệp văn bản ‘XOATRUNG.OUT’ chứa xâu sau khi xóa các ký tự trùng.
tttthhhhppt hamrrroong --> thpt hamrong
*/