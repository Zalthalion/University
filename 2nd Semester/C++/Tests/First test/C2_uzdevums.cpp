#include<iostream>
#include "lvfriendly.h"
using namespace std;
struct elem {
    int value;
    elem *next;
};

bool monotomousweak(elem *&start){
if(start==false or start->next == false) return false;
elem *p = start->next;
int current = start->value;
while (p !=NULL){
    if(current > p->value)return false;
    current = p->value;
    p=p->next;
}return true;


}

int main() {
    elem *start=NULL, *last;
    int a[4]={4,3,3,1};
    /// creating
    for(int i=0;i<4;i++) {
        elem *p = new elem; /// s1
        p->value=a[i]; /// s2
        p->next=NULL; /// s3
        if(start==NULL) start=p; /// s4a
        else last->next=p; /// s4b
        last=p; /// s5
    }
    /// printing
    elem *p=start;
    while (p!=NULL) {
        cout<<p->value<<" ";
        p=p->next;
    }
    cout << monotomousweak(start) << endl;
    /// deleting
    p = start; /// 1
    while (p!=NULL) {
        start = p->next; /// 2
        delete p; /// 3
        p=start; /// 4
    }
}

