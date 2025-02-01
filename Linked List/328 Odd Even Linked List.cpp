class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head)
      return NULL;

    ListNode *first, *second, *tempSecond;
    first = head;

    if (head->next) {
      second = first->next;
      tempSecond = first->next;
    } else {
      return head;
    }

    while (second && second->next) {
      first->next = second->next;
      first = first->next;
      second->next = first->next;
      second = second->next;
    }

    first->next = tempSecond;
    return head;
  }
};
