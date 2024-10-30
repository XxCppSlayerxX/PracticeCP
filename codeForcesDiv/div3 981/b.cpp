#include "bits/stdc++.h"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int m = n;
        vector<vector<int>> a(n, vector<int> (m));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        int res = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; j++){
                if(a[i][j] < 0){
                    int increment = -a[i][j];  
                    res += increment;          
                    int ti = i, tj = j;
                    while(ti < n && tj < m){
                        a[ti][tj] += increment;
                        ti++;
                        tj++;
                    }
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
