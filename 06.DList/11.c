ListNode* reverse(ListNode* head)
{
    ListNode *pnode=head,*pre=NULL;   //pnode指向当前节点，pre指向前一节点
    while (pnode)                                      //当pnode！=null时，开始反转
    {
        ListNode* pnext=pnode->next;   //首先保存pnode的下一节点保存到pnext，否则反转（1）链时会丢失下一节点指向。
        pnode->next=pre;                       //反转（1）链，指向前一节点，当pnode为头节点时，pre指针为空。
        pnode->pre=pnext;  //反转（2）链，指向下一节点，当pnode为尾节点时，pnext指针为空。
        pre=pnode;     //反转完成，后移pre指针。
        pnode=pnext;     //后移pnode指针。
    }
    return pre;     //当pnode为Null时，说明已经反转完毕，它的前一节点pre指向尾节点。返回此节点指针。
}
