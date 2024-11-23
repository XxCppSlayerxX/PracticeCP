#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> seq;
        
        for(int i = 1; i <= n; i++) {
            int candidate = (seq.empty() ? 1 : seq.back() + 1);
            
            while(candidate <= 100) {
                bool valid = true;
                
                
                for(int j = 0; j < seq.size(); j++) {
                    if((candidate % i) == (seq[j] % (j + 1))) {
                        valid = false;
                        break;
                    }
                }
                
                if(valid) {
                    seq.push_back(candidate);
                    break;
                }
                candidate++;
            }
        }
        
        for(int i = 0; i < seq.size(); i++) {
            cout << seq[i];
            if(i < seq.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}