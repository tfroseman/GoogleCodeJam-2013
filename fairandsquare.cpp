#include "iostream";
#include "vector";
#include "fstream";
#include "cmath";
#include "list";
#include "sstream";

using namespace std;

bool ispal_list(const int testNumber);
int calcSquare(int caseNumber);

int main(){

    bool isPal = false;
    double TestNumber=0;
    bool subfairSquare=false;
    int testingNumber=0;
    long long testCases=0;
    unsigned long long lowRange, highRange=0;
    int amtFairSquare=0;
    double valid;
    int temp;



    ifstream googleInput;
    ofstream googleOutput;

    googleInput.open("C-large-2.in");
    googleOutput.open("small.out");

    googleInput >> testCases;
 
    for(int w=1; w<=testCases; ++w){
        //cout << " RANGE: ";
        googleInput >> lowRange >> highRange;
        cout << lowRange;
        for (double i = lowRange; i <= highRange; ++i){

            isPal=ispal_list(i);
            if(isPal){
                temp=sqrt(i);
                TestNumber=temp;
                valid = pow(TestNumber,2);

                if(valid == i){
                    subfairSquare=false;
                    subfairSquare=ispal_list(TestNumber);
                    if (subfairSquare==true){
                        amtFairSquare++;
                    }
                }
            }
        }
        googleOutput << "Case #" << w << ": " << amtFairSquare << endl;
        //cout << "Case #" << w << ": " << amtFairSquare << endl;
        amtFairSquare=0;
    }



    return 0;
}


bool ispal_list(const int testNumber) {
    // Given: s is a string of characters
    // Returns: true if s contains a palindrome, false if it doesn't
    // Method: build a local list of chars using only the alphanumeric characters, ignoring case, from s
    //		then as long as the front of the list equals the back of the list,
    //		pop the front and the back. When you are done if the list is empty or contains
    //		only one character, s was a palindrome. If it contains more than one character
    //		s was not a palindrome. Note: This method destroys the contents of the list

    bool result=false;
    string convertString;

    stringstream handleString;

    handleString << testNumber;
    handleString >> convertString;

    std::list<char> testList;

    for(int i=0; i<convertString.size(); i++) {
        testList.push_back(convertString[i]);
    }

    for(int o=0; testList.size()>1; o++) {
        if(testList.front()==testList.back()) {
            testList.pop_front();
            testList.pop_back(); 
        }else{
            return result;}}

    if ((testList.size()<=1)) {
        testList.clear();
        result=true; }

    testList.clear();
    return result; } // is_pal_list()