class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size());
        // for(int val:nums){
        //     ans.push_back(val*val);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;

        int left=0,right=nums.size()-1,pos=nums.size()-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                ans[pos]=nums[left]*nums[left];
                left++;
            }else{
                ans[pos]=nums[right]*nums[right];
                right--;
            }
            pos--;
        }
        return ans;
    }
};