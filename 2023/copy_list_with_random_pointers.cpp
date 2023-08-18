/*
The first appoarch could be to have a map storing new node coresponding to the 
old nodes, but that would introduce a space complexity of O(n), so now what I'm doing 
is creating new node and inserting them between old nodes first.
1->3->5
1->1->3->3->5->5

now we know that the random pointer to the new node is next to the random pointer of the old
node, so we update that. Afterwards we seperate the two lists and restore the links of the 
old list.
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* root = NULL, *cur=head, *temp;
        if(!head)
        {
            return head;
        }
        while(cur)
        {
            Node* node = new Node(cur->val);
            temp = cur->next;
            cur->next = node;
            node->next = temp;
            cur = temp;
        }
        temp = head;
        while(temp)
        {
           // cout<<temp->val<<"->";
            temp = temp->next;
        }
        root = head->next;
        cur = head;
        while(cur)
        {

            if(cur->random)
            {
                cur->next->random = cur->random->next;
            }else
            {
                cur->next->random = NULL;
            }
            temp = cur->next->next;
            cur = temp;
        }
        cur = head;
        while(cur)
        {
            temp = cur->next->next;
            if(temp)
            {
                cur->next->next = temp->next;
            }else
            {
                cur->next->next = NULL;
            }
            cur->next = temp;
            cur = temp;
        }
        cur = head;
        return root;
    }
};