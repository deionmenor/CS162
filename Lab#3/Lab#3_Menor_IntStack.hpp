
struct IntStack{

public:
  Node* headPointer;
  int len;

//constructor
  IntStack(){

    Node* headPointer = new Node(0,NULL);
    len = 0;
    std::cout << "Initialize stack..." << '\n';


  };
  void push(int data){

    len++;
    // std::cout << len << '\n';
    if(len == 0){
      headPointer = new Node(data,headPointer);
      std::cout << "StackSize:"<<len<< "| Push In value:"<<headPointer->getValue() << '\n';
    }
    else
  {
      Node* newNode = new Node(data,headPointer);
      std::cout << "StackSize:"<<len<< "| Push In value:"<<newNode->getValue() << '\n';
      headPointer = newNode;
    }

  }

  int pop(){
    if(len==0){
      std::cout << "StackSize:"<<len<< "| Nothing to pop!" << '\n';
      return 0;
    }
    int dataOut = headPointer->getValue();
    headPointer = headPointer->getNext();
    len--;
    std::cout << "StackSize:"<<len<< "| Pop out value:"<<dataOut<< '\n';
    return dataOut;
  }

  ~IntStack(){
    std::cout << "Deleting stack..." << '\n';
    delete headPointer;
  }

};
