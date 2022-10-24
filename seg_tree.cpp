struct seg_tree{ /// 0 - индексация
    const int good_value = 0; ///безопасное значение (для суммы - 0, для произведения - 1 и тд)
    vi t;
    int n;

    seg_tree(int n){
        this->n = n;
        t.resize(n);
    }

    int func(int a, int b){
        return a + b; /// функция для отрезка
    }

    void update(int cur_ind, int L, int R, int ind, int val){
        if (ind > R || ind < L){
            return;
        }

        if (L == R){
            t[cur_ind] = val;
        }

        int m = (R + L) / 2;

        update(cur_ind * 2, L, m, ind, val);
        update(cur_ind * 2 + 1, m + 1, R, ind, val);
    }

    int get(int cur_ind, int L, int R, int l, int r){
        if (l > R || r < L){
            return good_value;
        }

        if (l <= L && R <= r){
            return t[cur_ind];
        }

        int m = (L + R) / 2;
        return func(get(cur_ind * 2, L, m, l, r), get(cur_ind * 2 + 1, m + 1, R, l, r));
    }

    void update(int ind, int val){
        update(1, 0, n - 1, ind, val);
    }

    int get(int l, int r){
        return get(1, 0, n - 1, l, r);
    }
};
