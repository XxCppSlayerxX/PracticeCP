#include "bits/stdc++.h"
using namespace std;

struct segtree{

    int size;
    vector<long long> sums;

    void init(int n){
        size = 1;
        while(size < n) size *= 2; // so we have a power of 2
        sums.assign(2*size, 0LL); // initialize the sums vector with 0
    }

    void set(int i, int v, int x, int lx, int rx){
        // lx is the left bound of the current node and rx is the right bound of the current node
        cout << "i = " << i << " v = " << v << " x = " << x << " lx = " << lx << " rx = " << rx << endl;
        if(rx - lx == 1){ // if we are at the leaf just assign the val
            sums[x] = v;
            cout << "sums[" << x << "] = " << v << endl;
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2*x+1, lx, m); // go to the left child
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        // calculate the sum of the children
        sums[x] = sums[2*x+1] + sums[2*x+2];
        cout << "sums[" << x << "] = " << sums[x] << " this the parent of " << sums[2*x+1] << " and " << sums[2*x+2] << endl;
    }
    

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    // in this case fn is the sum of the elements in the range [l, r)
    long long fn(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return 0; // if the range is outside the query range
        if(lx >= l && rx <= r) return sums[x]; // if the range is inside the query range 
        
        int m = (lx + rx) / 2;
        long long s1 = fn(l, r, 2*x+1, lx, m);
        long long s2 = fn(l, r, 2*x+2, m, rx);
        return s1 + s2;
    }

    long long fn(int l, int r){
        return fn(l, r, 0, 0, size);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    segtree st;
    st.init(n);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        st.set(i, v);
    }
    for(int i = 0; i < 2*st.size; i++){
        cout << st.sums[i] << " ";
    }

    while(m--){
        int op; cin >> op;
        if(op == 1){
            int i, v; cin >> i >> v;
            st.set(i, v);
        }else{
            int l, r; cin >> l >> r;
            cout << st.fn(l, r) << endl;
        }
    }
    cout << endl;


    return 0;
}