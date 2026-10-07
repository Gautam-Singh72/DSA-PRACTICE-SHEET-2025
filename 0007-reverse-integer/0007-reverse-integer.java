class Solution {
    public int reverse(int x) {
        int rem,sum=0;
        int min=Integer.MIN_VALUE;
        int max=Integer.MAX_VALUE;
        while(x!=0){
            rem=x%10;
            if(sum>max/10 || sum<min/10){
            return 0;
        }
            sum=sum*10+rem;
            x=x/10;

        
        }
         return sum;
        
    }
}