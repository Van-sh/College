#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src)
{
   vector<int> dist(V, INT_MAX);
   dist[src] = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, src});

   while (!pq.empty())
   {
      int u = pq.top().second;
      pq.pop();
      for (auto [v, w] : adj[u])
      {
         if (dist[u] + w < dist[v])
         {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
         }
      }
   }

   cout << "Dijkstra's Shortest Distances:\n";
   for (int i = 0; i < V; i++)
      cout << i << " : " << dist[i] << endl;
}

void bellmanFord(int V, vector<vector<int>> &edges, int src)
{
   vector<int> dist(V, INT_MAX);
   dist[src] = 0;

   for (int i = 0; i < V - 1; i++)
      for (auto e : edges)
         if (dist[e[0]] != INT_MAX && dist[e[0]] + e[2] < dist[e[1]])
            dist[e[1]] = dist[e[0]] + e[2];

   cout << "Bellman-Ford Shortest Distances:\n";
   for (int i = 0; i < V; i++)
      cout << i << " : " << dist[i] << endl;
}

int main()
{
   int V = 5;
   vector<vector<pair<int, int>>> adj(V);
   adj[0] = {{1, 2}, {2, 4}};
   adj[1] = {{2, 1}, {3, 7}};
   adj[2] = {{4, 3}};
   adj[3] = {{4, 1}};

   dijkstra(V, adj, 0);
   vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 4, 3}, {3, 4, 1}};

   bellmanFord(V, edges, 0);
   return 0;
}
