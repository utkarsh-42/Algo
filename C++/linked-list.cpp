#include <iostream>
using namespace std;

struct node {
    int data ; 
    node *next ; 
}; 

class list {
    private: 
    // node *head, *tail ;
    node *head ;
    public: 
    list(){
        head = NULL;
        // tail = NULL;
    }
    void insertBeg(int value) {
        node *temp = new node ; 
        temp->data = value ;
        temp->next = head ; 
        head = temp ;
    }
    
    void insertLast(int value) {
        node *temp = new node ; 
        temp->data = value ; 
        temp->next = NULL ; 
        if(head==NULL) {
           head = temp ;
           
        }
        else {
            node *temp1 = new node ;
            temp1 = head ; 
            while(temp1->next!=NULL) {
                temp1 = temp1->next ;
            }
            temp1->next = temp ;
        }
        
        
    }
    
    bool find(int value) {
        if (head==NULL) { return false ; }
        node* temp = new node ;
        temp = head ;
        while(temp !=NULL) {
            if(temp->data==value) {
                
                return true ;
            }
            temp = temp->next ;
        } 
        
        return false ;
    }
    void print() {
        node* temp = new node ;
        temp = head ;
        
        while(temp !=NULL) {
            cout<<temp->data<<"-->" ;
            temp = temp->next ;
        }
        
    }
    
};


int main() {
	list myList ; 

	myList.insertLast(100);
	myList.insertBeg(40);
	myList.insertLast(1);
	myList.insertLast(120);
	myList.insertBeg(41);
	myList.insertLast(11);
	cout<<"\n";
	myList.print();
	if(myList.find(11)) {
	    cout<<"\n"<<"found";
	}
	
	return 0 ;
}
