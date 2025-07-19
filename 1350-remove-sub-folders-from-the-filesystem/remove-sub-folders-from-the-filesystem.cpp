class Solution {
    // TC : O(N*100*log N + N*100)
    // SC : O(N*100)
    bool isSubfolder(string &folder1, string& folder2){
        int n = folder1.size(), m = folder2.size();
        vector<string>splits1, splits2;
        string temp = "";
        for(int i=1;i<n;i++){
            if(folder1[i] !='/'){
                temp += folder1[i];
            }
            else{
                splits1.push_back(temp);
                temp = "";
            }
        }
        temp = "";
        for(int i=1;i<m;i++){
            if(folder2[i] !='/'){
                temp += folder2[i];
            }
            else{
                // cout<<temp;
                splits2.push_back(temp);
                temp = "";
            }
        }
        int sz = splits1.size();
        for(int i=0;i<sz;i++){
            // cout<<"("<<splits1[i]<<","<<splits2[i]<<")\n";
            if(splits1[i]!=splits2[i]) return false;
        }
        return true;
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string>res;
        int n = folder.size();
        res.push_back(folder[0]);
        for(int i=1;i<n;i++){
            // cout<<i<<"\n";
            string last_folder = res.back();
            string cur_folder = folder[i];
            last_folder += '/';
            cur_folder += '/';
            if(!isSubfolder(last_folder, cur_folder)){
                res.push_back(folder[i]);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<folder[i];
        //     cout<<"("<<i<<","<<mark[i]<<")\n";
        // }
        return res;

    }
};