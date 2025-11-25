struct Dinic { // O(n^2 * m), for one W (parsoch): O(sqrt(n) * m + n * n)
    int n; vector<vector<pair<pii, int>>> c; // kolichestvo vershin i graph
    vi skip; int s, t; //nachalo i konec
    void add_edge(int u, int v, int w) {
        c[u].push_back({ {v, w}, (int) c[v].size()});
        c[v].push_back({ {u, w}, (int) c[u].size() - 1 });}
    bool bfs(vi& d) {
        queue<int> q; q.push(s); d[s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto& edge : c[v]) {
                int to = edge.first.first;
                if (d[to] == -1 && edge.first.second > 0) {
                    q.push(to); d[to] = d[v] + 1;
                }}} // 3 skobki
        return d[t] != -1;}
    int dfs(int v, int flow, vi& d) {
        if (!flow) return 0; if (v == t) return flow;
        for (; skip[v] < c[v].size(); ++skip[v]){
            auto& edge = c[v][skip[v]];
            int to = edge.first.first;
            if (d[to] != d[v] + 1) continue;
            int pushed = dfs(to, min(flow, edge.first.second), d);
            if (pushed) {
                edge.first.second -= pushed;
                c[to][edge.second].first.second += pushed;
                return pushed;}}
        return 0;}
    int potok() {
        int flow = 0;
        while (1) {
            skip = vi(n); vi d(n, -1);  if (!bfs(d)) break;
            while (int pushed = dfs(s, inf, d)) flow += pushed;}
        return flow;}};
