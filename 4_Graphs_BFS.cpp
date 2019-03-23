#include <iostream>
#define SIZE 10
struct Queue{
  int items[SIZE];
  int front;
  int rear;
};
// Function to create Queue.
struct Queue* createQueue(){
  struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Function to check for an Empty Queue.
int isEmpty(struct Queue* q){
  if(q->rear == -1)
    return 1;
  else
    return 0;
}

// Function to insert an element in Queue.(insertion from the front side.)
void enQueue(struct Queue* q, int value){
  if(q->rear == SIZE-1){
    std::cout << "Queue is Full!!" << '\n';
  }else{
    if(q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Function to delete an element from Queue.(deletion from the fron side.)
int deQueue(struct Queue* q){
  int item;
  if(isEmpty(q)){
    std::cout << "Queue is empty!" << '\n';;
    item = -1;
  }else{
    item = q->items[q->front];
    q->front++;
    if(q->front > q->rear){
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Function to print the Queue.
void printQueue(struct Queue *q){
  int i = q->front;
  if(isEmpty(q)){
    std::cout << "Queue is empty!" << '\n';;
  }else{
    std::cout << "Queue contains : ";
    for(i = q->front; i < q->rear + 1; i++){
      std::cout << q->items[i] << " ";
    }
  }
}
struct Node{
  int vertex;
  struct Node* next;
};

// Function to create Node.
struct Node* createNode(int v){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
struct Graph{
  int numVertices;
  struct Node** adjLists;
  int* visited;
};
// Intialization
struct Graph* createGraph(int vertices){
  struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
  graph->visited = (int*)malloc(vertices * sizeof(int));
  for (int i = 0; i < vertices; i++){
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}
// BFS Algorithm.
void BFS(struct Graph* graph, int startVertex) {
  struct Queue* q = createQueue();
  graph->visited[startVertex] = 1;
  enQueue(q, startVertex);
  while(!isEmpty(q)){
    printQueue(q);
    int currentVertex = deQueue(q);
    printf("\nVisited %d\n", currentVertex);
    struct Node* temp = graph->adjLists[currentVertex];
    while(temp){
      int adjVertex = temp->vertex;
      if(graph->visited[adjVertex] == 0){
        graph->visited[adjVertex] = 1;
        enQueue(q, adjVertex);
      }
      temp = temp->next;
   }
  }
}
// Function to create edge between two Nodes.
void addEdge(struct Graph* graph, int src, int dest){
  // Add edge from src to dest
  struct Node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}
int main(){
  struct Graph* graph = createGraph(100);
  int temp,u,v;
  std::cout << "Enter number of vertices :" ;
  std::cin >> temp;
  std::cout << "Enter the Edges" << '\n';
  for (int i = 0; i < temp*temp; i++) {
    std::cin >> u >> v;
    if (u == -1 && v == -1)
      break;
    addEdge(graph,u,v);
  }
  BFS(graph, 5);
  return 0;
}
