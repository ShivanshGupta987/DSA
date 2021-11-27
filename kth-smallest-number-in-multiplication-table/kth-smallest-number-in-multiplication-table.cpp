// class Solution {
// public:
//     int findKthNumber(int m, int n, int k) {
//          int count=0;   
//         for(int i=1;i<=m;i++){
//                 for(int j=1;j<=n;j++){
//                         if(k<=i*j)count++;
//                 }
//         }
//             return count;
//     }
// };



class Solution {
public:
        // TC : O(mlog(m*n))
        // SC: O(1)
    int findKthNumber(int m, int n, int k) {                                        
            int low=1; int high=m*n;
            while(low<high)
            {
                int mid=(low + high)/2;
                int count=0;  // count stores how many numbers are smaller than or equal to mid
                    for(int i=1;i<=m;i++)
                    {
                        int j= mid/i;
                       count+= ( (j>n)? n : j);     
                    }
                    
                    if(count>=k) high = mid; // target count is less than or equal to mid count
                    else low = mid +1 ;
            }
       return low;
    }
};