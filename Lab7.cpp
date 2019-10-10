#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <iomanip>

void Evaluate_Cholesterol(int, int);
void Evaluate_Blood_Pressure(int, int);
int Get_HDL_LDL_Systolic_Diastolic();

ifstream myFile;

//Pre-conditions:
//      - User-entered number of patients should not exceed the actual number of patients included within infile.txt
//      - User-entered number of patients may be less the actual number of patients within infile.txt in which case the program will only output data for the first x patients with x being the user-entered value
//Post-conditions:
//      - If the operation is correct and the pre-condition(s) are met, then when main has completed its tasks and run through all the other functions, the file will be closed and each patients health data numbers will have been printed out along with the associated interpretations
int main()
{
  int Patients;
  cout << "Enter the number of patient records: ";
  cin >> Patients;
  cout << endl;
  cout << endl;

  myFile.open("infile.txt");
    for (int i=1; i<=Patients; i++)
    {
      string Last_Name, Return_Status;
      int Data_Sets;
      myFile >> Last_Name >> Return_Status >> Data_Sets;
      cout << "Current Patient's Name - " << Last_Name << endl;

      for (int x=1; x<=Data_Sets; x++)
      {
        int HDL = Get_HDL_LDL_Systolic_Diastolic();
        int LDL = Get_HDL_LDL_Systolic_Diastolic();
        int Diastolic = Get_HDL_LDL_Systolic_Diastolic();
        int Systolic = Get_HDL_LDL_Systolic_Diastolic();
        
        cout << "DATA SET " << x << endl;
        cout << "Cholesterol Profile" << endl;
        Evaluate_Cholesterol(HDL, LDL);
        
        cout << "Blood Pressure Profile" << endl;
        Evaluate_Blood_Pressure(Diastolic, Systolic);
        cout << endl;
      }
      cout << endl;
      cout << endl;
    }
    myFile.close();
    return 0;
}
//Pre-conditions: The function is being called while the file is open and there is data left to read that is an integer.
//Post-conditions: If the operation is correct and the pre-condition(s) are met, then when the tasks are completed, a single integer value will be read from the file and returned to main to be stored as a value for HDL, LDL, Systolic, or Diastolic within the main function.
int Get_HDL_LDL_Systolic_Diastolic()
{
  int data;
  myFile >> data;
  return data;
}

//Pre-conditions: Two integer values are passed in; one for HDL and the other for LDL. The LDL value is not 0; otherwise the ratio (HDL/LDL) will be undefined
//Post-conditions: If the operation is correct and the pre-condition(s) are met, then the inputed HDL and LDL health data will be printed out along witht the associated interpretations
void Evaluate_Cholesterol(int HDL, int LDL)
{
  string HDL_Interpretation;
  string LDL_Interpretation;
  string Ratio_Interpretation;

  if (HDL <40)
    HDL_Interpretation = "Too low";
  if ((HDL <60) && (HDL >=40))
    HDL_Interpretation = "Okay";
  if (HDL >= 60)
    HDL_Interpretation = "Excellent";
  
  if (LDL <100)
    LDL_Interpretation = "Optimal";
  if ((LDL <130) && (LDL >=100))
    LDL_Interpretation = "Near Optimal";
  if ((LDL <160) && (LDL >=130))
    LDL_Interpretation = "Borderline High";
  if ((LDL <190) && (LDL >=160))
    LDL_Interpretation = "High";
  if (LDL >= 190)
    LDL_Interpretation = "Very High";

  float Ratio = float (HDL) / float (LDL);

  if (Ratio >0.3)
    Ratio_Interpretation = "Good";
  if (Ratio <=0.3)
    Ratio_Interpretation = "Not Good";
  
  cout << "\tHDL: " << HDL;
  cout << "\t\tLDL: " << LDL << endl;
  cout << "\tRatio: " << fixed << showpoint << setprecision (4) <<Ratio << endl;
  cout << "\tHDL is " << HDL_Interpretation << endl;
  cout << "\tLDL is " << LDL_Interpretation << endl;
  cout << "\tRatio of HDL to LDL is " << Ratio_Interpretation << endl;
}

//Pre-conditions: Two integer values are passed in; one for Systolic and the other for Diastolic
//Post-conditions: If the operation is correct and the pre-condition(s) are met, then the inputed Systolic and Diastolic health data will be printed out along with the associated interpretations
void Evaluate_Blood_Pressure(int Systolic, int Diastolic)
{
  string Systolic_Interpretation;
  string Diastolic_Interpretation;
  if (Systolic <120)
    Systolic_Interpretation = "Optimal";
  else if (Systolic <130)
    Systolic_Interpretation = "Normal";
  else if (Systolic <140)
    Systolic_Interpretation = "Normal High";
  else if (Systolic <160)
    Systolic_Interpretation = "Stage 1 Hypertension";
  else if (Systolic < 180)
    Systolic_Interpretation = "Stage 2 Hypertension";
  else if (Systolic >= 180)
    Systolic_Interpretation = "Stage 3 Hypertension";
  
  if (Diastolic <80)
    Diastolic_Interpretation = "Optimal";
  else if (Diastolic <85)
    Diastolic_Interpretation = "Normal";
  else if (Diastolic <90)
    Diastolic_Interpretation = "High Normal";
  else if (Diastolic <100)
    Diastolic_Interpretation = "Stage 1 Hypertension";
  else if (Diastolic < 110)
    Diastolic_Interpretation = "Stage 2 Hypertension";
  else if (Diastolic >= 110)
    Diastolic_Interpretation = "Stage 3 Hypertension";
  
  cout << "\tSystolic: " << Systolic;
  cout << "\t\tDiastolic: " << Diastolic << endl;
  cout << "\tSystolic reading is " << Systolic_Interpretation << endl;
  cout << "\tDiastolic reading is " << Diastolic_Interpretation << endl;
}

