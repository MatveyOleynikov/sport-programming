struct snm{
    long long n;
    vector<long long> clr;
    vector<vector<long long>> obr_clr;

    void join(long long color1, long long color2){
        if (color1 == color2){
            return;
        }
       
        if (obr_clr[color1].size() < obr_clr[color2].size()){
            swap(color1, color2);
        }

        for (auto elem: obr_clr[color2]){
            obr_clr[color1].push_back(elem);
            clr[elem] = color1;
        }
    }

    void join_elems(int u, int v){
        join(clr[u], clr[v]);
    }

    bool equal_snm(int u, int v){
        return clr[u] == clr[v];
    }

    snm(long long n){
        this->n = n;

        clr.resize(n);
        obr_clr.resize(n);

        for (int i = 0; i < n; ++i){
            clr[i] = i;
            obr_clr[i].push_back(i);
        }
    }
};
