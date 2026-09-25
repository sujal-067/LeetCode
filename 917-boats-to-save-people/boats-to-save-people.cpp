class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(),nums.end());
        int st=0,end=nums.size()-1,ans=0;
        while(st<=end){
            if(nums[st]+nums[end]<=limit){
                st++;end--;
            }else{
                end--;
            }
            ans++;
        }
        return ans;
    }
};