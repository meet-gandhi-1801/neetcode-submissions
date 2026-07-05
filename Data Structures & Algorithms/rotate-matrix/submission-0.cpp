class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        for(int j = 0;j<n;j++)
        {
            for(int i = j;i<n;i++)
            {
               swap( matrix[i][j] , matrix[j][i]);
            }
        }
        for(int j = 0;j<(n/2);j++)
        {
            for(int i =0;i<n;i++)
            {
                swap(matrix[i][j] ,matrix[i][n-j-1]);
            }
        }

    }
};
