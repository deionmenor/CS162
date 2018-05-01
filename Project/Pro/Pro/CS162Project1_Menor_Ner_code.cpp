

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

  int arrival_time;
  int burst_time;
  int priority;
  bool isFinished;
  double respondedOn;
  double finishedOn;
  double timeWaiting;
  int lastRun;

  Process(){
    arrival_time=0;
    burst_time=0;
    priority=0;
    isFinished=FALSE;
    respondedOn=0;
    finishedOn=0;
    timeWaiting=0;
    lastRun=0;
  }


  Process(int at, int bt, int p){
    arrival_time = at;
    burst_time = bt;
    priority = p;
    isFinished=FALSE;
    respondedOn=0;
    finishedOn=0;
    timeWaiting=0;
    lastRun=0;
  }
};

int time_elapsed = 0;
std::vector<Process> p_array;
std::vector<int> order;



void printOutput(int time_elapsed, int index, int cpu_time, string finished){

    std::cout << time_elapsed << " "  << index+1 <<  " " << cpu_time  << finished << '\n';

}

void finishProcess(int p){
  p_array[p].isFinished = TRUE;
}

bool hasUnfinishedProcesses(){

  for (size_t i = 0; i < p_array.size(); i++) {
    if(!p_array[i].isFinished){
        return TRUE;
    }
  }
  return FALSE;
}

int getNextProcessByPriority(){

  int min = 21;
  int min_index = 0;

  for (size_t i = 0; i < p_array.size(); i++) {


    if(p_array[i].priority<min && !p_array[i].isFinished){
        min = p_array[i].priority;
        min_index = i;
    }
  }

  //this function returns the index of the next process
  return min_index;


}

int getNextProcessByBurstTime(){

  int min = 10000;
  int min_index = 0;
  bool foundJob = FALSE;

  while(hasUnfinishedProcesses()){
      for (size_t i = 0; i < p_array.size(); i++) {

        //check for jobs that have arrived
        if(p_array[i].burst_time<min && p_array[i].arrival_time <= time_elapsed && !p_array[i].isFinished){
            min = p_array[i].burst_time;
            min_index = i;
            foundJob=TRUE;

        }
      }
      if(foundJob) break;

      time_elapsed++;
  }
  //this function returns the index of the next process
  return min_index;




  //hnu do
}

int checkForShorterJobs(int nextIndex){

  int arrival_min = 10000;
  int arrival_min_index = 0;
  int currIndex = nextIndex;
  int cpu_time = 0;
  int burstingFor = 0;
  int endBurst=0;
  int startBurst=0;


 //if the most recent job just finished
  if(currIndex == -1){

   int min = 1000;
   int minIndex = -1;

    while(hasUnfinishedProcesses()){


    for (size_t i = 0; i < p_array.size(); i++) {




      // look for nearest arrived, unifinished process
      if(!p_array[i].isFinished && p_array[i].arrival_time <= time_elapsed && p_array[i].burst_time<min ){
          // update bursting time of current process, since will now go to new process

            min = p_array[i].burst_time;
            minIndex = i;
      }

    }
    if(minIndex!=-1) return minIndex;
    time_elapsed++;
  }
  }
  else{
    startBurst = time_elapsed;
    burstingFor = p_array[currIndex].burst_time;
    endBurst = startBurst + burstingFor;



    //for every unfinished process, look for the job with the shortest remaining time left
    while(time_elapsed != endBurst){



    for (size_t i = 0; i < p_array.size(); i++) {


      // look for arrived, unifinished processes with remaining burst time shorter than current remaining burst time
      if(!p_array[i].isFinished && p_array[i].burst_time < burstingFor && p_array[i].arrival_time <= time_elapsed){

          // update bursting time of current process, since will now go to new process
          if(p_array[currIndex].respondedOn == 0){
            p_array[currIndex].respondedOn  = startBurst;
            p_array[currIndex].lastRun  = p_array[currIndex].arrival_time;
          }

          p_array[currIndex].burst_time = burstingFor;

          p_array[currIndex].timeWaiting+= startBurst - p_array[currIndex].lastRun;

          printOutput(startBurst,currIndex,cpu_time, "" );
          p_array[nextIndex].lastRun=time_elapsed;

          return i;
      }
   }

  time_elapsed++;
  burstingFor--;
  cpu_time++;


  }

  if(p_array[currIndex].respondedOn == 0) p_array[currIndex].respondedOn  = startBurst;

  p_array[currIndex].timeWaiting+= startBurst - p_array[currIndex].lastRun;
  finishProcess(currIndex);
  p_array[currIndex].finishedOn= time_elapsed;
  printOutput(startBurst,currIndex,cpu_time, "X" );

  //RETURN -1 IF PROCESS FINISHES
  return -1;

  //this function returns the index of the next process
  }
}



