#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include"SumofGaussians.h"
using namespace std;
int print(int dim,double array[]){
  for (int x=0;x<dim;x++){
    cout<<array[x]<<" ";
  }
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
  //Choose a random starting position
  for (int x = 0; x < dem_num; x++)
    input[x]=rand()%10+1;
  reached_max=false;

  SumofGaussians sog(dem_num,gauss_num);
  sog_value=sog.eval(input);
  //Print the first starting position and sog_value
  print(dem_num,input);
  cout<<sog_value<<endl;
  while (!reached_max){
    //Find Deriv:
    sog.deriv(input,deriv);
    //Move in the direction of driv and get new sog_value
    double new_sog_value;
    for (int i=0;i<dem_num;i++){
      input[i]=input[i]+0.01*deriv[i];
    }
    new_sog_value=sog.eval(input);
    //check if reached max
    if (abs(new_sog_value-sog_value)<=1.0e-8){
      reached_max=true;
    }
    sog_value=new_sog_value;
    print(dem_num,input);
    cout<<sog_value<<endl;
  }

  return 0;
}
