class Solution {
    // --------- USING DYNAMIC PROGRAMMING ----------
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int>dp(n); // dp[i] reprents len of longest substring ending at i
        int ans = 0;
        for(int i=1;i<n;i++){
            if(s[i]=='(') continue;
            if(s[i-1]=='('){
                dp[i] = (i-2>=0?dp[i-2]:0) + 2;
            }
            else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                dp[i] = (i-dp[i-1]-2>=0?dp[i-dp[i-1]-2] : 0) + dp[i-1] + 2;
            }
            ans = max(ans, dp[i]);
        } 
        return ans;
    }
};


class Solution1 {
    // ------------------ USING STACK -----------------------
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