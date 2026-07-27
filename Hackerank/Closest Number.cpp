int closestNumber(int a, int b, int x) {
    double p = pow((double)a, (double)b);

    long long k = (long long)floor(p / x);
    long long lower = k * 1LL * x;
    long long upper = lower + x;

    if (p - lower <= upper - p)
        return (int)lower;
    return (int)upper;
}
