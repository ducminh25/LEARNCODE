#include <bits/stdc++.h>
using namespace std;
int main ()
{
    deque <int> dq;
    for (int i = 1; i <= 5; ++i)
    {
        dq.push_back(i);
    }

    dq.push_front(7); // dq = {7, 1, 2, 3, 4, 5}

    cout << dq.size (); // 6

    cout << dq.back (); // 5

    cout << dq [4]; // 4
}