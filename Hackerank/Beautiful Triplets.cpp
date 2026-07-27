int beautifulTriplets(int d, vector<int> arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int count = 0;

    for (int x : arr) {
        if (s.count(x + d) && s.count(x + 2 * d)) {
            count++;
        }
    }

    return count;
}
