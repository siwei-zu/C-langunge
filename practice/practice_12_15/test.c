//#define _CRT_SECURE_NO_WARNINGS 1
//
//struct ListNode* reverseList(struct ListNode* head) {//递归的方法
//    if (head == NULL || head->next == NULL)
//    {
//        return head;                                 //这个返回值即表示了特殊情况，也存储了最后一个节点储存在ret里面
//    }
//    struct ListNode* ret = reverseList(head->next);
//    head->next->next = head;//程序运行到这里时，操作的是递归时当前节点的下一个节点开始是下一个节点，把下一个结点的的next改为当前节点
//    head->next = NULL;//把当前节点的next设置为空指针，作为收尾工作。
//    return ret;
//}
//
//
//struct ListNode* reverseList(struct ListNode* head) {//迭代的方法
//    struct ListNode* pre = head;    
//    struct ListNode* cur = NULL;    
//    while (pre != NULL)            //创建两个节点用来反转整个链表，pre表示前面的，cur表示后面的，需要注意的是反转之前需要储存前往下一个节点的地址
//    {                              //之后在进行反转。不然找不到链表下一个节点
//        struct ListNode* tmp = pre->next;
//        pre->next = cur;
//        cur = pre;
//        pre = tmp;
//    }
//    return cur;
//}