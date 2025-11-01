#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> map(nums.begin(), nums.end());

        while(head && map.count(head->val)){
            head = head -> next;
        }

        ListNode* curr = head;
        while(curr && curr->next){
            if(map.count(curr->next->val)){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }

        return head;
    }

    ListNode* modifiedList_1(vector<int>& nums, ListNode* head) {
        unordered_set<int> mp(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;

        while(curr->next != nullptr){

            if(mp.find(curr->next->val) != mp.end()){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                // delete temp;
            }else{
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        // delete dummy;
        return newHead;
    }
};


int main(){
    Solution sobj;

    vector<int> nums = {1, 2, 3};

    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);
    ListNode* five = new ListNode(5);

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;

    ListNode* ret = sobj.modifiedList(nums, one);

    ListNode* temp = one;
    cout<<"Original List : "<<endl;
    while(temp != nullptr){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;

    cout<<"Modified List : "<<endl;
    temp = ret;
    while(temp != nullptr){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}


