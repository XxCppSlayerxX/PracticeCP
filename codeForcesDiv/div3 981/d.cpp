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
        vector<int> a(n);
        vector<long long> prefixSum(n + 1, 0); 
        vector<int> lastOccurrence(n + 1, -1);
        map<long long, int> mapa;

        for(long long i = 0; i < n; ++i){
            cin >> a[i];
        }

        mapa[0] = 0;
        
        for(int i = 1; i <= n; ++i){
            prefixSum[i] = prefixSum[i - 1] + a[i - 1]; 
            if(mapa.find(prefixSum[i]) != mapa.end()){
                lastOccurrence[i] = mapa[prefixSum[i]];
            }
            mapa[prefixSum[i]] = i;
        }

        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; ++i){
            dp[i] = max(dp[i], dp[i - 1]);
            if(lastOccurrence[i] != -1){
                dp[i] = max(dp[i], dp[lastOccurrence[i]] + 1);
            }
        }

        cout << dp[n] << endl; 
    }
    return 0;
}
