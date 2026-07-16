#include <iostream>
#include <string>
using namespace std;
string kiemtraNgoac(string s) 
{ 
    int balance = 0;
    
    for(char c : s) {
        if(c == '(') {
            balance++;
        } else if(c == ')') {
            balance--;
        } else {
            return "KHONG HOP LE";
            break;
        }
    }
    if (balance =! 0) {
        return "KHONG HOP LE";
       }
       else return "HOP LE";
}

int main() {
    string s;
    getline (cin, s);
    cout << kiemtraNgoac(s) << endl;
    return 0;
}