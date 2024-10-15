struct snm {
    int n; vi clr; vvi obr_clr;
    void join(int u, int v) {
        int color1 = clr[u], int color2 = clr[v];
        if (color1 == color2) return;
        if (obr_clr[color1].size() < obr_clr[color2].size()) swap(color1, color2);
        for (auto elem : obr_clr[color2]) {
            obr_clr[color1].push_back(elem);
            clr[elem] = color1;
        }
    }
    snm(long long n): n(n), clr(vi(n)), obr_clr(vvi(n)) {
        for (int i = 0; i < n; ++i) {
            clr[i] = i; obr_clr[i].push_back(i);
        }
    }
};
