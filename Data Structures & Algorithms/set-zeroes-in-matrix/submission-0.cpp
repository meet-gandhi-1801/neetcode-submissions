class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j] == 0)
                {
                    for(int a = 0;a<n;a++)
                    {
                        if(matrix[a][j] != 0) matrix[a][j] = -1;
                    }
                    for(int a = 0;a<m;a++)
                    {
                        if(matrix[i][a] != 0) matrix[i][a] = -1;
                    }
                }
            }
        }

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(matrix[i][j] == -1) matrix[i][j] = 0;
            }
        }
        
    }
};
