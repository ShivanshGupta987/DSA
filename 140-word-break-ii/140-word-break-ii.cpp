class Solution {
        vector<string>ans;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       
            unordered_set<string>ss;
            for(auto x: wordDict) ss.insert(x);
            dfs(0,s,ss,"");
            return ans;
    }
        
    void dfs(int start, string s, unordered_set<string>& ss, string cur_str){
            
            int len = s.size();
            if(len==0) {
                    ans.push_back(cur_str); return ;
            }
            
            for(int end=0; end<len; end++){
                    string str = s.substr(0,end+1);
                    if(ss.count(str)) {
              dfs(end+1, s.substr(end+1),ss, cur_str + (cur_str.size()?" ":"") + str);
                    }
            }
    }
};