struct root_tree_1{
    long long n;
    vector<vector<long long>> g;

    friend istream& operator>>(istream& o, root_tree_1& cur)
    {
        o >> cur.n;
        cur.g.resize(cur.n + 1);

        for (long long i = 2; i <= cur.n; ++i){
            long long parent;
            cin >> parent;
            cur.g[parent].push_back(i);
        }
        return o;
    }
};
