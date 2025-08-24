struct Kun{
    int n, m; vvi g;
    bool try_kuhn (int v, vi& mt, vi& used) {
        if (used[v])  return false;
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (mt[to] == -1 || try_kuhn (mt[to], mt, used)) {
                mt[to] = v; return true;}}
        return false;}
    vector<pii> kuhn(){
        vector<int> mt(n, -1); vi used(n);
        for (int u = 0; u < n; ++u){
            used.clear(); used.resize(n);
            try_kuhn(u, mt, used);}
        vector<pii> res;
        for (int i = 0; i < n; ++i){
            if (mt[i] != -1){
                res.push_back({mt[i], i});}}
        return res;}};
