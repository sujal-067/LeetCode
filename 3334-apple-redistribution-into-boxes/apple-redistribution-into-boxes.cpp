class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;

        // Total apples
        for(int x : apple) {
            total += x;
        }

        // Largest capacity first
        sort(capacity.rbegin(), capacity.rend());

        int count = 0;
        int space = 0;

        for(int x : capacity) {
            space += x;
            count++;

            if(space >= total) {
                return count;
            }
        }

        return count;
    }
};