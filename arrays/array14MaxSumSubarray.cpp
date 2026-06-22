class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0 ; i < k; i++){
            sum = sum + nums[i];
        }
        double max = sum/k;
        int i = 0;

        while(i+k < nums.size()){
            sum = sum - nums[i] + nums[i+k];
            if(sum/k > max){
                max = sum/k;
            }
            i++;
        }
        return max;
            
    }
};