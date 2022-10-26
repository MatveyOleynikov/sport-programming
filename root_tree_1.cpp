struct root_tree_1{
    long long n;
    vector<vector<long long>> g;
    
    friend ostream& operator<<(ostream& o, const graph& cur)
    {
        o << "Vertexes: " << cur.n << "\n";
        o << "Edges: " << cur.n - 1 << "\n";

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

    friend istream& operator>>(istream& o, root_tree_1& cur)
    {
        o >> cur.n;
        cur.g.resize(cur.n);

        for (long long i = 1; i < cur.n; ++i){
            long long parent;
            cin >> parent; parent--;
            cur.g[parent].push_back(i);
        }
        return o;
    }
};
