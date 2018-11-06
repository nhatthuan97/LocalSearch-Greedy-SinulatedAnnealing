#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include"SumofGaussians.h"
#include<math.h>
using namespace std;
int print(int dim,double array[]){
  for (int x=0;x<dim;x++){
    cout<<array[x]<<" ";
  }
}
//Function to calculate tempurature
double annealing_schedule(int itteration){
  return (250000000/(itteration+1))-2500;
}
int main(int argc, char*argv[]){
  int seed=atoi(argv[1]);
  int dem_num=atoi(argv[2]);
  int gauss_num=atoi(argv[3]);
  bool reached_max;
  double input[dem_num];
  double deriv[dem_num];
  double sog_value;
  srand(seed);
  SumofGaussians sog(dem_num,gauss_num);
  //Choose a random starting position
  for (int x = 0; x < dem_num; x++)
    input[x]=rand()%10+1;
  sog_value=sog.eval(input);

  //Sinnulated annealing process
  for (int x=0;x<100000;x++){
    //Determine the random run for new input
    int sign;
    double random_run;
    sign=rand()%11;
    random_run=((double)(rand()%101))/10000;
    if (sign%2==0){
      random_run=random_run*-1;
    }
    double new_input[dem_num];
    //Get new input
    for (int x=0;x<dem_num;x++){
      new_input[x]=input[x]+random_run;
      if (new_input[x]<0){
        new_input[x]=0;
      }
    }
    double new_sog_value;
    new_sog_value=sog.eval(new_input);
    //If new input is better take it
    if (new_sog_value>sog_value){
      for (int x=0;x<dem_num;x++){
        input[x]=new_input[x];
      }
      sog_value=new_sog_value;
    }
    else{
      //New input is worse, it still have a certain percentage to be used.
      if (pow(2.71828,(new_sog_value-sog_value)/annealing_schedule(x))>(((double)(rand()%101))/100)){
        for (int x=0;x<dem_num;x++){
          input[x]=new_input[x];
        }
        sog_value=new_sog_value;
      }
    }
    print(dem_num,input);
    cout<<sog_value<<endl;
  }
  return 0;
}
