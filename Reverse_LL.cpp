#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    while (current != NULL)
    {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    head = prev;
    return head;
  }
};

// Function to print the list
void printList(ListNode *head)
{
  ListNode *temp = head;
  while (temp != NULL)
  {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

int main()
{

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  std::cout << "Original list: ";
  printList(head);

  Solution solution;
  head = solution.reverseList(head);

  std::cout << "Reversed list: ";
  printList(head);

  return 0;
}
