struct lca {
    int timer, l;
    vi tin, tout;
    vvi up;

    void dfs(vvi& g, int u, int root) {
        tin[u] = ++timer;
        up[u][0] = root;
        for (int i = 1; i <= l; ++i)
            up[u][i] = up[up[u][i - 1]][i - 1];
        for (auto v : g[u]) {
            if (v != root)
                dfs(g, v, u);
        }
        tout[u] = ++timer;
    }

    lca(int n, vvi g, int root = 0) {
        l = 1;
        while ((1 << l) <= n)  ++l;
        up.resize(n);
        for (int i = 0; i < n; ++i)  up[i].resize(l + 1);

        tin.resize(n), tout.resize(n);
        timer = 0;

        dfs(g, root, root);
    }

    bool upper(int a, int b) {
        return tin[a] <= tin[b] && tout[a] >= tout[b];
    }

    int zapros(int a, int b) {
        if (upper(a, b))  return a;
        if (upper(b, a))  return b;
        for (int i = l; i >= 0; --i)
            if (!upper(up[a][i], b))
                a = up[a][i];
        return up[a][0];
    }
};
