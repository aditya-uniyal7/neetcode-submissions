class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Step 1: ginti karo
        count = {}
        for num in nums:
            if num in count:
                count[num] += 1
            else:
                count[num] = 1
        
        # Step 2: pairs banao (count, number)
        pairs = []
        for num in count:
            pairs.append((count[num], num))
        
        # Step 3: sort karo, sabse zyada pehle
        pairs.sort(reverse=True)
        
        # Step 4: pehle k numbers nikaal lo
        result = []
        for i in range(k):
            result.append(pairs[i][1])
        
        return result