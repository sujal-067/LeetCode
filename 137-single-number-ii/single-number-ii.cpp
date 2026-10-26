class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x : nums) {
            freq[x]++;
        }
        for(auto p : freq) {
            if(p.second == 1) {
                return p.first;
            }
        }
        return -1;
    }
};