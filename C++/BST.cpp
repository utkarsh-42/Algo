#include <iostream>
#include <queue>
#include <stack>
struct node {
    int data  ;
    node *left ;
    node *right ;
} ;

class BST {
    public : 
    node *root ;
    BST() {
        root = NULL ;
    }
    
    void insert(int value) {
        node *key = new node ;
        key->data = value ;
        key->left = NULL ;
        key->right = NULL ;
        if(root == NULL) {
            root = key ;
            return ;
        }
        node* temp = new node ; 
        temp = root ;
        while(true) {
            if( temp->data > value) {
                 if(temp->left == NULL) {
                     temp->left = key ;
                    return;
                }
                 temp = temp->left ;
                }
            else {
                if(temp->right == NULL) {
                    temp->right = key ;
                    return ;
                }
                temp = temp->right ;
            }
            
        }
    }
    
    void inorder(node *root) {
        if(root == NULL) {
            return ;
        }
        if(root!=NULL) {
            inorder(root->left);
            std::cout<<root->data<<", " ;
            inorder(root->right);
        }
    }
    
    void preorder(node *root) {
        if(root == NULL) {
            return ;
        }
        if(root!=NULL) {
            std::cout<<root->data<<", " ;
            preorder(root->left);
            preorder(root->right);
        }
    }
    
    void postorder(node *root) {
        if(root == NULL) {
            return ;
        }
        if(root!=NULL) {
            postorder(root->left);
            postorder(root->right);
            std::cout<<root->data<<", " ;
        }
    }
    
    void LevelOrder(node* root) {
        if(root==NULL) return ;
        std::queue<node*> Q ;
        Q.push(root);
        while(!Q.empty()) {
            node* current = Q.front();
            Q.pop();
            std::cout<<current->data<<" " ;
            if(current->left != NULL) Q.push(current->left);
            if(current->right != NULL) Q.push(current->right);
               
        }
    }
    void InorderIte(node* root) {
    std::stack<node*> s ;
    node* current = root;
    while(!s.empty()|| current !=NULL) {
        if(current != NULL) {
            s.push(current);
            current = current->left ;
            }
        else{
            current = s.top();
            s.pop();
            std::cout<<current->data<<" ";
            current = current->right ;
            }
        }
    }    
};


int main() {
    BST myTree ;
    
    myTree.insert(11);
    myTree.insert(4);
    myTree.insert(15);
    myTree.insert(2);
    myTree.insert(13);
    myTree.insert(17);
    myTree.inorder(myTree.root);
    std::cout<<"\n";
    // myTree.preorder(myTree.root);
    // std::cout<<"\n";
    myTree.LevelOrder(myTree.root);
    
    return 0 ;
}
