/**
 * @brief Calculates the maximum area of a rectangle in a histogram
 * @param heights The histogram data
 * @return The maximum area of a rectangle in the histogram
 * @authors NamLS
 */
#include <bits/stdc++.h>
using namespace std;

long long maxArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> s;
    long long maxArea = 0;

    // Iterate through the histogram, and for each bar, keep track of the maximum area
    // that can be formed with that bar as the rightmost bar
    for (int i = 0; i <= n; i++) {
        int h;
        if (i == n) h = 0;
        else h = heights[i];
        while (!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width;
            if (s.empty()) width = i;
            else width = i - s.top() - 1;
            // Update the maximum area with the area of the rectangle with the current bar as the rightmost bar
            maxArea = max(maxArea, (long long)height * width);
        }
        s.push(i);
    }

    return maxArea;
}

/**
 * @brief Finds the maximum area of a rectangle in a histogram with colors
 * @param m The number of rows in the histogram
 * @param n The number of columns in the histogram
 * @return The maximum area of a rectangle in the histogram
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    if(fopen("Rectangle.inp", "r")) {
        freopen("Rectangle.inp", "r", stdin);
        freopen("Rectangle.out", "w", stdout);
    }

    int m, n;
    cin >> m >> n;

    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    long long red = maxArea(h);
    
    for (int i = 0; i < n; ++i)
        // Chuyển sang phần trắng
        h[i] = m - h[i];
    
    long long white = maxArea(h);
    cout << max(red, white) << endl;

    return 0;
}
