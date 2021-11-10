#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// for the overall loop going on for ever; turned off by QUIT command
bool forever = true;

struct Student{
  char first[16];
  char last[16];
  int id;
  float gpa;
};

vector<Student> student = {{
  {'J', 'a', 's', 'o', 'n'}, {'G', 'a', 'l', 'b', 'r', 'a', 'i', 't', 'h'}, 354567, 2.42},
};

// loop trhough the vector and print
void print() {
  for (const auto &print : student) {
    cout 
    << print.first << " " << print.last
    << ", " << print.id 
    << ", " << print.gpa << "\n";
  }
}

// add a student; ask for name, gpa etc and then use that to add to student vector
void added() {
  char first[16], last[16];
  int id;
  float gpa;

  cout << "First Name:";
  cin >> first;
  cout << "Last Name:";
  cin >> last;
  cout << "ID:";
  cin >> id;
  cout << "GPA:";
  cin >> gpa;

  char on=first[0], tw=first[1] , th=first[2] , fr=first[3] , fi=first[4] , si=first[5] , se=first[6] , ei=first[7] , ni=first[8] , te=first[9] , ele=first[10] , twe=first[11] ,thi=first[12] , fou=first[13] , fif=first[14] ;


    char on2=last[0], tw2=last[1] , th2=last[2] , fr2=last[3] , fi2=last[4] , si2=last[5] , se2=last[6] , ei2=last[7] , ni2=last[8] , te2=last[9] , ele2=last[10] , twe2=last[11] ,thi2=last[12] , fou2=last[13] , fif2=last[14] ;

  student.push_back ({{on, tw, th, fr, fi, si, se, ei, ni, te, ele, twe,thi, fou, fif}, {on2, tw2, th2, fr2, fi2, si2, se2, ei2, ni2, te2, ele2, twe2, thi2, fou2, fif2}, id, gpa});

}

// ask for id; loop through vector and find the ids of each section; if it matches with the i then the i becomes order(int) to erase student
void deleted() {
  int id, order;
  cout << "Id of person please:\n";
  cin >> id;

  for(int i = 0; i < student.size(); i++){
    if (student[i].id == id) {
      i = order;
    }
  }

  student.erase(student.begin() + order);

}

int main() {

  while (forever == true) {

    // 4 command matches
    char print2[6] = {'P', 'R', 'I', 'N', 'T'};
    char add2[4] = {'A', 'D', 'D'};
    char delete2[7] = {'D', 'E', 'L', 'E', 'T', 'E'};
    char quit2[5] = {'Q', 'U', 'I', 'T'};

    char command[7];

    cout << "\nCommands are: PRINT, ADD, DELETE, QUIT\n";
    cin >> command;


    //4 for loops for matching commands; if matched then trigger function
    //print
    for (int i = 0; i < strlen(command); i++) {
      if (!(command[i] == print2[i])) {
        break;
      }
      if (i == strlen(print2)-1 && strlen(command) == strlen(print2)) {
        print();
      }
    }

    //added
    for (int i = 0; i < strlen(command); i++) {
      if (!(command[i] == add2[i])) {
        break;
      }
      if (i == strlen(add2)-1 && strlen(command) == strlen(add2)) {
        added();
      }
    }

    //deleted
    for (int i = 0; i < strlen(command); i++) {
      if (!(command[i] == delete2[i])) {
        break;
      }
      if (i == strlen(delete2)-1 && strlen(command) == strlen(delete2)) {
        deleted();
      }
    }

    //quit; no function, turns off the forever bool to turn off while loop
    for (int i = 0; i < strlen(command); i++) {
      if (!(command[i] == quit2[i])) {
        break;
      }
      if (i == strlen(quit2)-1 && strlen(command) == strlen(quit2)) {
        forever = false;
      }
    }
  }

}

/*
Sources:
1.
https://java2blog.com/vector-of-structs-in-cpp/
2. https://stackoverflow.com/questions/8067338/vector-of-structs-initialization
3.
https://stackoverflow.com/questions/875103/how-do-i-erase-an-element-from-stdvector-by-index
*/
