struct graph{
    long long n, m;
    vector<vector<long long>> g;

    graph(){
        n = 0;
        m = 0;
    }

    graph(int col){
        n = col;
        g.resize(n + 1);
        m = 0;
    }

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
    
    void add_edge(int u, int v){
        g[u].push_back(v);
        g[v].push_back(u);
        m++;
    }
    
    graph og(){
        graph res;
        for (int u = 1; u <= n; ++u){
            for (auto v: g[u]){
                res.g[v].push_back(u);
            }
        }
        return res;
    }
};
