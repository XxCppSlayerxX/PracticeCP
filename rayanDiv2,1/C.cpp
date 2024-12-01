#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;
vector<vector<char>> grid;
int n, m;
vector<vector<int>> state;  

bool find_cycle(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (state[x][y] == 1) return true;
    if (state[x][y] != 0) return state[x][y] == 2;  
    state[x][y] = 1;  
    
    char dir = grid[x][y];
    int nx = x, ny = y;
    
    if (dir == 'U') nx--;
    else if (dir == 'D') nx++;
    else if (dir == 'L') ny--;
    else if (dir == 'R') ny++;
    
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
        state[x][y] = 3;
        return false;
    }
    
    bool leads_to_cycle = find_cycle(nx, ny);
    state[x][y] = leads_to_cycle ? 2 : 3; 
    return leads_to_cycle;
}

int count_trapped() {
    state = vector<vector<int>>(n, vector<int>(m, 0));
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (state[i][j] == 0) {
                find_cycle(i, j);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (state[i][j] == 2) count++;
        }
    }
    return count;
}

void solve() {
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<pair<int,int>> question_marks;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '?') {
                question_marks.push_back({i, j});
            }
        }
    }
    
    int max_trapped = 0;
    string directions = "UDLR";
    
    if (question_marks.empty()) {
        cout << count_trapped() << "\n";
        return;
    }
    
    for (char dir : directions) {
        vector<vector<char>> temp_grid = grid;
        temp_grid[question_marks[0].first][question_marks[0].second] = dir;
        grid = temp_grid;
        
        for (int i = 1; i < question_marks.size(); i++) {
            int max_local = 0;
            char best_dir = 'U';
            
            for (char d : directions) {
                temp_grid[question_marks[i].first][question_marks[i].second] = d;
                grid = temp_grid;
                int trapped = count_trapped();
                if (trapped > max_local) {
                    max_local = trapped;
                    best_dir = d;
                }
            }
            
            temp_grid[question_marks[i].first][question_marks[i].second] = best_dir;
            grid = temp_grid;
        }
        
        max_trapped = max(max_trapped, count_trapped());
    }
    
    cout << max_trapped << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}