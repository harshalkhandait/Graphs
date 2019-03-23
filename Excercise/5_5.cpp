#include<iostream>
using namespace std;
struct node {
  int data;
  struct node *next;
};
struct node* newNode(int data){
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}
void printStack(struct node* root){
  while(root!=NULL){
    printf("%d ",root->data);
    root=root->next;
  }
}
int isEmpty(struct node* root){
  if(root==NULL)
    return 1;
  return 0;
}
struct node* push(struct node* root, int data){
  if(root == NULL)
    return newNode(data);
  root->next = push(root->next, data);
}
struct node* popStack(struct node* root){
  int i=0;
  if(root==NULL){
    return NULL;
  }
  struct node* temp=NULL;
  struct node* temp2=NULL;
  temp = root;
  if(temp->next==NULL){
    root=NULL;
    return root;
  }
  while(temp->next != NULL){
    temp2=temp;
    temp = temp->next;
    i++;
  }
  temp2->next=NULL;
  return root;
}
int peekStack(struct node* root){
  while(root->next != NULL){
    root=root->next;
  }
  return root->data;
}
//basic structure of graph
struct Graph{
  int V;
  int E;
  int Adj[10][10] ;
};
void printGraph(struct Graph *G){
  for(int u=0;u<G->V;u++){
    for(int v=0;v<G->V;v++)
      cout<<G->Adj[u][v]<<" ";
    cout<<"\n";
  }
}
struct Graph* ajdMatrixOfGraph(){
  int u,v,i,counter=0;
  struct Graph *G = new Graph;
  cout<<"Enter the number of Nodes :";
  std::cin >> G->V;
  G->E = G->V*(G->V-1);
  for(u=0;u<G->V;u++){
    for(v=0;v<G->V;v++){
      G->Adj[u][v]=0;
    }
  }
  std::cout << "Enter the node numbers to connect(space seprated) (-1, -1 to exit) " << '\n';;
  for(i=0;i<G->E;i++){
    std::cin >> u >> v;
    if (counter<G->E) {
      if (u == -1 && v == -1) {
        break;
      }else{
        if (u > G->V || v > G->V || u < 0 || v < 0) {
          std::cout << "Wrong Details !! Please re-enter" << '\n';
        } else {
          G->Adj[u][v]=1;
          G->Adj[v][u]=1;//bidirection graph
          counter++;
        }
      }
    } else {
      std::cout << "Number of connection exected" << '\n';
    }
  }
  return(G);
}
int dfs(struct Graph *G,int vn,int dn){
  int count=0;
  int *visited = new int[G->V];
  for(int i=0;i<G->V;i++)
    visited[i] = 0;
  struct node* stackH = NULL;
  stackH = push(stackH,vn);
  visited[vn] = 1;
  cout<<"DFS starting from "<<vn<<" is :- ";
  while(isEmpty(stackH)==0){
    int ele = peekStack(stackH);
    cout<<ele<<" ";
    count++;
    if (ele==dn) {
      return count;
    }
    stackH = popStack(stackH);
    for(int i=0;i<G->V;i++){
      if( visited[i]==0 && G->Adj[ele][i] == 1){
        stackH = push(stackH,i);
        visited[i]=1;
      }
    }
  }
  return 0;
}
int main(){
    struct Graph *G = ajdMatrixOfGraph();
    printGraph(G);
    std::cout << "Enter source" << '\n';
    int source,destination;
    std::cin >> source;
    std::cout << "Enter destination" << '\n';
    std::cin >> destination;
    std::cout << '\n';
    int path = dfs(G,source,destination);
    std::cout << "Length of path is " <<  path << '\n';
    return 0;
}
