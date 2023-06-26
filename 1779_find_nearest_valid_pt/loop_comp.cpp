class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_dist = 999999;
        int min_idx = -1;
        for(int i = 0; i < points.size(); i++)
        {
            if(points[i][0] == x || points[i][1] == y)
            {
                if (abs(points[i][0] - x) + abs(points[i][1] - y) < min_dist)
                {
                    min_idx = i;
                    min_dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                }
            }
        }
        return min_idx;
    }
};
