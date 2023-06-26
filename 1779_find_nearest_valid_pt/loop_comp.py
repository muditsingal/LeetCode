class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        min_dist = 999999
        min_idx = -1
        for i in range(0, len(points)):
            if points[i][0] == x or points[i][1] == y:
                curr_dist = abs(points[i][0]-x) + abs(points[i][1]-y)
                if curr_dist < min_dist:
                    min_dist = curr_dist
                    min_idx = i

        return min_idx
