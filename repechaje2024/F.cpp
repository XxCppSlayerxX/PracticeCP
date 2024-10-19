#include "bits/stdc++.h"
using namespace std;

int main() {
    unordered_map<int, int> a;
    for (int i = 0; i < 5; ++i) {
        int temp;
        cin >> temp;
        a[temp] = i;
    }

    vector<int> b(4);
    
    for (int i = 0; i < 4; ++i) {
        int temp;
        cin >> temp;
        if (a.find(temp) != a.end()) {
            a.erase(temp);  
        }
    }

    for (const auto& pair : a) {
        cout << pair.first << "\n";
    }

    return 0;
}
