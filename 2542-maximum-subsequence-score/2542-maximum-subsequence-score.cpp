#define pii pair<int,int>

// TC : O(n log k)
// SC : O(n)
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b, int k) {
        long long ans = 0;
        priority_queue<pii>maxheap;
        
        // inserting all the elements of array a in max heap
        for(int i=0;i<a.size();i++){
            maxheap.push({a[i],i});
        }
        priority_queue<pii,vector<pii>,greater<pii>>minheap;
        long long sum = 0;
        
        // popping out k largest element of array a from the max
        // heap and inserting elements of array b corresponding to 
        // those elements in min heap
        for(int i=0;i<k;i++){
            pii top = maxheap.top();
            maxheap.pop();
            sum += top.first;
            minheap.push({b[top.second],top.second});
        }
        ans = sum*(long long)minheap.top().first;
        
        while(maxheap.size()){
            
            pii top = maxheap.top();
            maxheap.pop();
            minheap.push({b[top.second],top.second});
            sum += top.first;
            
            top = minheap.top();
            minheap.pop();
            sum -= a[top.second];
            
            ans = max(ans,sum*(long long)minheap.top().first);
        }
        return ans;
        
    }
};



// bool comp(const pair<int,int>& a, const pair<int,int>& b){
//         if(a.first < b.first) return true;
//         else if(a.first == b.first){
//             return a.second < b.second;
//         }
//         else return false;
//     }
// class Solution {

// // TC : O(n log n)
// // SC : O(n)
// public:
//     long long maxScore(vector<int>& a, vector<int>& b, int k) {
       
//         int n = a.size();
//         vector<pair<int,int>>vp;
//         for(int i=0;i<n;i++){
//             vp.push_back({b[i],a[i]});
//         }
//         sort(vp.begin(),vp.end(),comp);
//         priority_queue<int,vector<int>,greater<int>>pq;
//         // int ind=n-1;
//         long long sum=0, res = 0;
//         // int mn = INT_MAX;
//         // while(k--){
//         //     sum+=vp[ind].second;
//         //     pq.push(vp[ind].second);
//         //     mn  = min(mn,vp[ind].first);
//         //     ind--;
//         // }
//         // res = sum*(long long)mn;
//         // for(int i=ind;i>=0;i--){

//             // long long num = pq.top();
//             // long long cur_num = vp[i].second;
//             // long long sm = vp[i].first;
//             // if((sum-num+cur_num)*sm > res){
//             //     res = (sum-num+cur_num)*sm;
//             //     sum -= num;
//             //     sum += cur_num;
//             //     // cout<<num<<" popped"<<endl;
//             //     pq.pop();
//             //     pq.push(cur_num);
//             //     // cout<<cur_num<<" pushed"<<endl;
//             //     // cout<<"res is :"<<res<<endl;
//             //     // cout<<"--------------"<<endl;
//             // }
//         // }
            
//         for(int i=n-1;i>=0;i--){
//             int cur_num = vp[i].second;
//             pq.push(cur_num);
//             sum+=cur_num;

//             if(pq.size()>k){
//                 int smallest_num = pq.top();
//                 pq.pop();
//                 sum -= smallest_num;
//             }

//             if(pq.size()==k){
//                 res = max(res, sum*(long long)vp[i].first);
//             }
//         }
//         return res;
//     }
// };