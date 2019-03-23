#include<iostream>
using namespace std;
struct node{
  int num;
  struct node *next;
};
void qu(int n,struct node **root,struct node **endi){
  struct node *temp=new node;
  temp->num=n;
  temp->next=NULL;
  if(*root==NULL){
    *root=temp;
    *endi=temp;
  }else{
    (*endi)->next=temp;
    *endi=temp;
  }
}

void show(struct node** root){
  struct node *temp=*root;
  while(temp!=NULL){
    cout<<temp->num<<endl;
    temp=temp->next;
  }
}
int deq(struct node **root){
  struct node *temp=*root;
  int a;
  a=temp->num;
  *root=temp->next;
  return a;
}
int isemp(struct node **root){
  if(*root==NULL)
    return 1;
  else
    return 0;
}
void st(struct node **root,int k ){
  struct node *temp=new node;
  temp->num=k;
  temp->next=*root;
  *root=temp;
}
void print_path(struct node **root){
  struct node *temp=*root;
  while(temp!=NULL){
    cout<<temp->num<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
int main(){
  struct node* head,*head1, *end;
  head=NULL;
  head1=NULL;
  end=NULL;
  int n=7,i;
  int m,mot=5;
  int a,j,b[7]={0};
  int arr[7][7] = {{0, 0, 1, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 1, 0},
      {0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0}
  };
  for(m=0; m<n; m++){
      if(b[m]==0){
          b[m]=1;
          mot=m;
          int k=m;
          int y=0;
          st(&head,m);
          while(!isemp(&head)){
              y=0;
              i=0;
              while(i<n){
                  if(arr[k][i]==1 && b[i]==0){
                      st(&head,i);
                      y=1;
                      b[i]=1;
                      k=i;
                      i=0;
                  }
                 i++;
              }
            int check_pop=0;
           if(y==0){
             k=head->num;
              for(i=0;i<n;i++){
                if(arr[k][i]==1&&b[i]!=1){
                      check_pop=1;
                      break;
                }
              }
              if(check_pop==0){
                k=deq(&head);
                st(&head1,k);
            }
          }
        }
      }
    }
    int topo_sor[n];
    i=0;
    cout<<"topological sort is:"<<endl;
    struct node *temp= head1;
    while(temp!=NULL){
     cout<<temp->num<<" "<<flush;
     topo_sor[i]=temp->num;
     i++;
     temp=temp->next;
    }
    cout<<endl;
    int no_of_edg=0;
    for(i=0;i<n;i++)
    {
       for(j=i+1;j<n;j++)
        {
           if(arr[i][j]==0)
              no_of_edg++;
        }
    }
    cout<<"maximum no of edges can be inserted is:"<<no_of_edg<<endl;
}
