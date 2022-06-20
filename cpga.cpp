#include <iostream>

using namespace std;

string* splitCourseDetails(string courseDetails) {
  // Initialize an array pointer with 3 empty spaces
  // We expect course details to be 3 values that are separated by spaces
  // i.e courseCode courseCredit score
  // e.g CIT202 3 70

  string* splits = new string[3];
  int splitCounter = 0;
  string tmp = "";

  // loop through each character in the string
  for (int i=0; i<courseDetails.length(); i++){
    if (courseDetails[i] == ' '){ 
      // ensures that previous strings of characters are stored when a space is encountered
      splits[splitCounter] = tmp;
      tmp = "";
      splitCounter++;
      continue;
    }else if (i == courseDetails.length()-1) { 
      // ensures that previous strings of characters are stored when the end of the string is reached
      tmp += courseDetails[i];
      splits[splitCounter] = tmp;
      splitCounter++;
      tmp = "";
    }else{
      tmp += courseDetails[i];
    }
  }

 return splits;
}

int convertScoreToPoints(int score){
  // all score values will have to be between 0 and 100 to get an accurate grade
  if (score >= 70 && score <= 100){
    // Grade A
    return 5;
  }else if (score >=60 && score < 70){
    // Grade B
    return 4;
  }else if (score >=50 && score < 60){
    // Grade C
    return 3;
  }else if (score >=45 && score < 50){
    // Grade D
    return 2;
  }else if (score >=40 && score < 45){
    // Grade E
    return 1;
  }else{
    // Grade F
    return 0;
  }
}

int main (){
  int courses;
  string courseDetails[100];
  string courseCodes[100];
  int courseCredits[100];
  int courseGrades[100];
  int courseGradePoints[100];
  int ctwgp;
  int ctc;
  double cgpa;

  cout<<"How many courses have you taken so far: ";
  cin>>courses;
  cin.ignore();
  cout<<"Enter the course details ([course code] [course credit] [score]). e.g CIT101 2 70 "<<endl;

  for (int i = 0; i<courses; i++){
    getline(cin, courseDetails[i]);
    string* d = splitCourseDetails(courseDetails[i]);

    // Extract course code from array pointer
    courseCodes[i] = d[0];

    // Extract course credits from array pointer
    courseCredits[i] = stoi(d[1]);
    // sum up the credits
    ctc += courseCredits[i];

    // Extract score from array pointer
    courseGrades[i] = stoi(d[2]);
    // convert the score to grade point
    courseGradePoints[i] = convertScoreToPoints(courseGrades[i]);
    // sum the values of (grade point * credit)
    ctwgp += courseGradePoints[i] * courseCredits[i];
  }
  
  // Calculate the CGPA
  // int/int = int, that us why ctwgp was casted to a double: double/int = double
  cgpa = (double)ctwgp/ctc;
  cout<<"Your CGPA is "<<cgpa<<endl;
  
  return 0;
}
