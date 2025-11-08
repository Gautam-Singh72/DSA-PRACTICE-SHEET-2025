class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int N=matrix.length, M=matrix[0].length;
        int start=0; int end=N*M-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;
            int mid_value=matrix[mid/M][mid%M];
            if(mid_value==target){
                return true;
            }
            else if(mid_value<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
}