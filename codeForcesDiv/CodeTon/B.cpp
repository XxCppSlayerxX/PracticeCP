#include <bits/stdc++.h>
using namespace std;

int countDistinctSubstrings(string& str) {
    set<string> distinctSubs;
    int n = str.length();
    
    for(int i = 0; i < n; i++) {
        string sub;
        for(int j = i; j < n; j++) {
            sub += str[j];
            distinctSubs.insert(sub);
        }
    }
    
    return distinctSubs.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        
        bool found = false;
        
       
        for(int i = 0; i < s.length()-1; i++) {
            if(s[i] == s[i+1]) {
                cout << s.substr(i, 2) << "\n";
                found = true;
                break;
            }
        }
        
        if(!found) {
            for(int i = 0; i < s.length()-2; i++) {
                if(s[i] == s[i+1] && s[i+1] == s[i+2]) {
                    cout << s.substr(i, 3) << "\n";
                    found = true;
                    break;
                }
            }
        }
        
        if(!found) {
            for(int i = 0; i < s.length()-3; i++) {
                if(s[i] == s[i+1] && s[i+1] == s[i+2] && s[i+2] == s[i+3]) {
                    cout << s.substr(i, 4) << "\n";
                    found = true;
                    break;
                }
            }
        }
        
        if(!found) {
            for(int i = 0; i < s.length()-1; i++) {
                if(s[i] != s[i+1]) {
                    cout << s.substr(i, 2) << "\n";
                    found = true;
                    break;
                }
            }
        }
        
        if(!found) {
            cout << "-1\n";
        }
    }
    
    return 0;
}