#include "bits/stdc++.h"
using namespace std;

struct node{
    long long seg, pref, suf, sum;
};

struct segtree{

    int size;
    vector<node> values;

    node NEUTRAL = {0, 0, 0, 0};

    node merge(node a, node b){
        return {
            max({a.seg, b.seg, a.suf + b.pref}),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }

    node single(int v){
        if(v > 0) return {v, v, v, v};
        return {0, 0, 0, v};
    }

    void init(int n){
        size = 1;
        while(size < n) size *= 2; // so we have a power of 2
        values.resize(2 * size); // initialize the values vector with 0
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){ 
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if(i < m){
            set(i, v, 2*x+1, lx, m); 
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    node fn(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx) return NEUTRAL; // return neutral element
        if(lx >= l && rx <= r) return values[x]; // if the range is inside the query range 
        
        int m = (lx + rx) / 2;
        node s1 = fn(l, r, 2*x+1, lx, m);
        node s2 = fn(l, r, 2*x+2, m, rx);
        return merge(s1, s2);
    }

    node fn(int l, int r){
        return fn(l, r, 0, 0, size);
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < (int)a.size()){
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }

    void build(vector<int> &a){
        build(a, 0, 0, size);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    st.build(a);
    cout << st.fn(2, 3).seg << endl;
    while(m--){
            int i, v; cin >> i >> v;
            st.set(i, v);
            cout << st.fn(0, n).seg << endl;
        }
    cout << endl;

    return 0;
}
 
