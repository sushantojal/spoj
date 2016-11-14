#include <iostream>
using namespace std;

class node
{       
    public:
        
        int key;
        node *left;
        node *right;
        node *parent;
};

class btree
{
    public:
        node *root;
        node* makenode(int);
        void setleft(node*, int);
        void setright(node*, int);
        void intrav(node*);
        void pretrav(node *);
        void posttrav(node *);
        node* search(node*,int);
        btree();
};

btree::btree()
{
    root=NULL;
}    

node* btree::makenode(int x)
{
    node *newnode= new node;
    newnode->key=x;
    newnode->right=NULL;
    newnode->left=NULL;
    //newnode->parent=NULL;
    if(root==NULL)
    root= newnode;
    return newnode;
}

void btree::setleft(node *nodeptr, int x)
{
    if((nodeptr==NULL)||(nodeptr->left!=NULL))
    {  
        cout<<"void insertion"<<endl;
        return;
      }else
          nodeptr->left= makenode(x);
}

void btree::setright(node *nodeptr, int x)
{
    if((nodeptr==NULL)||(nodeptr->right!=NULL))
    {
        cout<<"void insertion"<<endl;
        return;
    }else
        nodeptr->right=makenode(x);
}

void btree::intrav(node *nodeptr)
{
    if(nodeptr!=NULL)
    {
        intrav(nodeptr->left);
        cout<<nodeptr->key<<endl;
        intrav(nodeptr->right);
    }
}

void btree::pretrav(node *nodeptr)
{
    if(nodeptr!=NULL)
    {
        cout<<nodeptr->key<<endl;
        pretrav(nodeptr->left);
        pretrav(nodeptr->right);
    }
}

void btree::posttrav(node *nodeptr)
{
    if(nodeptr!=NULL)
    {
        posttrav(nodeptr->left);
        posttrav(nodeptr->right);
        cout<<nodeptr->key<<endl;
    }
}

node* btree::search(node *nodeptr,int x)
{
    if(nodeptr!=NULL)
    {
        if(x==nodeptr->key)
        return nodeptr;
        else{
        search(nodeptr->left, x);
        search(nodeptr->right, x);}
    }else return NULL;
}        
        


int main()
{
    int x;
    cout<<"value for root node??"<<endl;
    cin>>x;
    btree obj1;
    node *nodeptr2= obj1.makenode(x);
    bool count=0;
    int var1;
    int var2;
    while(count==0)
    {
        cout<<"key of node after which a new node is to be inserted??"<<endl;
        cin>>x;
        node *nodeptr=obj1.search(obj1.root, x);
        cout<<nodeptr->key<<endl;
        cout<<"1 for inserting left node\n 2 for inserting right node\n 3 if tree is complete\n";
        cin>>var1;
        switch(var1)
        {
                case 1:
                    cout<<"value of key in the left node??\n";
                    cin>>var2;
                    obj1.setleft(nodeptr, var2);
                    
                    break;
                case 2:
                    cout<<"value of key in the right node??\n";
                    cin>>var2;
                    obj1.setright(nodeptr, var2);
                    break;
                case 3:
                    count=1;
                    break;
        }
    }
    int var3;
    cout<<"1 for inorder traversal\n 2 for preorder traversal\n 3 for postorder traversal\n";
    cin>>var3;
    switch(var3)
    {
        case 1:
            obj1.intrav(obj1.root);
            break;
        case 2:
            obj1.pretrav(obj1.root);
            break;
        case 3:
            obj1.posttrav(obj1.root);
            break;
    }
    system("pause");
}
                        
                
        
                    
            
    
            

    

        
