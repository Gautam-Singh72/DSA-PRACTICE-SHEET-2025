class Solution {
    public int maxSubArray(int[] arr) {
        int curr_sum=arr[0];
        int max_sum=arr[0];
        for(int i=1;i<arr.length;i++){
            curr_sum=Math.max(arr[i],curr_sum+arr[i]);
            max_sum=Math.max(max_sum,curr_sum);
        }
        return max_sum;
    }
    
}
    