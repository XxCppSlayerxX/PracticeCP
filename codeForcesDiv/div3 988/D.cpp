#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m, L; cin >> n >> m >> L;
        vector<pair<int, int>> hurdles(n), powerUps(m);
        for (int i = 0; i < n; ++i) {
            cin >> hurdles[i].first >> hurdles[i].second;  // l, r
        }
        for (int i = 0; i < m; ++i) {
            cin >> powerUps[i].first >> powerUps[i].second;  // x, v
        }

        priority_queue<int> bestP;
        int current = 0, res = 0, jumpPower = 1;
        bool flag = false;

        for (int i = 0; i < n; ++i) {
            int l = hurdles[i].first, r = hurdles[i].second;
            if(l >= L){
                break;
            }

            while (current < m && powerUps[current].first < l) {
                bestP.push(powerUps[current].second);
                current++;
            }

            while (jumpPower < r - l + 2) {
                if (bestP.empty()) {
                    flag = true;  
                    break;
                }
                jumpPower += bestP.top();
                bestP.pop();
                res++;
            }
            if (flag){
                break;
            } 

            jumpPower -= (r - l);
        }

        if (!flag) {
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }

    }
    return 0;
}