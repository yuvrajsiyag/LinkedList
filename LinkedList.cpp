#include <iostream>
using namespace std;
class Node{
	public:
		int key;
		int data;
		Node* next;
		Node() {
			key=0;
			data=0;
			next=NULL;
		}
		Node(int k,int d) {
			key=k;
			data=d;
		}
};
class SinglyLinkedList{
	public:
		Node* head;
		SinglyLinkedList()
		{
			head=NULL;
		}
		SinglyLinkedList(Node* n)
		{
			head=n;
		}
        // 1. check if node exist or not using key value
		Node* nodeExists(int k)
		{
			Node* temp=NULL;
			Node* ptr=head;
            while(ptr!=NULL)
            {
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr=ptr->next;
            }
            return temp;
		}
		// 2. Append a Node to the list
		void appendNode(Node* n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node Already Exists with key Value :"<<n->key<<". Append anoter node with different key value"<<endl;
			}
			else
			{
				if(head==NULL)
				{
					head=n;
					cout<<"Node Appended"<<endl<<endl;
				}
				else
				{
					Node* ptr=head;
					while(ptr->next!=NULL)
					{
						ptr=ptr->next;
					}
					ptr->next=n;
					cout<<"Node Appended"<<endl<<endl;
				}
			}
		}
		// 3. Prepend Node - Attach the Node at start
		void prependNode(Node* n)
		{
			if(nodeExists(n->key)!=NULL)
			{
				cout<<"Node Already Exists with key Value :"<<n->key<<". Append anoter node with different key value"<<endl;
			}
			else
			{
				n->next=head;
				head=n;
				cout<<"Node Prepended"<<endl;
		    }
		}
		// 4. Insert a Node after a particular Node in the list
		void insertNodeAfter(Node* n,int k)
		{
			if(nodeExists(n->key)==NULL)
			{
				cout<<"Node Already Exists with key Value :"<<n->key<<". Append anoter node with different key value"<<endl;
			}
			else
			{
				Node* ptr=nodeExists(k);
				if(ptr==NULL)
				{
					cout<<"No Node exists with key value :"<<k<<endl;
				}
				else
				{
					if(nodeExists(n->key)!=NULL)
					{
						cout<<"Node Already Exists with key Value :"<<n->key<<". Append anoter node with different key value"<<endl;
					}
					else
					{
						n->next=ptr->next;
						ptr->next=n;
						cout<<"Node Inserted"<<endl;
					}
			    }
			}
		}
		// 5. Delete Node by unique key
		void deleteNodeByKey(int k)
		{
			if(head==NULL)
			{
				cout<<"Singly linked list already empty. Cant't delete"<<endl;
			}
			/*else
			{
				Node* ptr=nodeExists(k);
				if(ptr==NULL)
				{
					cout<<"Node doesn't exist with key :"<<k<<endl;
				}
				else
				{
					ptr=ptr->next;
					cout<<"Node UNLINKED with key value :"<<k<<endl;
				}
			}*/
			else if(head!=NULL)
			{
				if(head->key==k)
				{
					head=head->next;
					cout<<"Node UNLINKED with key value :"<<k<<endl;
				}
				else
				{
					Node* temp=NULL;
					Node* prevptr=head;
					Node* currentptr=head->next;
					while(currentptr!=NULL)
					{
						if(currentptr->key==k)
						{
							temp=currentptr;
							currentptr=NULL;
						}
						else
						{
							prevptr=prevptr->next;
							currentptr=currentptr->next;
							
						}
					}
					if(temp!=NULL)
					{
						prevptr->next=temp->next;
						cout<<"Node UNLINKED with key :"<<k<<endl;
					}
					else
					{
						cout<<"Node Doesn't with key value :"<<k<<endl;
					}
				}
			}
		}
		// 6. Update node by key
		void updateNodeByKey(int k,int d)
		{
			Node* ptr=nodeExists(k);
			if(ptr!=NULL)
			{
				ptr->data=d;
				cout<<"Node data updated successfully with key value :"<<k<<endl;
			}
			else
			{
				cout<<"Node doesn't exist with key value :"<<k<<endl;
			}
		}
		// 7. Printing the list
		void printList()
		{
			if(head==NULL)
			{
				cout<<"No Nodes in singly linked list"<<endl;
			}
			else
			{
				cout<<endl<<"Singly linked list values :";
				Node* temp=head;
				while(temp!=NULL)
				{
					cout<<"("<<temp->key<<", "<<temp->data<<")-->";
					temp=temp->next;
				}
			}
		}
};
int main() {
	SinglyLinkedList s;
	int option;
	int key1,k1,data1;
	do {
		cout<<"What operation do you want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1. appendNode()"<<endl;
		cout<<"2. prependNode()"<<endl;
		cout<<"3. insertNodeAfter()"<<endl;
		cout<<"4. deleteNodeByKey()"<<endl;
		cout<<"5. updateNodeByKey()"<<endl;
		cout<<"6. printList()"<<endl;
		cout<<"7. clearScreen"<<endl<<endl;
		
		cin>>option;
		Node* n1 = new Node();
		// Node n1
		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Append node operation \nEnter key and data"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.appendNode(n1);
				break;
			case 2:
				cout<<"Prepend node operation \nEnter key and data"<<endl;
				cin>>key1;
				cin>>data1;
				n1->key=key1;
				n1->data=data1;
				s.prependNode(n1);
				break;
			case 3:
				cout<<"Insert node after operation \nEnter key and data of node and key of node where to insert"<<endl;
				cin>>key1;
				cin>>data1;
				cin>>k1;
				n1->key=key1;
				n1->data=data1;
				s.insertNodeAfter(n1,k1);
				break;
			case 4:
				cout<<"Delete node operation \nEnter key of node to delete"<<endl;
				cin>>k1;
				s.deleteNodeByKey(k1);
				break;
			case 5:
				cout<<"Update node operation \nEnter key of node to update and data"<<endl;
				cin>>k1;
				cin>>data1;
				s.updateNodeByKey(k1,data1);
				break;
			case 6:
				cout<<"Print LinkedList operation"<<endl;
				s.printList();
				break;
			case 7:
				system("cls");
				break;
			default :
				cout<<"Enter operation number: "<<endl;
		}
	} while(option!=0);
	return 0;
}