int checkForHigherPriorityJobs(int nextIndex){

  int currentPriority = p_array[nextIndex].priority;
  int min = currentPriority;
  int minIndex=-1;

  if(nextIndex==-1){
              while(hasUnfinishedProcesses()){

                min=1000;

                for (size_t i = 0; i < p_array.size(); i++) {

                      //if we find an unfinished arrived task that has a higher priority, we rkeep track
                      if(!p_array[i].isFinished && p_array[i].arrival_time<=time_elapsed && p_array[i].priority<min){
                          min = p_array[i].priority;
                          minIndex = i;

                      }
                }
                if(minIndex!= -1) break;
                time_elapsed++;


              }

              if(p_array[minIndex].respondedOn == 0){
                  p_array[minIndex].respondedOn = time_elapsed;
                  p_array[minIndex].lastRun = p_array[minIndex].arrival_time;
              }

              return minIndex;

  }

  else{

                for (size_t i = 0; i < p_array.size(); i++) {

                      //if we find an unfinished arrived task that has a higher priority, we rkeep track
                      if(!p_array[i].isFinished && p_array[i].arrival_time<=time_elapsed && p_array[i].priority<min){
                          min = p_array[i].priority;
                          minIndex = i;

                      }
                }

                return minIndex;

                }
}

int getNextProcessByArrivalTime(){

  // at the start, the minimum arrival time is a high number
  // and the default index is 0, this will change of course
  int min = 10000;
  int min_index = 0;
  //std::cout << "Job " << currIndex+1 << " interrupted at " << burstingFor << " left. Found Job "<< i+1 << " with shorter remaining time:" << p_array[i].burst_time << '\n';

  // scan thru array for earliest arrival time
  for (size_t i = 0; i < p_array.size(); i++) {


  /*  if the arrival time is less than the minimum ( remember, its originally 10000) AND is not yet finished,
    update the min and min_index*/
    if(p_array[i].arrival_time<min && !p_array[i].isFinished){
        min = p_array[i].arrival_time;
        min_index = i;
    }
  }

  //this function returns the index of the next process
  return min_index;
}

void printCriteria(double totalBurstTime, double number_of_processes){

  double totalResponseTime;
  double totalWaitingTime;
  double totalTurnaroundTime;

  for (size_t i = 0; i < p_array.size(); i++) {
      totalResponseTime += (p_array[i].respondedOn - p_array[i].arrival_time);
      totalWaitingTime +=  (p_array[i].timeWaiting);
      totalTurnaroundTime += (p_array[i].finishedOn - p_array[i].arrival_time);

  }
  std::cout << "========CRITERIA:=========" << '\n';
  std::cout << "CPU UTILIZATION: " << totalBurstTime/time_elapsed*100 << "%" << '\n';
  std::cout << "THROUGHPUT: " << number_of_processes/time_elapsed << " processes per nanosecond"<<'\n';
  std::cout << "RESPONSE TIME: " << totalResponseTime/p_array.size() << "ns" << '\n';
  std::cout << "WAITING TIME: " << totalWaitingTime/p_array.size() << "ns" << " cumulative" << '\n';
  std::cout << "TURNAROUND TIME: " << totalTurnaroundTime/p_array.size() << "ns" << '\n';
}

int getTotalBurstTime(){

  int totalBurstTime=0;
  for (size_t i = 0; i < p_array.size(); i++) {
      totalBurstTime += p_array[i].burst_time;

  }
  return totalBurstTime;
}