//Enter the number of patient records: 4
//
//
//Current Patient's Name - Jones
//DATA SET 1
//Cholesterol Profile
//    HDL: 60     LDL: 124
//    Ratio: 0.4839
//    HDL is Excellent
//    LDL is Near Optimal
//    Ratio of HDL to LDL is Good
//Blood Pressure Profile
//    Systolic: 130       Diastolic: 84
//    Systolic reading is Normal High
//    Diastolic reading is Normal
//
//DATA SET 2
//Cholesterol Profile
//    HDL: 65     LDL: 121
//    Ratio: 0.5372
//    HDL is Excellent
//    LDL is Near Optimal
//    Ratio of HDL to LDL is Good
//Blood Pressure Profile
//    Systolic: 133       Diastolic: 80
//    Systolic reading is Normal High
//    Diastolic reading is Normal
//
//DATA SET 3
//Cholesterol Profile
//    HDL: 70     LDL: 120
//    Ratio: 0.5833
//    HDL is Excellent
//    LDL is Near Optimal
//    Ratio of HDL to LDL is Good
//Blood Pressure Profile
//    Systolic: 130       Diastolic: 81
//    Systolic reading is Normal High
//    Diastolic reading is Normal
//
//
//
//Current Patient's Name - Smith
//DATA SET 1
//Cholesterol Profile
//    HDL: 30     LDL: 195
//    Ratio: 0.1538
//    HDL is Too low
//    LDL is Very High
//    Ratio of HDL to LDL is Not Good
//Blood Pressure Profile
//    Systolic: 120       Diastolic: 85
//    Systolic reading is Normal
//    Diastolic reading is High Normal
//
//
//
//Current Patient's Name - Williams
//DATA SET 1
//Cholesterol Profile
//    HDL: 45     LDL: 185
//    Ratio: 0.2432
//    HDL is Okay
//    LDL is High
//    Ratio of HDL to LDL is Not Good
//Blood Pressure Profile
//    Systolic: 190       Diastolic: 112
//    Systolic reading is Stage 3 Hypertension
//    Diastolic reading is Stage 3 Hypertension
//
//DATA SET 2
//Cholesterol Profile
//    HDL: 50     LDL: 181
//    Ratio: 0.2762
//    HDL is Okay
//    LDL is High
//    Ratio of HDL to LDL is Not Good
//Blood Pressure Profile
//    Systolic: 193       Diastolic: 115
//    Systolic reading is Stage 3 Hypertension
//    Diastolic reading is Stage 3 Hypertension
//
//
//
//Current Patient's Name - Foster
//DATA SET 1
//Cholesterol Profile
//    HDL: 55     LDL: 165
//    Ratio: 0.3333
//    HDL is Okay
//    LDL is High
//    Ratio of HDL to LDL is Good
//Blood Pressure Profile
//    Systolic: 163       Diastolic: 115
//    Systolic reading is Stage 2 Hypertension
//    Diastolic reading is Stage 3 Hypertension
//
//DATA SET 2
//Cholesterol Profile
//    HDL: 65     LDL: 145
//    Ratio: 0.4483
//    HDL is Excellent
//    LDL is Borderline High
//    Ratio of HDL to LDL is Good
//Blood Pressure Profile
//    Systolic: 167       Diastolic: 95
//    Systolic reading is Stage 2 Hypertension
//    Diastolic reading is Stage 1 Hypertension
//
//DATA SET 3
//Cholesterol Profile
//    HDL: 57     LDL: 165
//    Ratio: 0.3455
//    HDL is Okay
//    LDL is High
//    Ratio of HDL to LDL is Good
//Blood Pressure Profile
//    Systolic: 163       Diastolic: 105
//    Systolic reading is Stage 2 Hypertension
//    Diastolic reading is Stage 2 Hypertension
//
//DATA SET 4
//Cholesterol Profile
//    HDL: 59     LDL: 163
//    Ratio: 0.3620
//    HDL is Okay
//    LDL is High
//    Ratio of HDL to LDL is Good
//Blood Pressure Profile
//    Systolic: 165       Diastolic: 108
//    Systolic reading is Stage 2 Hypertension
//    Diastolic reading is Stage 2 Hypertension
