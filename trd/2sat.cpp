struct TwoSat {
    int n; vvi g, gt; vector<bool> used;
    vector<int> order, comp;
    void dfs1(int v) {
        used[v] = true;
        for (size_t i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) dfs1(to);
        }
        order.push_back(v);}
    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (size_t i = 0; i < gt[v].size(); ++i) {
            int to = gt[v][i];
            if (comp[to] == -1) dfs2(to, cl);
        }}
    vi calc() {
        used.assign(n, false);
        for (int i = 0; i < n; ++i){
            if (!used[i]) dfs1(i);}
        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1) dfs2(v, j++);}
        for (int i = 0; i < n; ++i) {
            if (comp[i] == comp[i ^ 1]) {
                return {};}}
        vi res;
        for (int i = 0; i < n; i += 2) {
            int ans = comp[i] > comp[i ^ 1] ? 1 : 0;
            res.push_back(ans);}
        return res;}
    TwoSat(int n) : n(2 * n), g(vvi(2 * n)), gt(vvi(2 * n)) {}
    void add_or(int false_u, int false_v, int u, int v) {
        u *= 2; v *= 2;
        g[u ^ false_u ^ 1].push_back(v ^ false_v);
        g[v ^ false_v ^ 1].push_back(u ^ false_u);
        gt[v ^ false_v].push_back(u ^ false_u ^ 1);
        gt[u ^ false_u].push_back(v ^ false_v ^ 1);}};
