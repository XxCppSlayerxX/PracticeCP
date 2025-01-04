#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    string s;
    cin >> k >> s;
    int n = s.length();
    int res = 0;
    string ans = s;
    
    if (k == 2) {
        string s1 = s, s2 = s;
        int ops1 = 0, ops2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && s1[i] != '1') {
                s1[i] = '1';
                ops1++;
            }
            if (i % 2 == 1 && s1[i] != '0') {
                s1[i] = '0';
                ops1++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && s2[i] != '0') {
                s2[i] = '0';
                ops2++;
            }
            if (i % 2 == 1 && s2[i] != '1') {
                s2[i] = '1';
                ops2++;
            }
        }
        
        if (ops1 <= ops2) {
            res = ops1;
            ans = s1;
        } else {
            res = ops2;
            ans = s2;
        }
    } else {
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            int len = j - i;
            
            if (len >= k) {
                if (len % k == 0) {
                    for (int pos = i + k - 2; pos < j; pos += k) {
                        ans[pos] = (s[i] == '0' ? '1' : '0');
                        res++;
                    }
                } else {
                    for (int pos = i + k - 1; pos < j; pos += k) {
                        ans[pos] = (s[i] == '0' ? '1' : '0');
                        res++;
                    }
                }
            }
            i = j;
        }
    }
    
    cout << res << " " << ans << endl;
    return 0;
}