#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <list>
#include <algorithm>
#include <cstdio>
#include <iterator>
#include <sstream>

using namespace std;
string pa;
int intpa;
int playerLoc;

int tree1;
int tree2;
int tree3;
int rock1;

map<int, string> board { 
  {1, " "},
  {2, " "},
  {3, " "},
  {4, " "},
  {5, " "},
  {6, " "},
  {7, " "},
  {8, " "},
  {9, " "},
  {10, " "},
  {11, " "},
  {12, " "},
  {13, " "},
  {14, " "},
  {15, " "},
  {16, " "},
  {17, " "},
  {18, " "},
  {19, " "},
  {20, " "},
  {21, " "},
  {22, " "},
  {23, " "},
  {24, " "},
  {25, " "}
};


void curBoard() {
  cout << "|" << board[1] << "|" << board[2] << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|" << endl;
  cout << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|" << board[9] << "|" << board[10] << "|" << endl;
  cout << "|" << board[11] << "|" << board[12] << "|" << board[13] << "|" << board[14] << "|" << board[15] << "|" << endl;
  cout << "|" << board[16] << "|" << board[17] << "|" << board[18] << "|" << board[19] << "|" << board[20] << "|" << endl;
  cout << "|" << board[21] << "|" << board[22] << "|" << board[23] << "|" << board[24] << "|" << board[25] << "|" << endl;
}
void moving() {
  if ((pa == "w")&&(playerLoc != 1)&&(playerLoc != 2)&&(playerLoc != 3)&&(playerLoc != 4)&&(playerLoc != 5)) {
    intpa -= 5;
    if ((intpa == tree1)||(intpa == tree2)||(intpa == tree3)||(intpa == rock1)) {
      cout << "Blocked by object" << endl;
      intpa = playerLoc;
    }
    else {
      board[intpa] = "+";    
      board[playerLoc] = " ";
      playerLoc = intpa;      
    }
  }
  else if ((pa == "a")&&(playerLoc != 1)&&(playerLoc != 6)&&(playerLoc != 11)&&(playerLoc != 16)&&(playerLoc != 21)) {
    intpa -= 1;
    if ((intpa == tree1)||(intpa == tree2)||(intpa == tree3)||(intpa == rock1)) {
      cout << "Blocked by object" << endl;
      intpa = playerLoc;
    }
    else {
      board[intpa] = "+";    
      board[playerLoc] = " ";
      playerLoc = intpa;      
    }
  }  
  else if ((pa == "d")&&(playerLoc != 5)&&(playerLoc != 10)&&(playerLoc != 15)&&(playerLoc != 20)&&(playerLoc != 25)) {
    intpa += 1;
    if ((intpa == tree1)||(intpa == tree2)||(intpa == tree3)||(intpa == rock1)) {
      cout << "Blocked by object" << endl;
      intpa = playerLoc;
    }
    else {
      board[intpa] = "+";    
      board[playerLoc] = " ";
      playerLoc = intpa;      
    }
  }  
  else if ((pa == "s")&&(playerLoc != 21)&&(playerLoc != 22)&&(playerLoc != 23)&&(playerLoc != 24)&&(playerLoc != 25)) {
    intpa += 5;
    if ((intpa == tree1)||(intpa == tree2)||(intpa == tree3)||(intpa == rock1)) {
      cout << "Blocked by object" << endl;
      intpa = playerLoc;
    }
    else {
      board[intpa] = "+";    
      board[playerLoc] = " ";
      playerLoc = intpa;      
    }
  }  
  else {cout << "Way is Blocked!" << endl;}
}

void actions() {
  int pLeft = playerLoc - 1;
  int pRight = playerLoc + 1;
  int pUp = playerLoc - 5;
  int pDown = playerLoc + 5;
  if (board[pLeft] != " ") {
    if (pLeft == tree1) {
      cout << ">> Chop wood" << endl;
    }
    if (pLeft == tree2) {
      cout << ">> Chop wood" << endl;
    }
    if (pLeft == tree3) {
      cout << ">> Chop wood" << endl;
    }
    if (pLeft == rock1) {
      cout << ">> Mine Rock" << endl;
    }
  }
  if (board[pRight] != " ") {
    if (pRight == tree1) {
      cout << ">> Chop wood" << endl;
    }
    if (pRight == tree2) {
      cout << ">> Chop wood" << endl;
    }
    if (pRight == tree3) {
      cout << ">> Chop wood" << endl;
    }
    if (pRight == rock1) {
      cout << ">> Mine Rock" << endl;
    }
  }
  if (board[pUp] != " ") {
    if (pUp == tree1) {
      cout << ">> Chop wood" << endl;
    }
    if (pUp == tree2) {
      cout << ">> Chop wood" << endl;
    }
    if (pUp == tree3) {
      cout << ">> Chop wood" << endl;
    }
    if (pUp == rock1) {
      cout << ">> Mine Rock" << endl;
    }
  }
  if (board[pDown] != " ") {
    if (pDown == tree1) {
      cout << ">> Chop wood" << endl;
    }
    if (pDown == tree2) {
      cout << ">> Chop wood" << endl;
    }
    if (pDown == tree3) {
      cout << ">> Chop wood" << endl;
    }
    if (pDown == rock1) {
      cout << ">> Mine Rock" << endl;
    }
  }
}


int main() {  
  srand (time(NULL));
  while (true) {
    tree1 = rand() % 25 + 1;
    tree2 = rand() % 25 + 1;
    tree3 = rand() % 25 + 1;
    rock1 = rand() % 25 + 1;
    if ((tree1 != tree2)&&(tree1 != tree3)&&(tree1 != rock1)&&(tree2 != tree3)&&(tree2 != rock1)&&(tree3 != rock1)) {
      break;
    }
  }
  board[tree1] = "*";
  board[tree2] = "*";
  board[tree3] = "*";
  board[rock1] = "¤";

  while (true) {
    curBoard();
    cin >> pa;
    intpa = stoi(pa); 
    if ((intpa != tree1)&&(intpa != tree2)&&(intpa != tree3)&&(intpa != rock1)) {
      board[intpa] = "+";
      playerLoc = intpa;
      break;
    }
    else {cout << "Invalid Placement" << endl;}
  }
 



  while (true) {
    curBoard();
    cin >> pa;  
    if ((pa == "w")||(pa == "a")||(pa == "s")||(pa == "d")) {
      moving();
    }
    else if (pa == "f") {
      actions();
    }
  }





}
