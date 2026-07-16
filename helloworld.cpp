#include <bits/stdc++.h>
using namespace std;
int a[1003];
int main ()
{
	for (int i = 0; i < 5; i++) cin >> a[i];
	for (int i = 1; i < 5; i++)
	{
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
	for (int i = 0; i < 5; i++) cout << a[i] << ' ';
}


/*

*/