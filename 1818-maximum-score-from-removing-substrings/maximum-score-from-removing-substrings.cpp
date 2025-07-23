class Solution {
    // TC : O(N)
    // SC : O(N)
    string remove(string &s, string & target){
        stack<char>st;
        int cnt = 0;
        for(int i=0;s[i];i++){
            if(!st.empty() && s[i]==target[1] && st.top()==target[0]){
                cnt++;
                st.pop();
            }
            else st.push(s[i]);
        }
        string rem = "";
        while(!st.empty()){
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        return rem;

    }
public:
    int maximumGain(string s, int x, int y) {
        
        int totalScore = 0;
        string highPriorityPair = x > y ? "ab" : "ba";
        string lowPriorityPair = x > y ? "ba" : "ab";

        // first pass : removing high priority pair

        string rem1 = remove(s, highPriorityPair);
        int score1 = max(x,y)*(s.size()-rem1.size())/2;

        // second pass : removing low priority pair 
        
        string rem2 = remove(rem1, lowPriorityPair);
        int score2 = min(x,y)*(rem1.size()-rem2.size())/2;

        return score1 + score2;
    }
};