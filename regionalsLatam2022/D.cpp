#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, h, w;
    cin >> n >> h >> w;
    vector<pair<char, char>> rains(n);
    for(int i = 0; i < n; ++i){
        cin >> rains[i].first >> rains[i].second;
    }

    for(pair<int, int> pair : rains){
        if (pair.first == 'Y' || w == 0){
            cout << 'Y' << " ";
            h--; w++;
        }else{
            cout << 'N' << " ";
        }
        if(pair.second == 'Y' || h == 0){
            cout << 'Y' << " ";
            h++; w--;
        }else{
            cout << 'N';
        }
        cout << endl;
    }
    return 0;
}