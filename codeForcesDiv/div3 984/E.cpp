#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

// Function to find the valid range [start, end] for a requirement
void findValidRange(const vector<pair<int, ll>>& bi_r_list, char o, ll c, int n, int& start, int& end) {
    int len = bi_r_list.size();

    if (o == '<') {
        // Initialize start and end
        start = 1;
        end = n;

        // If the first cumulative OR is >= c, the condition is never satisfied
        if (bi_r_list[0].second >= c) {
            end = 0; // Invalid range
            return;
        }

        // Find the earliest position where bi_r >= c
        for (int p = 1; p < len; ++p) {
            if (bi_r_list[p].second >= c) {
                end = bi_r_list[p].first - 1;
                return;
            }
        }
        // If cumulative OR never reaches >= c, condition holds till the end
        end = n;
    } else { // o == '>'
        // Initialize start and end
        start = n + 1;
        end = n;

        // Find the first position where bi_r > c
        for (int p = 0; p < len; ++p) {
            if (bi_r_list[p].second > c) {
                start = bi_r_list[p].first;
                return;
            }
        }
        // If cumulative OR never exceeds c, condition is never satisfied
        start = n + 1; // Invalid range
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<pair<int, ll>>> bi_r_list(k + 1); // bi_r_list[r] stores (position, cumulative OR) for region r
    vector<ll> bi_r_prev(k + 1, 0); // Stores previous cumulative OR for each region

    // Read input and compute cumulative ORs
    for (int i = 1; i <= n; ++i) {
        for (int r = 1; r <= k; ++r) {
            ll ai_r;
            cin >> ai_r;
            ll bi_r = bi_r_prev[r] | ai_r; // Compute cumulative OR
            if (i == 1 || bi_r != bi_r_prev[r]) {
                // Store the position and new cumulative OR if it changes
                bi_r_list[r].emplace_back(i, bi_r);
                bi_r_prev[r] = bi_r;
            }
        }
    }

    // Process queries
    for (int qi = 0; qi < q; ++qi) {
        int m;
        cin >> m;
        int max_start = 1;
        int min_end = n;
        bool possible = true;
        for (int mi = 0; mi < m; ++mi) {
            int r;
            string o_str;
            ll c;
            cin >> r >> o_str >> c;
            char o = o_str[0]; // Get the operator

            int start = 1;
            int end = n;
            findValidRange(bi_r_list[r], o, c, n, start, end);

            if (start > end) {
                possible = false; // No valid range for this requirement
                break;
            } else {
                max_start = max(max_start, start);
                min_end = min(min_end, end);
            }
        }
        if (possible && max_start <= min_end)
            cout << max_start << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}
