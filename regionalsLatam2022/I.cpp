#include "bits/stdc++.h"
using namespace std;

int bfs(vector<vector<pair<int, bool>>> dishes, pair<int, int> start){
    int n = dishes.size();
    int m = dishes[0].size();
    vector<pair<int, int>> move = {{1,0}, {-1,0}, {0,-1}, {0,1}};
    queue<pair<int, int>> q;
    int res = 0;

    q.push(start);
    //cout << "visited " << start.first << " " << start.second << endl;


    while(!q.empty()){
        int currentRow = q.front().first;
        int currentCol = q.front().second;
        q.pop();
        res++;
        int currentVal = dishes[currentRow][currentCol].first;
        dishes[currentRow][currentCol].second = true;

        for(int i = 0; i < 4; ++i){
            int newRow = currentRow + move[i].first;
            int newCol = currentCol + move[i].second;

            if(0 <= newRow && newRow < n && 0 <= newCol && newCol < m && dishes[newRow][newCol].second != true && currentVal < dishes[newRow][newCol].first){
                q.push({newRow, newCol});
                dishes[newRow][newCol].second = true;
                //cout << "visited " << newRow << " " << newCol << endl;
            }
        }
    }
    //cout << "mande " << res << " con " << start.first << " " << start.second<<endl<<endl;
    return res;
}

int main (){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, bool>>> dishes(n, vector<pair<int,bool>>(m, {0, false}));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            cin >> dishes[i][j].first;

        }
    }

    int res = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            res = max(bfs(dishes, {i, j}), res);
        }
    }
    cout << res << endl;

    return 0;
}