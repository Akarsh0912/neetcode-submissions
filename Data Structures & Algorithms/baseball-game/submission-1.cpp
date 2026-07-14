class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sum =0;

        for(auto it : operations){
            if(it == "C"){
                st.pop();
            }
            else if(it == "D"){
                int temp = st.top();
                st.push(2*temp);
            }
            else if(it == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.push(first);
                st.push(first+second);
            }
            else{
                st.push(stoi(it));
            }
        }

        while(!st.empty()){
            sum = sum + st.top();
            st.pop();
        }
        return sum;
        
    }
};