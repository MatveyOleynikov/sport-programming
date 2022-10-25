    int l = 0, r = n, EPS = 2; // входные данные
    while (r - l > EPS) {
        dbg(l, r);
       int m1 = l + (r - l) / 3,
          m2 = r - (r - l) / 3;
       if (check_ans(m1, a, n, q) < check_ans(m2, a, n, q))
          l = m1;
       else
          r = m2;
    }

    int k = l;
    if (check_ans(l, a, n, q) < check_ans(r, a, n, q)) k = r;
    if (check_ans(l, a, n, q) < check_ans(l + 1, a, n, q)) k = r;
