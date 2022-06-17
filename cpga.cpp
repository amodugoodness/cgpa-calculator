#include <iostream>
using namespace std;

int main (){
  int n;
  double sum=0;
  double percent;
  double ctwgp[100];
  double mean;
 
  cout<< "Input cumulated total credit: "; 
  cin >> n; 
  cout<<"Input cummulated total weighted grade point: "; 

  for(int i=0; i<n; i++){
    cin>>ctwgp[i];
  }
      
  for(int i=0; i<n; i++){
    sum+=ctwgp[i]; 
  }
  
  mean=sum/n; 
  
  cout<<"The cgpa is: "<<mean<<endl;
    return 0;
}
