//***************************************
// Name: Cooper Vandiver
// Course: CS 155 - Computer Science 1
// Semester: Spring 2021
// Project 4b: Write a program that calculates a course grade using a weighted average. It is nearing the midterm for the course. Quizzes count for
// 15% of the grade, assignments count for 15% of the grade, projects count for 25% of the grade, and exams count for 25% of the grade. This only adds
// up to 80% because it's only midway through the semester, and the final exam has not yet been taken. The skeleton code has already been provided,
// so you are only tasked with making use of four functions: void printPrompt(int), double average(), double weightedAverage(double, double, double,
// double), and void outputAverages(double, double, double, double, double). A file has been provided where all the necessary function declarations as
// well as a main function that makes calls to these functions have been written.  DO NOT MODIFY either the function declarations OR the main function.
// Your job will be to add the function definitions below the main function.  A completed and fully functional program should result if you correctly
// define these functions. The program will also compute the necessary final exam grades in order to make a 92.5, an 82.5, a 72.5, and a 62.5 for a
// final grade for the semester.
#include <iostream>
using namespace std;

//FUNCTION DECLARATIONS - ***DO NOT MODIFY***
/*name: printPrompt
  INCOMING:  An integer of possible values 1 through 4 indicating a specific graded activity
  OUTGOING:  None
*/
void printPrompt(int);

/*name: average
  INCOMING: None
  OUTGOING: The double average of the integer grades as entered by the user
*/
double average();

/*name: weightedAverage
  INCOMING: Four double values representing the averages for the four graded activities
  OUTGOING: The double value representing the weighted average for the course so far (a.k.a. the current grade)
*/
double weightedAverage(double, double, double, double);

/*name: outputAverages
  INCOMING: A double value representing the current grade and four double values for four graded activity averages
  OUTGOING: None
*/
void outputAverages(double, double, double, double, double);

/*name: outputFinalNeeded
    INCOMING: A double value representing the current weighted average
    OUTGOING: None
*/
void outputFinalNeeded(double);

//MAIN FUNCTION - ***DO NOT MODIFY***
int main(){
   double quizAvg, assignAvg, examAvg, projAvg, currentGrade;
   int count = 1;
   while (count<=4){
      printPrompt(count);
      switch(count){
         case 1:
         //1 - getting the quiz grades
            quizAvg = average();
            break;
         case 2:
         //2 - getting the assignment grades
            assignAvg = average();
            break;
         case 3:
         //3 - getting exam grades
            examAvg = average();
            break;
         case 4:
         //4 - getting project grades
            projAvg = average();
            break;
      }
      count++;
   }

   //get the current grade, based on the different averages and their weights.
   currentGrade = weightedAverage(quizAvg, assignAvg, examAvg, projAvg);


   outputAverages(currentGrade, quizAvg, assignAvg, examAvg, projAvg);

   outputFinalNeeded(currentGrade);

}
//END MAIN FUNCTION

//**YOUR FUNCTION DEFINITIONS START HERE - Put your code below this line**//
void printPrompt(int x){ //defining void printPrompt(int) and declaring variable
    switch(x){ //setting up switch statement to output certain prompt based on incoming value
        case 1: //if value is 1
            cout<<"Please enter your quiz grades."<<endl; //prompt user to input quiz grades
            break;
        case 2: //if value is 2
            cout<<"Please enter your assignment grades."<<endl; //prompt user to input assignment grades
            break;
        case 3: //if value is 3
            cout<<"Please enter your exam grades."<<endl; //prompt user to input exam grades
            break;
        case 4: //if value is 4
            cout<<"Please enter your project grades."<<endl; //prompt user to input project grades
            break;
    }
}

double average(){ //defining double average()
    double grade = 0; //declaring variables and setting equal to 0
    double avg = 0; //declaring variables and setting equal to 0
    int counter = 0; //declaring variables and setting equal to 0
    cin>>grade; //getting first input from user
    while(grade != -1){ //setting up while loop to run as long as input isn't -1
        counter++; //increasing value of counter by 1 for use in averaging the sum
        avg = avg + grade; //adding the input to the running sum
        cin>>grade; //getting next input
    }
    avg = avg / (double)counter; //averaging by dividing the sum by the number of inputs
    return avg; //returning computed average
}

