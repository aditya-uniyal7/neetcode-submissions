# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        tempo=head
        temp=head
        c=0
        temps=0
        while tempo!=None:
            c+=1
            tempo=tempo.next
        if c == n:
            return head.next

        temp = head
        for _ in range(c - n - 1):
            temp = temp.next
            
        temp.next = temp.next.next
        
        return head