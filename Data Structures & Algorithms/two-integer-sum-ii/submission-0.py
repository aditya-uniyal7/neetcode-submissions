class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        arr=numbers
        i=0
        j=len(arr)-1
        o=[]
        while(i<j):
            if arr[i]+arr[j]==target:
                o.append(i+1)
                o.append(j+1)
                return o
            else:
                if arr[i]+arr[j] > target:
                    j-=1
                else:
                    i+=1