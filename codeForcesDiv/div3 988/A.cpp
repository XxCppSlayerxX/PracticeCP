#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int res = 0;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(a[i] == a[j] && a[i] != 501 && a[j] != 501){
                    a[i] = 501;
                    a[j] = 501;
                    res++;
                    break;
                }
            }
        }
        cout << res << endl;
        
    }

    

    return 0;
}