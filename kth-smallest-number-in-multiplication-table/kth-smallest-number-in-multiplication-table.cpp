// class Solution {
// public:
//     int findKthNumber(int m, int n, int k) {
//             vector<int>arr;
//         for(int i=1;i<=m;i++){
//                 for(int j=1;j<=n;j++){
//                         arr.push_back(i*j);
//                 }
//         }
//             sort(arr.begin(),arr.end());
//             return arr[k-1];
//     }
// };
class Solution {
public:
    int findKthNumber(int m, int n, int k) {                                        
            int low=1; int high=m*n;
            while(low<high)
            {
                 int mid=(low + high)/2;
                    int count=0;
                    for(int i=1;i<=m;i++)
                    {
                        int j= mid/i;
                       count+= ( (j>n)? n : j);     
                    }
                    
                    if(count>=k) high = mid;
                    else low = mid +1 ;
            }
       return low;
    }
};