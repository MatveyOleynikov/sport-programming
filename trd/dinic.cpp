struct Dinic {
    int n; vector<vector<pair<pii, pii>>> c; // kolichestvo vershin i graph
    int s, t; //nachalo i konec
    void add_edge(int u, int v, int w) {
        c[u].push_back({ {v, w}, {c[v].size(), 0} });
        c[v].push_back({ {u, 0}, {c[u].size() - 1, 0} });
    }
    bool bfs(vi& d) {
        queue<int> q; q.push(s); d[s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto& edge : c[v]) {
                int to = edge.first.first;
                if (d[to] == -1 && edge.second.second < edge.first.second) {
                    q.push(to); d[to] = d[v] + 1;
                }}} // 3 skobki
        return d[t] != -1;}
    int dfs(int v, int flow, vi& d) {
        if (!flow) return 0; if (v == t) return flow;
        for (auto& edge : c[v]) {
            int to = edge.first.first;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, edge.first.second - edge.second.second), d);
            if (pushed) {
                edge.second.second += pushed;
                c[to][edge.second.first].second.second -= pushed;
                return pushed;}}
        return 0;}
    int potok() { int flow = 0;
    while (1) { vi d(n, -1);  if (!bfs(d)) break;
            while (int pushed = dfs(s, inf, d)) flow += pushed; }
        return flow;}};