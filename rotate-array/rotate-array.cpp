// class Solution {
// public:
//        // TC:O(n*k)  
//        // SC:O(1)
//     void rotate(vector<int>& a, int k) {
//             k%=a.size();
//             int n=a.size();
//         while(k--)
//         {   
//                 int t1,t2=a[n-1];
                
//           for(int i=0;i<n;i++){
//                t1=a[i];
//                   a[i]=t2;
//                   t2=t1;
//           }  
                
                
//         }
//     }
// };


// class Solution {
// public:
//         // TC:O(N)
//         // SC:O(N)
//     void rotate(vector<int>& a, int k) {
//             k%=a.size();
//              int n=a.size();
//             vector<int>arr(n);
            
//           for(int i=0;i<n;i++){
//                arr[i]=(a[i]);
//           } 
//            for(int i=0;i<n;i++){
//                    a[(i+k)%n]=arr[i];
//            }                
//     }
// };


class Solution {
public:
        // TC:O(N)
        // SC:O(1)
    void rotate(vector<int>& arr, int k) {
            
            k%=arr.size();
            if(k==0)return;
             int n=arr.size();
            int i=0;int j=0;
            int curr,prev=arr[j],next;
            int size=n;
            while(size--){
               
                    //cout<<j<<" "<<k<<" "<<n<<endl;
                    j=(j+k)% n;
                    curr=arr[j];
                    arr[j]=prev;
                    prev=curr;
                    if(j==i){i++;j=i;prev=arr[j];}
            }
              
    }
};
