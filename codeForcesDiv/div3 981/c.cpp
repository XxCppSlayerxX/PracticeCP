#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;  
    
    while (t--) {
        int n;
        cin >> n; 
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];  
        }


        for(int i = 1; i < n / 2; ++i){
            if(a[i - 1] == a[i] || a[n - i] == a[n - i - 1]){
                swap(a[i], a[n - i - 1]);
            }
        }

        int disturbance = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                disturbance++;
            }
        }

        if (disturbance == 0) {
            cout << 0 << endl;
            continue;
        }

        cout << disturbance << endl;
    }

    return 0;
}
