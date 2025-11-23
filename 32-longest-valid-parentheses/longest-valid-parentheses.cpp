class Solution {
    // TC : O(N)
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n = s.size();
        int ans = 0;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]==')' && st.top()!=-1 && s[st.top()]=='('){
                st.pop();
                ans = max(ans, i-st.top());
            }
            else st.push(i);
        }
        return ans;
    }
};