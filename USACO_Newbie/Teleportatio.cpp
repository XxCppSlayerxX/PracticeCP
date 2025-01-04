#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int direct = abs(a - b);                    
    int via_x = abs(a - x) + abs(b - y);        
    int via_y = abs(a - y) + abs(b - x);  
          
    int result = min({direct, via_x, via_y});

    cout << result << endl;

    return 0;
}
