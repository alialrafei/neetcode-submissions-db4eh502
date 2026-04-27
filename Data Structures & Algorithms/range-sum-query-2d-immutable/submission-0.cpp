class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
       int cols = matrix[0].size()+1, rows = matrix.size()+1;
       prefixSum = vector<vector<int>>(rows,vector<int> (cols,0));
       for(int row = 1; row< rows;row++){
            int prefix = 0 ;
            for(int col = 1; col < cols ; col++){
                prefixSum[row][col] = matrix[row-1][col-1]+ 
                    prefixSum[row][col-1] + 
                    prefixSum[row-1][col]-
                    prefixSum[row-1][col-1];
            }
       }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;col1++;row2++;col2++;
        return prefixSum[row2][col2] -
               prefixSum[row1-1][col2] -
               prefixSum[row2][col1-1] +
               prefixSum[row1-1][col1-1];

    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */