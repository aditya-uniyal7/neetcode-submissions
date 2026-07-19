class Solution:
  def maxArea(self, heights: List[int]) -> int:
       
    max_area = 0
    n = len(heights)
    
    for i in range(n):              
        for j in range(i+1, n):    
            width = j - i
            h = min(heights[i], heights[j])
            area = width * h
            max_area = max(max_area, area)
    
    return max_area 