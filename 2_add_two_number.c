#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

unsigned long long power(unsigned int base,unsigned int n){
    unsigned long long i, product = 1;
    for(i=0; i<n; i++)
        product *= base;
    return product;
}

unsigned long long get_num(struct ListNode* l){
    struct ListNode* tmp;
    unsigned int cnt;
    unsigned long long sum = 0;
    for(tmp=l,cnt=0;tmp;tmp=tmp->next,cnt++){
        if(tmp->val >=0 && tmp->val <= 9)
            sum += tmp->val * power(10,cnt);
    }
    return sum;    
}


struct ListNode* get_listnode(unsigned long long num){
    unsigned int ratio = 0;
    struct ListNode *head = NULL,*last = NULL, *new_node = NULL;
    for(; num>0; num /= 10){
        ratio = num % 10;
        new_node = malloc(sizeof(struct ListNode));
        new_node->val = ratio;
        new_node->next = NULL;
        if(!head){
            head = new_node;
            last = new_node;
        }
        else{
            last->next = new_node;
            last = new_node;
        }
    }
    if(!head){
        head = malloc(sizeof(struct ListNode));
        head->val = 0;
        head->next = 0;
    }
    return head;
}

void print_listnode(struct ListNode* l){
    for(;l;l = l->next)
        printf("%d ",l->val);
    printf("\n");
}

void insert_node(struct ListNode** tail, unsigned int val){
        struct ListNode* new_node = malloc(sizeof(struct ListNode));
        new_node->val = val;
        new_node->next = NULL;
        if(*tail)
            (*tail)->next = new_node;
        *tail = new_node;
        return;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    unsigned int carry = 0,sum = 0;
    struct ListNode *head = NULL, *tail = NULL, *left=NULL;
    while(l1 || l2){
        if (l1 && l2){
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if(l1){
            sum = l1->val + carry;
            l1 = l1->next;
        }
        else{
            sum = l2->val + carry;
            l2 = l2->next;
        }
        carry = 0;
        if(sum > 9){
            carry = sum / 10;
            sum = sum % 10;
        }
        else if(sum < 0){
            perror("invalid input!");
            exit(-1);
        }
        insert_node(&tail,sum);
        if(!head)
            head = tail;
    }
    if(carry){
        insert_node(&tail,carry);
    }
    return head;
}

int main(){
    unsigned int i1 = 46953, i2 = 98653457;
    struct ListNode *l1 = get_listnode(i1), *l2 = get_listnode(i2);
    print_listnode(l1);
    print_listnode(l2);
    printf("%d\n",i1+i2);
    print_listnode(addTwoNumbers(l1,l2));
    return 0;
}