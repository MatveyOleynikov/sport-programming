struct lazy_seg_tree{ /// 0 - индексация ; ///здесь добавление на отрезке, а не изменение
    const int good_value = 0; ///безопасное значение (для суммы - 0, для произведения - 1 и тд)
    vi t;
    vi add; /// lazy массив
    int n;

    lazy_seg_tree(int n){
        this->n = n;
        t.resize(n * 4 + 1);
        add.resize(n * 4 + 1);
    }

    void modify(int v, int L, int R, int l, int r, int X){
       if (L > r || R < l){
           return;
       }
       if (l <= L && R <= r){
           t[v] += X * (R - L + 1); ///при переходе с суммы на другую функцию заменить это на t[v] += X
           add[v] += X;
       }
       else {
           int C = (L + R) / 2;
           modify(v * 2, L, C, l, r, X);
           modify(v * 2 + 1, C + 1, R, l, r, X);
           t[v] = t[v * 2] + t[v * 2 + 1] + add[v] * (R - L + 1);  ///при переходе с суммы на другую функцию заменить это на t[v] = max(t[v * 2], t[v * 2 + 1]) + add[v];
       }
    }

    void modify(int l, int r, int X){
       modify(1, 0, n - 1, l, r, X);
    }

    int get(int v, int L, int R, int l, int r, int additive){
       if (L > r || R < l){
           return good_value;
       }
       if (l <= L && R <= r){
           return t[v] + additive * (R - L + 1); ///t[v] + additive для максимума
       }
       int C = (L + R) / 2;
       return get(v * 2, L, C, l, r, additive + add[v])
               + get(v * 2 + 1, C + 1, R, l, r, additive + add[v]); ///заменить функцию на максимум для максимума
    }

    int get(int l, int r){
       return get(1, 0, n - 1, l, r, 0);
    }
};
