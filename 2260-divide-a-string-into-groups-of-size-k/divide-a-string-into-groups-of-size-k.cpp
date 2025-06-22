class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>res;
        int i = 0, n = s.size();
        for(int i=0;i<n;i++){
            string temp(k,fill);
            int j = i;
            while(j<i+k && j<n){
                temp[j-i] = s[j];
                j++;
            }
            res.push_back(temp);
            i = j-1;
        }
        return res;
    }
};