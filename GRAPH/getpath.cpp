
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool dfs(int start, int end, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &ans)
{
    if (start == end)
    {
        ans.push_back(start);
        return true;
    }
    visited[start] = true;
    ans.push_back(start);

    for (int i = 0; i < adj[start].size(); i++)
    {
        if (!visited[adj[start][i]])
        {
            if (dfs(adj[start][i], end, adj, visited, ans))
                return true;
        }
    }

    ans.pop_back();
    return false;
}

vector<int> getPath(int V, int E, vector<int> a, vector<int> b, int v1, int v2)
{
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < a.size(); i++)
    {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    vector<bool> visited(V, false);
    vector<int> ans;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(v1, v2, adj, visited, ans))
                break;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    return 0;
}