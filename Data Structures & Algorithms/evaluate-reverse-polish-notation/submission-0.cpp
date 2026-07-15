class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            if(it == "+"){
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left + right);
            }
            else if(it == "-"){
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left - right);
            }
            else if(it == "*"){
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left * right);
            }
            else if(it == "/"){
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left / right);
            }
            else{
                st.push(stoi(it));
            }
        }
        if(!st.empty()){
            return st.top();
        }
        else{
            return -1;
        }
    }
};
