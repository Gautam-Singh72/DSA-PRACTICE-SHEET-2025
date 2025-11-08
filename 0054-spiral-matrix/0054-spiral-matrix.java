class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int startrow=0;
        int endrow=matrix.length-1;
        int startcolm=0;
        int endcolm=matrix[0].length-1;
        List<Integer> li = new ArrayList<>();
        while(startrow<=endrow && startcolm<=endcolm){
            for(int j=startcolm; j<=endcolm; j++){
                li.add(matrix[startrow][j]);
            
            }
            for(int i=startrow+1; i<=endrow; i++){
                li.add(matrix[i][endcolm]);
                
            }
            for(int j=endcolm-1; j>=startcolm; j--){
                if(startrow==endrow){
                    break;
                }
                li.add(matrix[endrow][j]);
                
                
                
            }
            for(int i=endrow-1; i>=startrow+1; i--){
                if(startcolm==endcolm){
                    break;
                }
                li.add(matrix[i][startcolm]);
                
                
            }
            startrow++;
            startcolm++;
            endrow--;
            endcolm--;
        }
        return li;

    }
}