#include<iostream>

using namespace std;
struct elem {
    int value;
    elem *next;
};
void print(elem *start) {
    elem *p=start;
    while (p!=NULL) {
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl;
}
void insert2ndlast(elem*&start,int n) {
    if(start==false or start->next==NULL) return;
    elem *q=new elem();
    q->value=n;
    if (start->next->next==NULL) {
        q->next = start;
        start = q;
    }
    else {
        elem *p=start;
        while (p->next->next->next!=NULL) {
            p=p->next;
        }
        q->next=p->next;
        p->next=q;
    }
}
int main() {
    elem *start=NULL, *last;
    int a[5]={1,2,3,3,5};
    /// creating
    for(int i=0;i<5;i++) {
        elem *p = new elem; /// s1
        p->value=a[i]; /// s2
        p->next=NULL; /// s3
        if(start==NULL) start=p; /// s4a
        else last->next=p; /// s4b
        last=p; /// s5
    }
    print(start);
    /// processing
    insert2ndlast(start,99);
    print(start);
    /// deleting
    elem *p = start; /// 1
    while (p!=NULL) {
        start = p->next; /// 2
        delete p; /// 3
        p=start; /// 4
    }
}

