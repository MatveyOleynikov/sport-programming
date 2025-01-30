struct Shape2SegTree {
    const int good_value = 0;

    int func(int a, int b) {
        return max(a, b);
    }

    vector<pii> deti;
    vi t;
    int n;

    Shape2SegTree(int n) {
        this->n = n;
        t = { good_value };
        deti = { {-1, -1} };
    }

    int new_rebenok() {
        t.push_back(good_value);
        deti.push_back({ -1, -1 });

        return t.size() - 1;
    }

    int x, y, value;

    bool in_bb(int Xl, int Xr, int Yl, int Yr) {
        return Xl <= x && x <= Xr && Yl <= y && y <= Yr;
    }

    void update(int v, int Xl, int Xr, int Yl, int Yr) {
        if (!in_bb(Xl, Xr, Yl, Yr)) {
            return;
        }

        if (deti[v].first == -1) {
            deti[v].first = new_rebenok();
        }

        if (deti[v].second == -1) {
            deti[v].second = new_rebenok();
        }

        if (Xr - Xl > Yr - Yl) {
            int Xc = (Xr + Xl) / 2;
            update(deti[v].first, Xl, Xc, Yl, Yr);
            update(deti[v].second, Xc + 1, Xr, Yl, Yr);
        }

        else {
            int Yc = (Yr + Yl) / 2;
            update(deti[v].first, Xl, Xr, Yl, Yc);
            update(deti[v].second, Xl, Xr, Yc + 1, Yr);
        }
    }

    int xl, yl, xr, yr;

    bool intersect(int Xl, int Xr, int Yl, int Yr) {
        if (Xl > xr || xl > Xr || Yl > yr || yl > Yr) {
            return false;
        }
        return true;
    }

    bool below(int Xl, int Xr, int Yl, int Yr) {
        if (xl <= Xl && Xr <= xr && yl <= Yl && Yr <= yr) {
            return true;
        }
        return false;
    }

    int get(int v, int Xl, int Xr, int Yl, int Yr) {
        if (v == -1) {
            return good_value;
        }

        if (!intersect(Xl, Xr, Yl, Yr)) {
            return good_value;
        }

        if (below(Xl, Xr, Yl, Yr)) {
            return t[v];
        }


        if (Xr - Xl > Yr - Yl) {
            int Xc = (Xr + Xl) / 2;
            return func(
                get(deti[v].first, Xl, Xc, Yl, Yr),
                get(deti[v].second, Xc +1, Xr, Yl, Yr)
            );
        }

        else {
            int Yc = (Yr + Yl) / 2;
            return func(
                get(deti[v].first, Xl, Xr, Yl, Yc),
                get(deti[v].second, Xl, Xr, Yc + 1, Yr)
            );
        }
    }

    void update(int x, int y, int value) {
        this->x = x;
        this->y = y;
        this->value = value;

        update(0, 0, 0, n - 1, n - 1);
    }

    int get(int xl, int yl, int xr, int yr) {
        this->xl = xl;
        this->yl = yl;
        this->xr = xr;
        this->yr = yr;
    }
};
