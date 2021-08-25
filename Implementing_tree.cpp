#include<iostream>
using namespace std;

struct node{
    int data;
    node *rchild;
    node *lchild;
} *root=0;

struct Queue{
    node *pointer;
    Queue *next;
} *front=0, *rear=0;

struct Stack{
    node *n;
    Stack *st;
} *top=0;

void push(node *x){
    Stack *s=new(Stack);
    if(s==0){
        cout<<"Stack Full"<<endl;
    }
    else{
        s->n=x;
        s->st=top;
        top=s;
    }
}
node *pop(){
    node *np=0;
    if(top==0){
        cout<<"Stack Empty"<<endl;
    }
    else{
        Stack *t=top;
        np=top->n;
        top=top->st;
        delete t;
    }
    return np;
}

void enqueue(node *x){
    Queue *q=new(Queue);
    if(q==0){
        cout<<"Queue is full!"<<endl;
    }
    else{
        q->pointer=x;
        q->next=0;
        if(front==0){
            front=rear=q;
        }
        else{
            rear->next=q;
            rear=rear->next;
        }
    }
}
node *dequeue(){
    node *x=0;
    if(front==0){
        cout<<"Queue is empty!"<<endl;
    }
    else{
        Queue *q=front;
        x=q->pointer;
        front=front->next;
        delete q;
    }
    return x;
}

void create(){
    int x;
    cout<<"Enter the root= ";
    cin>>x;
    node *n=new(node);
    n->data=x;
    n->lchild=0;
    n->rchild=0;
    root=n;
    enqueue(n);
    while(front){
        int x,y;
        node *n=dequeue();
        cout<<"Enter the lchild of "<<n->data<<" = ";
        cin>>x;
        if(x!=-1){
            node *n1=new(node);
            n1->data=x;
            n1->lchild=0,n1->rchild=0;
            n->lchild=n1;
            enqueue(n1);
        }
        cout<<"Enter the rchild of "<<n->data<<" = ";
        cin>>y;
        if(y!=-1){
            node *n2=new(node);
            n2->data=y;
            n2->lchild=0,n2->rchild=0;
            n->rchild=n2;
            enqueue(n2);
        }
    }
}
void Preorder(node *p){
    if(p){
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(node *p){
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}
void Postorder(node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Iterative_Preorder(node *p){
    cout<<p->data<<" ";
    push(p);
    p=p->lchild;
    while(top!=0 || p!=0){
        if(p!=0){
            cout<<p->data<<" ";
            push(p);
            p=p->lchild;
        }
        else if(p==0){
            p=pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}
void Iterative_Inorder(node *p){
    push(p);
    p=p->lchild;
    while(top || p){
        if(p==0){
            p=pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
        else{
            push(p);
            p=p->lchild;
        }
    }
    cout<<endl;
}
void Iterative_Postorder(node *p){
    if(p->rchild){
        push(p->rchild);
    }    
    push(p);
    p=p->lchild;
    while(top || p){
        if(p==0){
            p=pop();
            if(top==0){
                cout<<p->data<<" ";
                p=0;
            }
            else if(p->rchild==0){
                cout<<p->data<<" ";
                p=0;
            }
            else if(p->rchild==top->n){
                node *q=pop();
                push(p);
                p=q;
            }
            else{
                cout<<p->data<<" ";
                p=0;
            }
        }
        else{
            if(p->rchild){
                push(p->rchild);
            }
            push(p);
            p=p->lchild;
        }
    }
    cout<<endl;
}
void LevelOrderTraversal(node *p){
    cout<<p->data<<" ";
    enqueue(p);
    while(front){
        p=dequeue();
        if(p->lchild){
            cout<<p->lchild->data<<" ";
            enqueue(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            enqueue(p->rchild);
        }
    }
    cout<<endl;
}

int main(){
    create();
    Preorder(root);
    cout<<endl;
    Iterative_Preorder(root);
    Inorder(root);
    cout<<endl;
    Iterative_Inorder(root);  
    Postorder(root);
    cout<<endl;
    Iterative_Postorder(root);
    LevelOrderTraversal(root);
}