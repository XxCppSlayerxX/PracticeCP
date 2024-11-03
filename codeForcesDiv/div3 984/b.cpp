#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        map<int, vector<int>> bottles; // (brand, list of costs)
        
        for(int i = 0; i < k; ++i){
            int b, c;
            cin >> b >> c;
            bottles[b].push_back(c);
        }
        
        vector<int> total;
        for(auto &pair : bottles){
            sort(pair.second.rbegin(), pair.second.rend());
            int brand_total = 0;
            for(int cost : pair.second) {
                brand_total += cost;
            }
            total.push_back(brand_total);
        }
        
        sort(total.rbegin(), total.rend());
        
        int res = 0;
        for(int i = 0; i < n && i < total.size(); ++i){
            res += total[i];
        }
        
        cout << res << endl;
    }
    return 0;
}
