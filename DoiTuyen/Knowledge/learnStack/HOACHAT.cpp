#include <bits/stdc++.h>
using namespace std;

int tinhKL(const string &hchat) {
    unordered_map <char, int> klg = {{'C', 12}, {'H', 1}, {'O', 16}};
    stack<int> st;

    for (int i = 0; i < hchat.length(); ++i) 
    {
        if (hchat[i] == '(') {
            st.push(-1);
        } else if (hchat[i] == ')') 
        {
            int temp = 0;
            while (st.top() != -1) {
                temp += st.top();
                st.pop();
            }
            st.pop(); // bỏ đánh dấu
            if (i + 1 < hchat.length() && isdigit(hchat[i + 1])) {
                temp *= hchat[++i] - '0';
            }
            st.push(temp);
        } else if (isdigit(hchat[i])) {
            int top = st.top();
            st.pop();
            st.push(top * (hchat[i] - '0'));
        } else {
            st.push(klg[hchat[i]]);
        }
    }

    int totalMass = 0;
    while (!st.empty()) {
        totalMass += st.top();
        st.pop();
    }

    return totalMass;
}

int main() 
{
    string hoachat;
    getline(cin, hoachat);
    cout << tinhKL(hoachat);
    return 0;
}