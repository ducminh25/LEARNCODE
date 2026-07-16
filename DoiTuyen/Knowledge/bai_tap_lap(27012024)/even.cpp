//Cho số nguyên dương n. Em hãy in ra các số nguyên dương chẵn nhỏ hơn hoặc bằng n.
//Input: - một dòng duy nhất chứa số nguyên dương n.
//Output: - một dòng chứa các số nguyên dương chẵn <= n.
#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    for (int i = 2; i <= n; i+=2)
    {
        cout<<i<<" ";
    }
    return 0;
}
