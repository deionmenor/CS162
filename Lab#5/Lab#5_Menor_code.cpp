
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
struct Point3D {
  int x;
  int y;
  int z;

Point3D(){
    x=0;
    y=0;
    z=0;
  }

Point3D(int a, int b, int c){
  x=a;
  y=b;
  z=c;
}

  int getX(){
    return x;
  }

  int getY(){
    return y;
  }

  int getZ(){
    return z;
  }

};

int main( void ) {
  int cases;
  int points;
  int coordinates;
  int a;
  int b;
  int c;
  Point3D *p = new Point3D();
  Point3D *q = new Point3D();
  int result;


  // gets number of cases from user
  std::cin >> cases;


  //for each case...
  for (int i = 0; i < cases; i++) {

      // gets number of points to read
      std::cin >> points;


      //for each point...
      for (int j = 0; j < points; j++) {

        // std::cout << "C:" << i+1 << "/" << cases << " P:" << j+1 << "/" << points << " - ";

        //if first point...
        if(j==0){
          //set point as Point3D p
          scanf("%i %i %i", &a, &b, &c);
          p = new Point3D(a,b,c);

        }
        //if not...
        else{
        //set point as Point3D q..
        scanf("%i %i %i", &a, &b, &c);
        q =  new Point3D(a,b,c);

        // and use manhattan distance formula with Point3D p
        result = abs(p->getX()-q->getX())+ abs(p->getY()-q->getY())+abs(p->getZ()-q->getZ());

        // Point3D p is now q
        p = q;


        //print results
        std::cout << result << '\n';
        }
      }
      // std::cout << "-------------------------" << '\n';

  }
  return(0);
}
