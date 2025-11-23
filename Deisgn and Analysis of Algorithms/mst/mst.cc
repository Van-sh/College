#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge
{
   int u, v, w;
   bool operator<(Edge const &other)
   {
      return w < other.w;
   }
};

int find(vector<int> &parent, int i)
{
   if (parent[i] == i)
      return i;
   return parent[i] = find(parent, parent[i]);
}

void unite(vector<int> &parent, vector<int> &rank, int u, int v)
{
   u = find(parent, u);
   v = find(parent, v);
   if (u != v)
   {
      if (rank[u] < rank[v])
         parent[u] = v;
      else if (rank[u] > rank[v])
         parent[v] = u;
      else
         parent[v] = u, rank[u]++;
   }
}

void kruskalMST(vector<Edge> &edges, int V)
{
   sort(edges.begin(), edges.end());
   vector<int> parent(V), rank(V, 0);
   for (int i = 0; i < V; i++)
      parent[i] = i;
   int cost = 0;
   cout << "Edges in MST (Kruskal):\n";
   for (auto &e : edges)
   {
      if (find(parent, e.u) != find(parent, e.v))
      {
         cost += e.w;
         cout << e.u << " - " << e.v << " : " << e.w << endl;
         unite(parent, rank, e.u, e.v);
      }
   }
   cout << "Total cost: " << cost << endl;
}

void primMST(vector<vector<int>> &graph, int V)
{
   vector<int> key(V, INT_MAX), parent(V, -1);
   vector<bool> inMST(V, false);
   key[0] = 0;
   for (int count = 0; count < V - 1; count++)
   {
      int u = -1;
      for (int i = 0; i < V; i++)
         if (!inMST[i] && (u == -1 || key[i] < key[u]))
            u = i;
      inMST[u] = true;
      for (int v = 0; v < V; v++)
      {
         if (graph[u][v] && !inMST[v] && graph[u][v] < key[v])
         {
            key[v] = graph[u][v];
            parent[v] = u;
         }
      }
   }
   cout << "Edges in MST (Prim):\n";
   for (int i = 1; i < V; i++)
      cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
}

int main()
{
   int V = 4;
   vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
   kruskalMST(edges, V);
   vector<vector<int>> graph = {
       {0, 10, 6, 5},
       {10, 0, 0, 15},
       {6, 0, 0, 4},
       {5, 15, 4, 0}};
   primMST(graph, V);
   return 0;
}
