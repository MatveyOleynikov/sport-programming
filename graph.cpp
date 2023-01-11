struct graph{
    long long n, m;
    vector<vector<long long>> g;

    graph(){
        n = 0;
        m = 0;
    }

    graph(int col){
        n = col;
        g.resize(n);
        m = 0;
    }

    vi& operator [](int i){
        return g[i];
    }

    friend ostream& operator<<(ostream& o, const graph& cur)
    {
        o << "Vertexes: " << cur.n << "\n";
        o << "Edges: " << cur.m << "\n";

        for (long long u = 0; u < cur.n; ++u){
            o << u << ":";
            o << '(';
            for (auto v: cur.g[u]){
                o << v;
                o << ',';
            }
            o << ')';
            o << '\n';
        }
        return o;
    }

    friend istream& operator>>(istream& o, graph& cur)
    {
        o >> cur.n;
        cur.g.resize(cur.n);

        o >> cur.m;
        for (long long i = 0; i < cur.m; ++i){
            long long u, v;
            o >> u; u--;
            o >> v; v--;
            cur.g[u].push_back(v);
            cur.g[v].push_back(u);
        }
        return o;
    }

    void add_edge(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
        m++;
    }

    graph og(){
        graph res;
        for (int u = 0; u < n; ++u){
            for (auto v: g[u]){
                res.g[v].push_back(u);
            }
        }
        return res;
    }

    bool try_kuhn (int v, vi& mt, vi& used) {
        if (used[v])  return false;
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (mt[to] == -1 || try_kuhn (mt[to], mt, used)) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }

    vector<pii> kuhn(){
        vector<int> mt(n, -1);
        vi used(n);

        for (int u = 0; u < n; ++u){
            used.clear();
            used.resize(n);

            try_kuhn(u, mt, used);
        }

        vector<pii> res;
        for (int i = 0; i < n; ++i){
            if (mt[i] != -1){
                res.push_back({mt[i], i});
            }
        }

        return res;
    }

    vi bfs(int s){
        vi dist(n, inf);
        queue<int> q;

        dist[s] = 0;
        q.push(s);

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for (auto elem: g[cur]){
                if (dist[elem] == inf){
                    dist[elem] = dist[cur] + 1;
                    q.push(elem);
                }
            }
        }

        return dist;
    }
};