void scheduleFCFS(){

  time_elapsed=0;

  //iteratively find the next process and print out the output
  for (size_t i = 0; i < p_array.size(); i++) {

    string finished = "";
      /*we use the getNextProcessByArrivalTime method to get the index of the next process
     (finding the earliest process that is also not finished yet)*/
    int nextIndex = getNextProcessByArrivalTime();
    finishProcess( nextIndex);
    finished="x";

    //if current process comes after current elapsed time, we wait (time_elapsed becomes next processes arrival time)
    if(p_array[nextIndex].arrival_time>= time_elapsed)
      time_elapsed = p_array[nextIndex].arrival_time;

    //print output
    printOutput(time_elapsed, nextIndex, p_array[nextIndex].burst_time, finished);


    p_array[nextIndex].respondedOn = time_elapsed;


    //we add burst time of the current process to time_elapsed
    time_elapsed += p_array[nextIndex].burst_time;
    p_array[nextIndex].finishedOn = time_elapsed;
    p_array[nextIndex].timeWaiting = p_array[nextIndex].respondedOn -p_array[nextIndex].arrival_time;


  }
}

void scheduleSJF(){

  time_elapsed=0;

  //iteratively find the next process and print out the output
  for (int i = 0; i < p_array.size(); i++) {

    string finished = "";
    int nextIndex = getNextProcessByBurstTime();
    finishProcess(nextIndex);
    finished="x";


    printOutput(time_elapsed, nextIndex, p_array[nextIndex].burst_time, finished );

    p_array[nextIndex].respondedOn = time_elapsed;

    //we add burst time of the current process to time_elapsed
    time_elapsed += p_array[nextIndex].burst_time;


    p_array[nextIndex].finishedOn = time_elapsed;
    p_array[nextIndex].timeWaiting = p_array[nextIndex].respondedOn -p_array[nextIndex].arrival_time;

    // std::cout << "RESPONDED ON: " << p_array[nextIndex].respondedOn<<'\n';
    // std::cout << "FINISHED ON: " << p_array[nextIndex].finishedOn<<'\n';
    // std::cout << "WAITED FOR: " << p_array[nextIndex].timeWaiting<<'\n';

  }
}


int runQuantumTime(int quantum, int index){
  int b = p_array[index].burst_time;

  //sets response time if first time responding
  if(p_array[index].respondedOn==0) p_array[index].respondedOn  =time_elapsed;



  if(b<=quantum){
    p_array[index].burst_time = 0;

    finishProcess(index);
    return b;
  }
  else {
    p_array[index].burst_time = b-quantum;
  return quantum;
  }
}

void printTime(){
  std::cout << "time elapsed: " << time_elapsed << '\n';
}
void scheduleRR(int quantum_time, int number_of_processes){

  time_elapsed=0;
  int nextIndex=0;
  string finished ="";
  std::queue<int> rr_queue;
      while(hasUnfinishedProcesses()){
        while(rr_queue.empty()){
            for (size_t i = 0; i < p_array.size(); i++) {
                if(p_array[i].arrival_time == time_elapsed){
                    rr_queue.push(i);

                    p_array[i].lastRun = time_elapsed;

                    break;
                }
            }
            if(!rr_queue.empty()) break;
            time_elapsed++;

        }
        int start = time_elapsed;
        nextIndex = rr_queue.front();
        // run quantum time on z
        int cpu_time = runQuantumTime(quantum_time, nextIndex);
        int updated_time = time_elapsed+cpu_time;

        //add time between current start of burst to last time run as waiting time
        p_array[nextIndex].timeWaiting += time_elapsed - p_array[nextIndex].lastRun;

        //increment time until it reaches correct time, queue new processes along the way
        while(time_elapsed<updated_time){
                for (size_t i = 0; i < p_array.size(); i++) {
                    if(p_array[i].arrival_time == time_elapsed && i!=nextIndex){
                        rr_queue.push(i);
                        p_array[nextIndex].lastRun = time_elapsed;
                    }
                }
                time_elapsed++;
        }

        if(!p_array[nextIndex].isFinished){
          rr_queue.pop();
          rr_queue.push(nextIndex);
          finished ="";

          //keeps track of time process ended running the previous time
          p_array[nextIndex].lastRun=time_elapsed;
        }
        else{
           rr_queue.pop();
           finished ="X";
           p_array[nextIndex].finishedOn = time_elapsed;
           finishProcess(nextIndex);
        }
        printOutput(start,nextIndex,cpu_time,finished);
      }
}

