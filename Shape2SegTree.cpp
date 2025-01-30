struct DynamicSegTree {
    const int good_value = 0;

    int func(int a, int b) {
        return max(a, b);
    }

    vector<pair<int, int>> deti;
    vector<int> t;
    int n;

    DynamicSegTree(int n) {
        this->n = n;
        t = { good_value };
        deti = { {-1, -1} };
    }

    int new_rebenok() {
        t.push_back(good_value);
        deti.push_back({ -1, -1 });

        return t.size() - 1;
    }

    int ind, value;

    void update(int v, int L, int R) {
        if (R < ind || ind < L) {
            return;
        }

        if (L == R) {
            t[v] = value;
            return;
        }

        if (deti[v].first == -1) {
            deti[v].first = new_rebenok();
        }

        if (deti[v].second == -1) {
            deti[v].second = new_rebenok();
        }

        int C = (L + R) / 2;
        update(deti[v].first, L, C);
        update(deti[v].second, C + 1, R);

        t[v] = func(t[deti[v].first], t[deti[v].second]);
    }

    int l, r;

    int get(int v, int L, int R) {
        if (v == -1) {
            return good_value;
        }

        if (r < L || R < l) {
            return good_value;
        }

        if (l <= L && R <= r) {
            return t[v];
        }

        int C = (L + R) / 2;
        return func(
            get(deti[v].first, L, C),
            get(deti[v].second, C + 1, R)
        );
    }

    int get(int l, int r) {
        this->l = l;
        this->r = r;

        return get(0, 0, n - 1);
    }

    void update(int index, int value) {
        this->ind = index;
        this->value = value;

        update(0, 0, n - 1);
    }
};

struct Shape2SegTree {
    const int good_value = 0;

    int func(int a, int b) {
        return max(a, b);
    }

    vector<DynamicSegTree> seg_trees;
    int n;

    Shape2SegTree(int n) {
        this->n = n;
        for (int i = 0; i < n * 4 + 10; ++i) {
            seg_trees.push_back(DynamicSegTree(n));
        }
    }

    int x, y, value;

    void prpgram_update(int v, int Xl, int Xr) {
        if (Xl > x || x > Xr) {
            return;
        }

        seg_trees[v].update(y, value);

        if (Xl == Xr) {
            return;
        }

        int Xc = (Xr + Xl) / 2;
        prpgram_update(v * 2, Xl, Xc);
        prpgram_update(v * 2 + 1, Xc + 1, Xr);
    }

    int xl, yl, xr, yr;

    int get(int v, int Xl, int Xr) {
        if (Xl > xr || xl > Xr) {
            return good_value;
        }

        if (xl <= Xl && Xr <= xr) {
            return seg_trees[v].get(yl, yr);
        }

        int Xc = (Xr + Xl) / 2;
        return func(
            get(v * 2, Xl, Xc),
            get(v * 2 + 1, Xc + 1, Xr)
        );
    }

    void update(int x, int y, int value) {
        this->x = x;
        this->y = y;
        this->value = value;

        prpgram_update(1, 0, n - 1);
    }

    int get(int xl, int yl, int xr, int yr) {
        this->xl = xl;
        this->yl = yl;
        this->xr = xr;
        this->yr = yr;

        return get(1, 0, n - 1);
    }
};

pair<vi, vi> get_tin_and_tout(vvi& tree) {
    return pair<vi, vi>();
}

int rnd(int N) {
    int rnd1 = rand() << 16ll + rand();
    return rnd1 % N;
}

void SOLVE::solve() {
    //pair<vi, vi> tin_and_tout1 = get_tin_and_tout(tree1);
    //pair<vi, vi> tin_and_tout2 = get_tin_and_tout(tree2);

    int N = 160'000;

    Shape2SegTree seg_tree(N);

    for (int i = 0; i < N; ++i) {
        seg_tree.update(rnd(N), rnd(N), rnd(N));
    }

    int sm = 0;

    for (int i = 0; i < N; ++i) {
        sm += seg_tree.get(rnd(N), rnd(N), rnd(N), rnd(N));
    }
    
    cout << sm << "\n";

    //for (int i = 0; i < n; ++i) {
    //    seg_tree.update(tin_and_tout1.first[i], tin_and_tout2.first[i], a[i]);
    //}

    //for (int i = 0; i < n; ++i) {
    //    cout << seg_tree.get(tin_and_tout1.first[i], tin_and_tout2.first[i], tin_and_tout1.second[i], tin_and_tout2.second[i]) << "\n";
    //}

    return;
}
