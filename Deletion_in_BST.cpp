#include<iostream>

using namespace std;

struct node{
    int data;
    node *lchild;
    node *rchild;
} *root=0;

node *Iterative_Search_BST(node *p,int key){
    if(p==NULL){
        cout<<"BST is empty"<<endl;
        return 0;
    }
    else{
        while(p){
            if(p->data==key){
                return p;
            }
            else if(p->data<key){
                p=p->rchild;
            }
            else{
                p=p->lchild;
            }
        }
        return 0;
    }
}

node *Recursive_Search_BST(node *p, int key){
    if(p==NULL){
        return 0;
    }
    else if(p->data==key){
        return p;
    }
    else if(p->data<key){
        return Recursive_Search_BST(p->rchild,key);
    }
    else{
        return Recursive_Search_BST(p->lchild,key);
    }
}

void Insertion(node *p, int key){
    node *r=0;

    node *n=new(node);
    n->data=key;
    n->lchild=n->rchild=0;

    if(root==NULL){
        root=n;
    }
    else{
        int flag=0;
        while(p){
            if(p->data==key){
                flag=1;
                break;
            }
            else if(p->data<key){
                r=p;
                p=p->rchild;
            }
            else{
                r=p;
                p=p->lchild;
            }
        }
        if(flag==0){
            if(r->data<key){
                r->rchild=n;
            }
            else{
                r->lchild=n;
            }
        }
    }
}
int height(node *p){
    int x,y;
    if(p){
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y){
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0;
}

void Deleting_BST(node *p, int key){
    node *r=0;
    int flag=0;
    while(p){
        if(p->data<key){
            r=p;
            p=p->rchild;
        }
        else if(p->data>key){
            r=p;
            p=p->lchild;
        }
        else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        if(p->rchild==0 && p->lchild==0){
            if(p->data<r->data){
                r->lchild=0;
                delete p;
            }
            else{
                r->rchild=0;
                delete p;
            }
        }
        else if(p->lchild && p->rchild){
            node *q=p->rchild;
            node *s=0;
            if(q->lchild==0){
                q->lchild=p->lchild;
                if(p->data<r->data){
                    r->lchild=q;
                }
                else{
                    r->rchild=q;
                }
                delete p;
            }
            else{
                while(q->lchild){
                    s=q;
                    q=q->lchild;
                }
                s->lchild=q->rchild;
                q->lchild=p->lchild;
                q->rchild=p->rchild;
                if(r==0){
                    root=q;
                }
                else if(p->data<r->data){
                    r->lchild=q;
                }
                else{
                    r->rchild=q;
                }
                delete p;
            }
        }
        else if(p->rchild || p->lchild){
            if(p->rchild){
                if(p->data<r->data){
                    r->lchild=p->rchild;
                }
                else{
                    r->rchild=p->rchild;
                }
            }
            else if(p->lchild){
                if(p->data<r->data){
                    r->lchild=p->lchild;
                }
                else{
                    r->rchild=p->lchild;
                }
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Insertion(root,x);
    }
    cout<<height(root)-1<<endl;
    int key;
    cin>>key;
    Deleting_BST(root,key);
    cout<<height(root)-1<<endl;
    cout<<root->data<<endl;
    cout<<root->rchild->data<<endl;
}