double weightedAverage(double quizAvg, double assignAvg, double examAvg, double projAvg){ //defining double weightedAverage(double, double, double, double) and declaring variables
    double avg; //declaring variable
    examAvg = examAvg*25; //multiplying exam average by 25 due to its percentage of grade
    projAvg = projAvg*25; //multiplying project average by 25 due to its percentage of grade
    assignAvg = assignAvg*15; //multiplying assignment average by 15 due to its percentage of grade
    quizAvg = quizAvg*15; //multiplying quiz average by 15 due to its percentage of grade
    avg = examAvg+projAvg+assignAvg+quizAvg; //combining multiplied averages
    avg = avg / 80; //dividing combined averages by 80 since the percentages of each grade type add up to 80%
    return avg; //return weighted average value
}

void outputAverages(double currentGrade, double quizAvg, double assignAvg, double examAvg, double projAvg){ //defining void outputAverages(double, double, double, double, double) and declaring variables
    cout<<"Your quiz average: "<<quizAvg<<"."<<endl; //outputting quiz average
    cout<<"Your assignment average: "<<assignAvg<<"."<<endl; //outputting assignment average
    cout<<"Your exam average: "<<examAvg<<"."<<endl; //outputting exam average
    cout<<"Your project average: "<<projAvg<<"."<<endl; //outputting project average
    cout<<"Your current grade in this course is: "<<currentGrade<<"."<<endl<<endl;; //outputting weighted average as current grade
}

void outputFinalNeeded(double currentGrade){ //defining outputFinalNeeded and declaring variable
    double finalGradeA = 0, finalGradeB = 0, finalGradeC = 0, finalGradeD = 0; //declaring variables and setting to 0
    currentGrade = currentGrade * 0.8; //putting currentGrade into correct proportion
    finalGradeA = (92.5 - currentGrade)/0.2; //calculating grade necessary for an A
    finalGradeB = (82.5 - currentGrade)/0.2; //calculating grade necessary for a B
    finalGradeC = (72.5 - currentGrade)/0.2; //calculating grade necessary for a C
    finalGradeD = (62.5 - currentGrade)/0.2; //calculating grade necessary for a D
    cout<<"To make a 92.5 in this class, you would need to make a "<<finalGradeA<<" on the final exam."<<endl; //outputting final grade needed for an A
    if(finalGradeA > 100){ //conditional for it being impossible to make an A
        cout<<"It is impossible to make that grade."<<endl; //outputting that this grade is not possible
    }
    else if(finalGradeA <= 0){ //conditional for the student already having made this grade regardless
        cout<<"You have already made that grade."<<endl; //outputting that this grade has already been earned
    }
        cout<<"To make a 82.5 in this class, you would need to make a "<<finalGradeB<<" on the final exam."<<endl; //outputting final grade for a B
    if(finalGradeB > 100){  //conditional for the student being unable to make an 82.5
        cout<<"It is impossible to make that grade."<<endl; //outputting that an 82.5 is not possible
    }
    else if(finalGradeB <= 0){ //conditional for the student already having earned a 82.5
        cout<<"You have already made that grade."<<endl; //outputting that an 82.5 has already been earned
    }
        cout<<"To make a 72.5 in this class, you would need to make a "<<finalGradeC<<" on the final exam."<<endl; //outputting final grade for a C
    if(finalGradeC > 100){ //conditional for the student being unable to make a 72.5
        cout<<"It is impossible to make that grade."<<endl; //outputting that a 72.5 is not possible
    }
    else if(finalGradeC <= 0){ //conditional for the student having already earned a 72.5
        cout<<"You have already made that grade."<<endl; //outputting that the student has already earned a 72.5
    }
        cout<<"To make a 62.5 in this class, you would need to make a "<<finalGradeD<<" on the final exam."<<endl; //outputting final grade for a D
    if(finalGradeD > 100){ //conditional for the student being unable to make a 62.5
        cout<<"It is impossible to make that grade."<<endl; //outputting that a 62.5 is impossible to make
    }
    else if(finalGradeD <= 0){ //conditional for a student having already earned a 62.5
        cout<<"You have already made that grade."<<endl; //outputting that the student has already made a 62.5
    }
}
