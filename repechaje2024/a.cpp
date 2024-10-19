#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> dictionary(N);

    for (int i = 0; i < N; ++i) {
        cin >> dictionary[i];
        sort(dictionary[i].begin(), dictionary[i].end()); 
    }

    sort(dictionary.begin(), dictionary.end());

    int Q;
    cin >> Q;
    while (Q--) {
        string query;
        cin >> query;
        sort(query.begin(), query.end()); 

        auto it = upper_bound(dictionary.begin(), dictionary.end(), query);
        cout << (it - dictionary.begin()) << endl; 
    }

    return 0;
}
