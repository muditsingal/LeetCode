import numpy as np

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        n = len(grid)
        grid_arr = np.array(grid)
        grid_T = grid_arr.T
        n_pairs = 0
        for i in range(n):
            n_pairs += (n - np.count_nonzero(np.sum(np.abs(grid_T - np.roll(grid_arr, shift=i, axis=1)), axis=0)))

        return n_pairs
