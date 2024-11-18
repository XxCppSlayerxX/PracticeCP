#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int sum = 0;
    int currentMin = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        sum += a[i];
        currentMin = min(sum, currentMin);
    }
    if(currentMin >= 0){
        cout << 0 << endl;
        return 0;
    }
    cout << abs(currentMin) << endl;
    return 0;
}