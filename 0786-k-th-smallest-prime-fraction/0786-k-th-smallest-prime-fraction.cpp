class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            double frac = static_cast<double>(arr[i]) / arr[j];
            pq.push({frac, {i, j}});
        }
    }
    while (--k) {
        pq.pop();
    }
    auto [frac, idx] = pq.top();
    return {arr[idx.first], arr[idx.second]};
    }
};