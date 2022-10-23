struct weighed_graph{
    long long n, m;
    vector<vector<pair<long long, long long>>> g;

    weighed_graph(){
        n = 0;
        m = 0;
    }

    weighed_graph(int col){
        n = col;
        g.resize(n + 1);
        m = 0;
    }
    
    friend ostream& operator<<(ostream& o, const weighed_graph& cur)
    {
        o << "Vertexes: " << cur.n << "\n";
        o << "Edges: " << cur.m << "\n";

        for (long long u = 1; u <= cur.n; ++u){
            o << u << ":";
            o << '(';
            for (auto [v, w]: cur.g[u]){
                o << '(';
                o << v;
                o << ',';
                o << w;
                o << ')';
                o << ',';
            }
            o << ')';
            o << '\n';
        }
        return o;
    }

    friend istream& operator>>(istream& o, weighed_graph& cur)
    {
        o >> cur.n;
        cur.g.resize(cur.n + 1);

        o >> cur.m;
        for (long long i = 0; i < cur.m; ++i){
            long long u, v, w;
            o >> u;
            o >> v;
            o >> w;
            cur.g[u].push_back({v, w});
            cur.g[v].push_back({u, w});
        }
        return o;
    }

    void add_edge(int u, int v, int w){
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        m++;
    }

    vector<long long> djkstra(long long start){ //тут 1-индексация и это важноо!!!!!
        vector<long long> ans(n + 1);
        vector<long long> pr(n + 1);
        for (long long i = 1; i <= n; i++) {
            ans[i] = inf64;
            pr[i] = -1;   //Значение, обозначающее что из этой вершины возвращаться некуда
        }

        ans[start] = 0;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;

        q.push({0, start});

        while (!q.empty()) {
            pair<long long, long long> c = q.top();
            q.pop();

            long long dst = c.first, v = c.second;

            if (ans[v] < dst) {
                continue;
            }

            for (pair<long, long> e: g[v]) {
                int u = e.first, len_vu = e.second;

                int n_dst = dst + len_vu;
                if (n_dst < ans[u]) {
                    ans[u] = n_dst;
                    pr[u] = v;
                    q.push({n_dst, u});
                }
            }
        }

        return ans;
        /*vector<long long> path;

        long long cur = end;
        path.push_back(cur);

        while (pr[cur] != -1) {
            cur = pr[cur];
            path.push_back(cur);
        }

        reverse(path.begin(), path.end());

        cout << "Shortest path between vertices " << start + 1 << " and " << end + 1 << " is: " << endl;

        for (long long v: path) {
            cout << v + 1 << ", ";
        }*/ /// если нужен сам путь
    }
};
