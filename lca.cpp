struct lca{
    int timer, l;
    vi tin, tout;
    vvi up;

    void dfs (weighed_graph& g, int v, int p = 0) {
        dbg(v, p);
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i=1; i<=l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
        dbg(up);
        for (size_t i=0; i < g.g[v].size(); ++i) {
            int to = g.g[v][i].first;
            if (to != p)
                dfs (g, to, v);
        }
        tout[v] = ++timer;
    }

    lca(weighed_graph g, int root){
        dbg(g);
        dbg(root);
        int n = g.n;
        l = 1;
        while ((1<<l) <= n)  ++l;
        up.resize(n);
        for (int i=0; i< n; ++i)  up[i].resize (l+1);

        tin.resize(n), tout.resize(n);
        timer = 0;

        dbg(l);
        dfs(g, root);
    }

    bool upper (int a, int b) {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    }

    int zapros (int a, int b){
        if (upper (a, b))  return a;
        if (upper (b, a))  return b;
        for (int i = l; i >= 0; --i)
            if (!upper(up[a][i], b))
                a = up[a][i];
        return up[a][0];
    }
};
