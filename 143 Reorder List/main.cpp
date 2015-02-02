//
//  main.cpp
//  List Reorder
//
//  Created by JiaDuan on 14-8-30.
//  Copyright (c) 2014年 jdnull. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head) {
    if (head == NULL || head->next == NULL) return ;
    
    int count = 0, ascendCount;
    ListNode *p = head, *q = NULL, *ascendHead = head, *descendHead = NULL;
    
    while(p != NULL) {
        count++;
        p = p->next;
    }
    ascendCount = count / 2;
    if (count % 2 != 1) {
        ascendCount--;
    }
    
    p = head;
    while (ascendCount != 0) {
        ascendCount--;
        p = p->next;
    }
    descendHead = p->next;
    p->next = NULL;
    
    p = descendHead->next;
    descendHead->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = descendHead;
        descendHead = p;
        p = q;
    }
    
    p = ascendHead->next;
    while (descendHead != NULL) {
        ascendHead->next = descendHead;
        q = descendHead->next;
        ascendHead = p;
        if (ascendHead == NULL) {
            break;
        }
        p = ascendHead->next;
        descendHead->next = ascendHead;
        descendHead = q;
    }
}

int main(int argc, const char * argv[])
{
    int init = 7;
    ListNode *head = new ListNode(1);
    ListNode *t = head;
    ListNode *p = NULL;
    for (int i = 2; i <= init; i++) {
        p = new ListNode(i);
        t->next = p;
        t = t->next;
    }
    reorderList(head);
    t = head;
    while (t != NULL) {
        cout << t->val << endl;
        delete t;
        t = t->next;
    }
    head = NULL, t = NULL;
    return 0;
}

