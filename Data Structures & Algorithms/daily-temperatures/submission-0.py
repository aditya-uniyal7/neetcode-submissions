class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        t = temperatures
        n = len(t)
        result = [0] * n
        stack = [] 

        for i in range(n):
            while stack and t[stack[-1]] < t[i]:
                j = stack.pop()
                result[j] = i - j
            stack.append(i)

        return result