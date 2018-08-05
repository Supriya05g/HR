# https://leetcode.com/problems/projection-area-of-3d-shapes/description/

class Solution:
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        xy=len(grid)*len(grid[0])
        for row in grid:
            xy=xy-row.count(0)
        
        yz=0
        for row in grid:
            yz=yz+max(row)
        
        new_list=zip(*grid)
        
        xz=0
        for row in grid:
            xz=xz+max(row)
        return xz+xy+yz