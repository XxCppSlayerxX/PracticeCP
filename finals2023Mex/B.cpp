#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n * 3);

    for(int i = 0; i < n * 3; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    bool carlLoses = true;

    for(int i = 0; i < n * 3 - 2; i = i + 3){
        if(a[i] == a[i + 1] &&  a[i] == a[i + 2]){
            continue;
        }else{
            carlLoses = false;
            break;
        }
    } 

    if(carlLoses){
        cout << 'N' << endl;
    }else{
        cout << 'Y' << endl;
    }

    return 0;
}