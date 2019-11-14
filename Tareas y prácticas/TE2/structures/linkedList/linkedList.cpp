#define NULL 0
#include node.cpp

class linkedList{
  private:
  struct node *head, *tail;
  public:

  linkedList(){
    head=NULL;
    tail=NULL;
  }

  void createNode(int value){
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL){
      head=temp;
      tail=temp;
      temp=NULL;
    }
    else{ 
      tail->next=temp;
      tail=temp;
    }
  }

  void display(){
    node *temp=new node;
    temp=head;
    while(temp!=NULL){
      cout<<temp->data<<"\t";
      temp=temp->next;
    }
  }

  void insertStart(int value){
    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
  }

  void deleteFirst(){
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
  }

  void edit(int pos, int value){
    node *current = new node;
    
    current = head;

    for(int i=0;i<pos;i++){
      if(i == pos){
        current->data = value;
      }
    }

    //otra forma
    /*while(current->next!=NULL){
      if(i == pos){
        current->data = value;
      }    
    }
    current = current->next;*/
  }

  int getNode(int index){  
      
    node* current = head;  
 
    int count = 0;  
    while (current != NULL){  
        if (count == index){  
          return(current->data);
        }
        count++;  
        current = current->next;  
    }  
  
    /* if we get to this line,  
    the caller was asking  
    for a non-existent element  
    so we assert fail */
    assert(0);        
  }

  void int main(){

    linkedList obj;
    obj.createnode(25);
    obj.createnode(50);
    obj.createnode(90);
    obj.createnode(40);
    cout<<"\n--------------------------------------------------\n";
    cout<<"---------------Displaying All nodes---------------";
    cout<<"\n--------------------------------------------------\n";
    obj.display(); //25,50,90,40
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Inserting at Start----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.insert_start(10);
    obj.display(); //10,25,50,90,40
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Deleting at Start-----------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_first();
    obj.display(); //25,50,90,40
    cout<<"\n--------------------------------------------------\n";
    cout<<"--------------Delete at a position------------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_position(2);
    obj.display(); //25,50,40
    cout<<"\n--------------------------------------------------\n";
    cout<<"--------------Edit at a position------------------";
    cout<<"\n--------------------------------------------------\n";
    obj.edit(2,34);
    obj.display(); //25,50,34
    cout<<"\n--------------------------------------------------\n";
    cout<<"--------------Get node at a position------------------";
    cout<<"\n--------------------------------------------------\n";
    obj.getNode(2);
    obj.display(); //34
    cout<<"\n--------------------------------------------------\n";
    system("pause");
    return 0;
    
  }

};