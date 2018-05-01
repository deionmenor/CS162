#include <iomanip>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define  FALSE  0
#define TRUE 1


struct Process{

  std::vector<int> resourcesActual;
  std::vector<int> resourcesNeeded;
  bool isFinished;


  Process(){
    isFinished = false;
  }
};

std::vector<int> availableResources;
std::vector<Process> p_array;

void runProcess(int process_index){
  for (int i = 0; i < p_array[process_index].resourcesActual.size(); i++) {
    availableResources[i]+= p_array[process_index].resourcesActual[i];
    //printf("%i instances of R%i added to available resources", p_array[process_index].resourcesActual[i], i);
  }
}

bool hasUnfinishedProcesses(){
  for (int i = 0; i < p_array.size(); i++) {
    if (p_array[i].isFinished == false){
      return true;
    }
    }
    return false;
  }

int main( void ){


  int testcases;
  //get number of testcases
  scanf("%i", &testcases);
//  printf("number of testcases:%i  \n",testcases );


  //loop for each testcase
  for (int i = 0; i < testcases; i++) {
    printf("~~~~~~~~Testcase #%i~~~~~~~~~~~\n", i+1);
    // std::cout << std::setprecision(2) << std::fixed;


    int number_of_processes;
    int number_of_resources;
    scanf("%i %i", &number_of_processes, &number_of_resources);

    //initialize available resources
    availableResources = std::vector<int>(number_of_resources);
    for (size_t i = 0; i <number_of_resources; i++) {
          int x;
          std::cin >> x ;
          availableResources[i] = x;
         // std::cout << "R" << i+1 << ": " << availableResources[i] << " | ";
    }
    std::cout << '\n';

    //initialize processes
    p_array = std::vector<Process>(number_of_processes);

    //add resources processes have
    for (int i = 0; i < number_of_processes; i++) {

      p_array[i].resourcesActual = std::vector<int>(number_of_resources);

      for (int j = 0; j <number_of_resources; j++) {
        int x;
        std::cin >> x ;
        p_array[i].resourcesActual[j] = x;
        // printf("Process %i has %i instances of R%i\n", i+1,x,j);
      }
    }

    //add resources the processes need
    for (int i = 0; i < number_of_processes; i++) {

      p_array[i].resourcesNeeded = std::vector<int>(number_of_resources);

      for (int j = 0; j <number_of_resources; j++) {
        int x;
        std::cin >> x ;
        p_array[i].resourcesNeeded[j] = x;
        // printf("Process %i needs %i instances of R%i\n", i,x,j);
      }
    }

    //copy array
    std::vector<Process> p_array_original = p_array;
    bool isDeadlock;
    while(hasUnfinishedProcesses()){
    isDeadlock= true;
    for (int i = 0; i < number_of_processes; i++) {


      bool canRun = true;
      if (p_array[i].isFinished == false) {
        // printf("~~~~~~~~Process #%i~~~~~~~~~~~\n", i+1);
          for (int j = 0; j < number_of_resources; j++) {
              int n = + availableResources[j] - p_array[i].resourcesNeeded[j];
          //    std::cout << "R"<<j+1 << ": "<<  + availableResources[j] << "/"<< p_array[i].resourcesNeeded[j] << " " << '\n';
              if( n < 0){
                  //printf("Process %i is missing %i instances of R%i.", i+1, n*-1,j+1 );
                  canRun=false;
                  break;
              }
          }
          if(!canRun){
      //      printf("Process cannot run\n" );
          }
          else{
    //          printf("Process %i can run!\n", i+1 );
              isDeadlock = false;
              runProcess(i);
              p_array[i].isFinished = true;
              std::cout << i+1;
      }
    }
    }
    if(isDeadlock){
            printf("\nDeadlock has occurred\n");
            break;
      }
  }
  std::cout << "\n";


}

//  cout << "program end." << '\n';
}
