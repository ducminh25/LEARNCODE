#include <bits/stdc++.h>
using namespace std;

int main ()
{
    map <int, int> m;
    m.insert (make_pair (1, 2)); // Thêm key 1 với giá trị 2 vào map
    pair <int, int> p = {3, 4};
    m.insert (p); // Thêm key 3 với giá trị 4 trong map
    m [2] = 4; // Thêm key 2 với giá trị 4 trong map
    m [7] = 6; // Thêm key 7 với giá trị 6 trong map
    m [3] = 5; // Key 3 đã tồn tại, thay value thành 5

    cout << m [3] << endl; // In ra 5

    cout << m [6] << endl; // In ra 0 vì chưa có key 6 trong map

    cout << m.size (); // In ra số key trong map: 5

    cout << m.empty (); // return 0 (False) vì map không rỗng; ngược lại sẽ in ra 1 (True)

    map <int, int> ::iterator it; 
    it = m.begin (); // iterator tham chiếu đến phần đầu trong map

    cout << (*it).first << endl; // In ra key đầu trong map: 1

    cout << it->second << endl; // In ra value đầu trong map: 2

    m.erase (2); // Xóa key 2 trong map (xoá cả value)
    // Lúc này, map còn (1, 2), (3, 5), (6, 0), (7, 6)

    if (m.find (2) == m.end ()) // Kiểm tra xem key 2 có trong map không
        cout << "No" << endl;
    else cout << "Yes" << endl; // In ra No vì key 2 không có trong map

    it = m.lower_bound (3); // con trỏ đang chỉ đến key 3, value tương ứng là 5
    cout << it->second << endl; // In ra value 5
    it = m.upper_bound (3); // con trỏ đang trỏ tới key 6, value tương ứng là 0
    cout << it->first << endl; // In ra key 6
}