#include "bits/stdc++.h"
using namespace std;

struct edge {
    int to;
    int weight;
};

const long long INF = LLONG_MAX;

vector<long long> dijkstra(int start, int skip, const vector<vector<edge>>& graph) {
    int n = graph.size();
    vector<long long> dist(n, INF); 
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (const edge& e : graph[u]) {
            if (e.to == skip) continue; 
            long long new_dist = dist[u] + e.weight;
            if (new_dist < dist[e.to]) {
                dist[e.to] = new_dist;
                pq.push({new_dist, e.to});
            }
        }
    }
    return dist;  
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // n = nodes, m = edges
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> graph(n + 1);
    // p = Pedrot, g = destination
    int p, g;
    cin >> p >> g;

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    vector<long long> dist_from_P = dijkstra(p, -1, graph);  
    vector<long long> dist_without_G = dijkstra(p, g, graph);  // Dijkstra from P, but skipping G
    long long dist_P_to_G = dist_from_P[g];  
    vector<int> res;

    for (int i = 1; i <= n; ++i) {
        if (i == g) continue; 

        //if dist(P, V) == 2 * dist(P, G) and dist(P, V without G) > dist(P, V)
        if (dist_from_P[i] == 2 * dist_P_to_G && dist_without_G[i] > dist_from_P[i]) {
            res.push_back(i);  
        }
    }

    sort(res.begin(), res.end());

    if (res.empty()) {
        cout << "*";
    } else {
        for (auto elem : res) {
            cout << elem << " ";
        }
    }
    cout << endl;

    return 0;
}
