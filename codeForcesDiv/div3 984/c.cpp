#include <bits/stdc++.h>
using namespace std;

bool is1100(const string &s, int pos) {
    return s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        int count = 0;
        for (int i = 0; i <= n - 4; ++i) {
            if (is1100(s, i)) {
                ++count;
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int i, v;
            cin >> i >> v;
            --i; 
            for (int j = i - 3; j <= i; ++j) {
                if (j >= 0 && j <= n - 4 && is1100(s, j)) {
                    --count;
                }
            }

            s[i] = v + '0';

            for (int j = i - 3; j <= i; ++j) {
                if (j >= 0 && j <= n - 4 && is1100(s, j)) {
                    ++count;
                }
            }

            cout << (count > 0 ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
