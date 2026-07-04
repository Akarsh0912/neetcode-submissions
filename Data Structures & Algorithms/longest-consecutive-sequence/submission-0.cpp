class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(auto num : nums){
            st.insert(num);
        }

        int longest = 0;

        for(auto num : st){

            if(st.find(num-1) != st.end()){
                continue;
            }

            int currElm = num;
            int currLen= 1;

            while(st.find(currElm+1) != st.end()){
                currElm++;
                currLen++;
            }

            longest = max(longest,currLen);
        }
        return longest;
    }
};
