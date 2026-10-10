class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<int> diff(nums1.size());
        int mx = 0;
        for (int i = 0; i < nums1.size(); i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
        }
        int low = 0, high = mx;
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;
            for (int d : diff) {
                if (d > mid) need += d - mid;
            }
            if (need <= k) high = mid;
            else low = mid + 1;
        }
        long long ans = 0;
        for (int d : diff) {
            int reduced = min(d, low);
            ans += 1LL * reduced * reduced;
            k -= d - reduced;
        }
        // Any remaining operations reduce the sum further.
        // Distribute them by reducing the largest remaining differences.
        priority_queue<int> pq;
        for (int d : diff) {
            int reduced = min(d, low);
            if (reduced > 0) pq.push(reduced);
        }
        while (k > 0 && !pq.empty()) {
            int d = pq.top();
            pq.pop();
            ans -= 1LL * d * d;
            ans += 1LL * (d - 1) * (d - 1);
            k--;
            if (d - 1 > 0) pq.push(d - 1);
        }
        return ans;
    }
};