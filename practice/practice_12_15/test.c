//#define _CRT_SECURE_NO_WARNINGS 1
//
//struct ListNode* reverseList(struct ListNode* head) {//�ݹ�ķ���
//    if (head == NULL || head->next == NULL)
//    {
//        return head;                                 //�������ֵ����ʾ�����������Ҳ�洢�����һ���ڵ㴢����ret����
//    }
//    struct ListNode* ret = reverseList(head->next);
//    head->next->next = head;//�������е�����ʱ���������ǵݹ�ʱ��ǰ�ڵ����һ���ڵ㿪ʼ����һ���ڵ㣬����һ�����ĵ�next��Ϊ��ǰ�ڵ�
//    head->next = NULL;//�ѵ�ǰ�ڵ��next����Ϊ��ָ�룬��Ϊ��β������
//    return ret;
//}
//
//
//struct ListNode* reverseList(struct ListNode* head) {//�����ķ���
//    struct ListNode* pre = head;    
//    struct ListNode* cur = NULL;    
//    while (pre != NULL)            //���������ڵ�������ת��������pre��ʾǰ��ģ�cur��ʾ����ģ���Ҫע����Ƿ�ת֮ǰ��Ҫ����ǰ����һ���ڵ�ĵ�ַ
//    {                              //֮���ڽ��з�ת����Ȼ�Ҳ���������һ���ڵ�
//        struct ListNode* tmp = pre->next;
//        pre->next = cur;
//        cur = pre;
//        pre = tmp;
//    }
//    return cur;
//}