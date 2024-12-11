#include <iostream>

using namespace std;
struct node
{
    int data;
    node*next;
};
void deleteinoAtposition(node*head,int n,int pos)
{
    if(pos<0||pos>n)
    {
        cout<<"invalid position"<<endl;
    }
    else{
        if(pos==0)
        {
            node*todelete = head;
            head = head->next;
            delete todelete;
        }
        else{
            node*temp = head;
            for(int i = 0;i<pos-1;i++)
            {
                temp =  temp->next;
            }
            node*todelete = temp->next;
            temp->next = todelete->next;
            delete todelete;
        }
    }
    n--;
      node* temp = head;
    cout << "New Linked list after deletion: ";
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    cout<<"Enter the number of element in linked list: ";
    int n;
    cin>>n;
    node*head =nullptr,*temp = nullptr,*newnode = nullptr;
    for(int i = 0;i<n;i++)
    {
        newnode = new node;
        cin>>newnode->data;
        newnode->next = nullptr;
        if(head == nullptr)
        {
            head = newnode;
        }
        else{
            temp ->next = newnode;
        }
        temp = newnode;
    }
    temp = head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    temp = head;
    cout<<"Enter the position to delete - ";
    int pos;
    cin>>pos;
    deleteinoAtposition(head,n,pos);

    return 0;
}
