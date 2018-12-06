#include <vector>
#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};
node* head;
class mylist
{
private:
  node *head, *tail;

public:
  mylist();
  ~mylist();
  void push_front(int);
  void push_back(int);
  void print_list();
  void reverse();
  void Delete(int n);
  void inesert_at_position(int,int);
  void Delete_at_position(int n);  
};

mylist::mylist()
{
  head = NULL;
  tail = NULL;
}

mylist::~mylist()
{
  int c = 0;
  struct node *curr = head;
  while (curr != NULL)
  {
    c++;
    struct node *temp = curr;
    curr = curr->next;
    delete temp;
  }
  cout << endl
       << c << " nodes deallocated from memory" << endl;
}

void mylist::push_front(int value)
{
  node *temp = new node;
  temp->data = value;
  temp->next = head;
  if (head == NULL)
    tail = temp;
  head = temp;
}

void mylist::push_back(int value){
  node *temp = new node;
  temp->data = value;
  temp->next = tail;
  if(tail == head)
    head = temp;
  tail = temp;
}

//find function
bool find(node* head,int element){
  node* current = head;
  while(current != NULL){
    if(current->data == element)
        return true;
    current = current->next;

  }
  return false;

}//end find

//insert at position
void mylist::inesert_at_position(int data,int n){
  node* temp1 = new node();
  temp1->data = data;
  temp1->next = NULL;
  if(n==1){
    temp1->next = head;
    head = temp1;
    return;
  }
  node* temp2 = head;
  for(int i =0; i<n-2;i++){
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

//delete at position
void mylist::Delete_at_position(int n) {
  node* temp1 = head;
  if(n==1){
    head = temp1->next;
    free(temp1);
  }
  int i;
  for(int i=0;i<n-2;i++)
    temp1 = temp1->next;
  
  node* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);
}



//reverse list
void mylist::reverse(){
  node *current = head;
  node* prev = NULL, *next = NULL;

  while(current != NULL){
    next = current->next;
    current->next = prev;

    prev = current;
    current = next;
  }
  head = prev;



}//end reverse


void mylist::print_list()
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}

int main()
{
  vector<int> a = {5, 7, 13, 21, 16};
  mylist alist;
  
  for (int x : a)
    alist.push_front(x);
  cout << "Single Linked List " << endl;
  alist.print_list();
  cout<<endl;
  cout<<endl;

  vector<int> t ={1,2,3};
  mylist tlist;
  for(int y : t)
    tlist.push_back(y);
  tlist.print_list();

  cout<<endl;
  cout<<endl;
  alist.reverse();
  alist.print_list();
  cout<<endl;

  alist.inesert_at_position(1,1);
  alist.print_list();
  cout<<endl;

  alist.Delete_at_position(2);
  alist.print_list();
  cout<<endl;
  
  

  


  

  return 0;
}