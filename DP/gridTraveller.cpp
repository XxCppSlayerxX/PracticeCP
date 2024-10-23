#include <bits/stdc++.h>
using namespace std;

int gridTraveller(int m, int n, map<pair<int, int>, int>& memo){
    if(m < 1 || n < 1)return 0;
    if(memo.find({m , n}) != memo.end()){
        return memo[{m , n}];
    }
    
    memo[{m - 1, n}] = gridTraveller(m - 1, n, memo);
    memo[{m , n -1}] = gridTraveller(m, n - 1, memo);
    memo[{m , n}] = memo[{m - 1, n}] + memo[{m , n -1}];
    return memo[{m , n}];
}

int main(){
    // problem specifies only move down or left, and given n and m we have to calcultate all the ways of reaching n, m from 0, 0
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> memo = {{{1, 1}, 1}};
    cout << gridTraveller(n , m, memo) << endl;
    return 0;
}