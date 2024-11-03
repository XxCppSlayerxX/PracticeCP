#include <bits/stdc++.h>
using namespace std;

void traverseLayer(const vector<vector<char>>& grid, int layer, vector<char>& traversal) {
    int n = grid.size();
    int m = grid[0].size();
    int top = layer;
    int bottom = n - layer - 1;
    int left = layer;
    int right = m - layer - 1;

    for (int j = left; j <= right; ++j)
        traversal.push_back(grid[top][j]);

    for (int i = top + 1; i <= bottom; ++i)
        traversal.push_back(grid[i][right]);

    if (top < bottom) {
        for (int j = right - 1; j >= left; --j)
            traversal.push_back(grid[bottom][j]);
    }

    if (left < right) {
        for (int i = bottom - 1; i > top; --i)
            traversal.push_back(grid[i][left]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; 

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                grid[i][j] = s[j];
            }
        }

        int res = 0; 
        int layers = min(n, m) / 2;

        for (int layer = 0; layer < layers; ++layer) {
            vector<char> traversal;
            traverseLayer(grid, layer, traversal);

            int sz = traversal.size();

            traversal.insert(traversal.end(), traversal.begin(), traversal.begin() + 3);

            for (int i = 0; i < sz; ++i) {
                if (traversal[i] == '1' && traversal[i + 1] == '5' &&
                    traversal[i + 2] == '4' && traversal[i + 3] == '3') {
                    res++;
                }
            }
        }

        cout << res << endl; 
    }

    return 0;
}
