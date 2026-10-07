class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,ans=0;
        unordered_set<char>st;
        while(right<s.size()){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                int len=right-left+1;
                ans=max(len,ans);
                right++;
            }
            else{
                st.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};