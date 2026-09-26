class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int st=0,end=tokens.size()-1,ans=0,score=0;
        while(st<=end){
            //upper part for the face up 
            if(tokens[st]<=power){
                power-=tokens[st];
                score++;
                ans=max(ans,score);
                st++;
            }
            // for bottom part face down
            else if(score>0){
                power+=tokens[end];
                score--;
                end--;
            }
            else{
                break;
            }
        }
        return ans;
    }
};