struct Process{

  int arrival_time;
  int burst_time;
  int priority;
  bool isFinished;

  Process(){
    arrival_time=0;
    burst_time=0;
    priority=0;
    isFinished=FALSE;
  }


  Process(int at, int bt, int p){
    arrival_time = at;
    burst_time = bt;
    priority = p;
    isFinished=FALSE;
  }
};
