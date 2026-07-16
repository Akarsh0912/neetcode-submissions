class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for ( auto i : asteroids){
            bool alive  = true;

            while(!st.empty() && st.top() > 0 && i < 0){
                if(abs(st.top()) > abs(i)){
                    alive = false;
                    break;
                }
                else if(abs(st.top()) < abs(i)){
                    st.pop();
                }
                else{
                    st.pop();
                    alive = false;
                    break;
                }

            }

            if(alive){
                st.push(i);
            }
        }

        vector<int> ans(st.size());

        for(int i = st.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};