void scheduleSRTF(){



  int currIndex = -1;
  time_elapsed=0;



  while(hasUnfinishedProcesses()){

    if(currIndex==-1){
      currIndex = checkForShorterJobs(-1);
  //    std::cout << "WAITED FOR JOB" << currIndex+1 <<'\n';
    }
    else{
      currIndex = checkForShorterJobs( currIndex);
    //  std::cout << "MOVED TO JOB" << currIndex+1 <<'\n';
    }


}
}

int runPriority(int currIndex){

      int start = time_elapsed;
      int cpu_time=0;
      //add time waiting
      p_array[currIndex].timeWaiting+=start-p_array[currIndex].lastRun;


      while(!p_array[currIndex].isFinished){

          if(p_array[currIndex].burst_time==0){
            finishProcess(currIndex);
            p_array[currIndex].finishedOn = time_elapsed;
            printOutput(start, currIndex, cpu_time, "X");
            break;
          }
          //checkForHigherPriorityJobs
          int higherPriority = checkForHigherPriorityJobs(currIndex);
          if(higherPriority == -1){
            time_elapsed++;
            cpu_time++;

            p_array[currIndex].burst_time--;
          }
          else{

            printOutput(start, currIndex, cpu_time, "");
            p_array[currIndex].lastRun = time_elapsed;
            return higherPriority;
          }
      }

      return -1;



}


void scheduleP(){

  int currIndex = -1;
  time_elapsed=0;

  while(hasUnfinishedProcesses()){


      if(currIndex == -1){
          currIndex = checkForHigherPriorityJobs(-1);
          if(currIndex!=-1) currIndex = runPriority(currIndex);
      }
      else{
          currIndex = checkForHigherPriorityJobs(currIndex);
          if(currIndex!=-1) currIndex = runPriority(currIndex);
      }


  }


}


int scheduleWith(string algo_type, int number_of_processes, int quantum_time){

  //TODO: fix algo_type with leading space



  if (algo_type.compare("SJF") == 0){
    scheduleSJF();
   }


  else if (algo_type.compare("FCFS") == 0){
    scheduleFCFS();
   }

  else if (algo_type.compare("SRTF") == 0){
    scheduleSRTF();
   }

  else if (algo_type.compare("RR") == 0){
    scheduleRR(quantum_time,number_of_processes);
   }

  else if (algo_type.compare("P") == 0){
     scheduleP();
    }
  else{
    std::cout << "INCORRECT INPUT. PLS TRY AGAIN" << '\n';
    return -1;
  }


}

int main( void ){


  int testcases;

  //get number of testcases
  scanf("%i", &testcases);

  //loop for each testcase
  for (size_t i = 0; i < testcases; i++) {


    std::cout << std::setprecision(2) << std::fixed;

    int number_of_processes;
    int quantum_time=0;
    string algo_type;
    scanf("%i", &number_of_processes);
    cin >> algo_type;
    if(algo_type=="RR")   cin >> quantum_time;

    //make an array of processes
    p_array = std::vector<Process>(number_of_processes);
    order =  std::vector<int>(number_of_processes);


    //place process input into array
    for (size_t j = 0; j < number_of_processes; j++) {
          int x;
          int y;
          int z;
          scanf("%i %i %i", &x, &y, &z );

          p_array[j].arrival_time = x;
          p_array[j].burst_time = y;
          p_array[j].priority = z;
    }
    std::cout << i+1 << '\n';
    int x = getTotalBurstTime();
    scheduleWith(algo_type, number_of_processes, quantum_time);
    printCriteria(x, number_of_processes);

}
}
