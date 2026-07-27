long gcd(long a, long b) {
    while (b) {
        long t = a % b;
        a = b;
        b = t;
    }
    return abs(a);
}

vector<int> solve(vector<long> a, vector<int> queries) {
    int n = a.size();

    if (n == 1) {
        vector<int> ans;
        for (int k : queries)
            ans.push_back((int)(a[0] + k));
        return ans;
    }

    long g = 0;
    for (int i = 1; i < n; i++)
        g = gcd(g, labs(a[i] - a[0]));

    vector<int> ans;
    for (int k : queries)
        ans.push_back((int)gcd(g, a[0] + k));

    return ans;
}
