class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
            vector<vector<int>>res{{1}};
            vector<int>temp;
            for(int i=1;i<numRows;i++){
                    temp.push_back(1);
                    for(int j=1;j<i;j++){
                            temp.push_back(res.back()[j-1] + res.back()[j]);
                    }
                    temp.push_back(1);
                    res.push_back(temp);
                    temp.clear();
            }
            return res;
    }
};