struct weighed_graph{
    long long n, m;
    vector<vector<pair<long long, long long>>> g;

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
};
