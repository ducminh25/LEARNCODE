#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n; 
    int S;
    cin >> n >> S;
    int cows[n+2];
    int tongdanbo = 0;
    for (int i = 0; i < n + 2; i++)
    {
        cin >> cows[i];
        tongdanbo += cows[i];
    }
    int con1, con2;
    for (int i = 0; i < n + 2; i++)
    {
        for (int j = i + 1; j < n + 2; j++)
        {
            if (tongdanbo - cows[i] - cows[j] == S)
            {
                cows[i] = con1;
                cows[j] = con2;
                break;
            }
        }
    }
    for (int i = 0; i < n + 2; i++)
    {
        if ((cows[i] != con1) && (cows[i] != con2))
        {
            cout << cows[i] << endl;
        }
    }
    return 0;
}