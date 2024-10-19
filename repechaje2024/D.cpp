#include <bits/stdc++.h>
using namespace std;

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Compute the GCD of the entire array
    int overall_gcd = arr[0];
    for (int i = 1; i < n; ++i) {
        overall_gcd = gcd(overall_gcd, arr[i]);
        // If the GCD becomes 1 at any point, print "NO" and exit
        if (overall_gcd == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    // If the GCD of the entire array is greater than 1, print "YES"
    cout << "YES" << endl;
    return 0;
}
