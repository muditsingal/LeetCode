class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        pq = [(nums1[0]+nums2[0], (0,0))]
        visited = [(0,0)]
        l1 = len(nums1)
        l2 = len(nums2)
        res = []
        cntr=0
        while cntr < k and len(pq)>0:
            curr_sum, (i,j) = heapq.heappop(pq)
            res.append((nums1[i], nums2[j]))
            if j+1 < l2 and (i,j+1) not in visited:
                heapq.heappush(pq, (nums1[i] + nums2[j+1], (i, j+1)))
                visited.append((i,j+1))
            if i+1 < l1 and (i+1,j) not in visited:
                heapq.heappush(pq, (nums1[i+1] + nums2[j], (i+1, j)))
                visited.append((i+1,j))
            cntr += 1
        return res
        