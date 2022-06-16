#include <iostream>
using namespace std;

int main (){
  int n;
  double sum=0;
  double percent;
  double gpa[100];
  double mean;
 
  cout<< "Enter number of semesters: "; 
  cin >> n; 
  cout<<"Input consecutive gpa's: "; 

  for(int i=0; i<n; i++){
    cin>>gpa[i];
  }
      
  for(int i=0; i<n; i++){
    sum+=gpa[i]; 
  }
  
  mean=sum/n; 
  
  cout<<"The cgpa is: "<<mean<<endl;
    return 0;
}
