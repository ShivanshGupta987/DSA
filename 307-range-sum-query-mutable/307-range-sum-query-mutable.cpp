#define vi vector<int>
class NumArray {
 public:
 vi bit;
 vi arr;
 int n;
 public:
   void BIT(vi &nums){
         this->arr=nums;
          n=nums.size();
         bit.resize(n+1);
        for(int i=0;i<n;i++){
            init(i,nums[i]);
        } 
   }
   int prefixSum(int ind){
       if(ind<0)return 0;
       ind++;
       int sum=0;
      while(ind>0){
        sum+=bit[ind];
        ind = ind - (ind & -ind);
      }
      return sum;
   }
   void init(int i, int val){
        i++;
       while(i<=n){
           bit[i]+=val;
           i= i+ (i&-i);
       }
   
   }
   void update(int i, int val){
       int diff = val- arr[i];
       arr[i]=val;
      init(i,diff);
   }

   int sumRange(int l, int r){
       return  prefixSum(r)-prefixSum(l-1);
   }   

    NumArray(vector<int>& nums) {
        BIT(nums);
    }
    
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */