class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *cur = head, *prev = NULL, *temp = NULL;
    while (cur) {
      prev = cur;
      cur = cur->next;
      prev->next = temp;
      temp = prev;
    }
    return prev;
  }
};