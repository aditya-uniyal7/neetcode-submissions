class Solution(object):
    def maxProfit(self, prices):
        buy = prices[0] 
        max_profit = 0
        
        for i in range(1, len(prices)):
            if prices[i] < buy:
                buy = prices[i]
                
            elif prices[i] - buy > max_profit:
                max_profit = prices[i] - buy
                
        return max_profit