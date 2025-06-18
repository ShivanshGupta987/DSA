class Solution {
    // TC : O(N)
    // SC : O(N)
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int>id_to_idx(n);

        for(int i=0;i<n;i++){
            id_to_idx[row[i]] = i;
        }
        int cnt = 0;
        for(int i=0;i<n;i+=2){
            int hus = row[i];
            int wife = row[i] + (row[i]%2? -1 : 1);
            if(row[i+1] == wife) continue;
            int idx = id_to_idx[wife];
            int person = row[i+1];
            row[i+1] = wife;
            row[idx] = person;
            id_to_idx[wife] = i;
            id_to_idx[person] = idx;
            cnt++;
        }
        // for(int i=0;i<n;i++){
        //     cout<<row[i]<<" ";
        // }
        return cnt;
    }
};