int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    int s1 = accumulate(h1.begin(), h1.end(), 0);
    int s2 = accumulate(h2.begin(), h2.end(), 0);
    int s3 = accumulate(h3.begin(), h3.end(), 0);

    int i = 0, j = 0, k = 0;

    while (true) {
        if (s1 == s2 && s2 == s3)
            return s1;

        if (s1 >= s2 && s1 >= s3)
            s1 -= h1[i++];
        else if (s2 >= s1 && s2 >= s3)
            s2 -= h2[j++];
        else
            s3 -= h3[k++];
    }
}
