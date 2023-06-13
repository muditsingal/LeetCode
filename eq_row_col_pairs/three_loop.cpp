class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int pairs = 0;
        int n = grid.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int i = 0;
        int j = 0;
        int k = 0;
        int row_cntr = 0;

        for(i = 0; i < n; i++)
        {
            row_cntr = 0;
            for(j = 0; j < n; j++)
            {
                row_cntr = 0;
                for(k = 0; k < n; k++)
                {
                    if(grid[i][k] != grid[k][j])
                        break;
                    row_cntr++;
                }
                if(row_cntr == n)
                {
                    pairs += 1;
                    break;
                }  
            }
            
        }

        return pairs;
            
    }
};
