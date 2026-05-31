
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//use of exptra space by creating new node everytime
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                tail->next = new ListNode(list2->val);
                list2 = list2->next;
            }

            tail = tail->next;
        }

        while (list1) {
            tail->next = new ListNode(list1->val);
            tail = tail->next;
            list1 = list1->next;
        }

        while (list2) {
            tail->next = new ListNode(list2->val);
            tail = tail->next;
            list2 = list2->next;
        }

        return dummy.next;
    }
};



//optimal approach
// When you first tried the problem, what caused trouble?
// Creating the first node
// Deciding the head
// Returning the correct head
// Handling an empty result list

//Whenever you see:
//"First node is different from all other nodes"
//a dummy node should come to mind.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;
        ListNode dummy(0);                  
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if(list1) tail->next=list1;
        else tail->next=list2;

        return dummy.next;
    }
};