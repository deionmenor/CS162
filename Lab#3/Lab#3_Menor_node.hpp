
struct Node{

public:
  int data;
  Node* next;
  Node(){
    data = 0;
    next = NULL;
  }
  Node(int d, Node* n){

    data=d;
    next=n;
  }

  int getValue(){
    return data;
  }

  Node* getNext(){
    return next;
  }

  ~Node() { // Destructor

    delete next;
  }
};
