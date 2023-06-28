class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        node_graph = defaultdict(list)
        e = len(edges)
        for i in range(0, e):
            node_graph[edges[i][0]].append([edges[i][1], succProb[i]])
            node_graph[edges[i][1]].append([edges[i][0], succProb[i]])
            
        max_prob = [0.0] * n    
        max_prob[start] = 1.0
        
        open_list = [start]
        while len(open_list) > 0:
            curr_node = open_list.pop(0)
            for child_node, path_prob in node_graph[curr_node]:
                if max_prob[curr_node] * path_prob > max_prob[child_node]:
                    max_prob[child_node] = max_prob[curr_node] * path_prob
                    open_list.append(child_node)
                    
        return max_prob[end]