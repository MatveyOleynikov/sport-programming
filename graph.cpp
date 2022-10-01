struct graph{
    long long n, m;
    vector<vector<long long>> g;

    friend ostream& operator<<(ostream& o, const graph& cur)
    {
        o << "Vertexes: " << cur.n << "\n";
        o << "Edges: " << cur.m << "\n";

        for (long long u = 1; u <= cur.n; ++u){
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
        cur.g.resize(cur.n + 1);

        o >> cur.m;
        for (long long i = 0; i < cur.m; ++i){
            long long u, v;
            o >> u;
            o >> v;
            cur.g[u].push_back(v);
            cur.g[v].push_back(u);
        }
        return o;
    }
};
