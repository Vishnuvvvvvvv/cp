#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define ll long long

// Floyd-Warshall Algorithm
void floydWarshall(vector<vector<ll>>& dist, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout<<dist[i][j]<<" ";
            }

            cout<<endl;
        }



}

int main() {
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);

    int n, m; // Number of nodes and edges
    cin >> n >> m;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    vector<tuple<int, int, ll>> edges; // Store edges as (u, v, w)

    // Initialize distances
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        dist[u][v] = min(dist[u][v], (ll)w);
        dist[v][u] = min(dist[v][u], (ll)w);
    }

    // Run Floyd-Warshall
    floydWarshall(dist, n);

    ll total_weight = 0;
    set<pair<int, int>> important_edges;

    // Check each edge
    for (auto& edge : edges) {
        int u, v;
        ll w;
        tie(u, v, w) = edge;

        bool is_important = false;

        // Check if edge (u, v) is part of any shortest path
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] == dist[i][u] + w + dist[v][j] ||
                    dist[i][j] == dist[i][v] + w + dist[u][j]) {
                    is_important = true;
                    break; // No need to check further for this pair
                }
            }
           // if (is_important) break; // No need to check further nodes
        }

        if (is_important) {
            important_edges.insert({min(u, v), max(u, v)});
            total_weight += w; // Use the input weight directly
        }
    }

    // Output the total weight of important edges
    cout << total_weight << endl;

   
    


    for(auto edge:important_edges){
        cout<<edge.first<<" "<<edge.second<<endl;
    }


    return 0;
}
