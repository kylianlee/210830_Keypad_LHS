//
// Created by Kylian Lee on 2021/08/26.
//

#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Btn{
 private:
  int x;
  int y;
 public:
  Btn(int x, int y){
    this->x = x;
    this->y = y;
  }
  int getDistance(Btn b){
    int x2 = b.getX();
    int y2 = b.getY();
    return abs(this->x - x2) + abs(this->y - y2);
  }
  [[nodiscard]] int getX() const {return x;}
  [[nodiscard]] int getY() const {return y;}
};

string solution(vector<int> numbers, const string& hand) {
  string answer;
  Btn b1(0, 0);
  Btn b2(1, 0);
  Btn b3(2, 0);
  Btn b4(0, 1);
  Btn b5(1, 1);
  Btn b6(2, 1);
  Btn b7(0, 2);
  Btn b8(1, 2);
  Btn b9(2, 2);
  Btn b0(1, 3);
  Btn currentL(0, 3);
  Btn currentR(2, 3);
  Btn buttons[10] = {b0, b1, b2, b3, b4, b5, b6, b7, b8, b9};
  bool right_hand = true;
  if(hand == "left")
    right_hand = false;
  unsigned long size = numbers.size();
  for (int i = 0; i < size; ++i) {
    int idx = numbers[i];
    Btn temp = buttons[idx];
    if(idx == 1 || idx == 4 || idx == 7){
      answer.push_back('L');
      currentL = temp;
      continue;
    }
    if(idx == 3 || idx == 6 || idx == 9){
      answer.push_back('R');
      currentR = temp;
      continue;
    }
    int distL = currentL.getDistance(temp);
    int distR = currentR.getDistance(temp);
    if(distL < distR){
      answer.push_back('L');
      currentL = temp;
    }
    else if(distR < distL){
      answer.push_back('R');
      currentR = temp;
    }
    else{
      if(right_hand){
        answer.push_back('R');
        currentR = temp;
      }
      else{
        answer.push_back('L');
        currentL = temp;
      }
    }
  }
  return answer;
}
int main(){
  //  vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
  //  vector<int> numbers = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
  vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  //  string hand = "right";
  //  string hand = "left";
  string hand = "right";
  cout << solution(numbers, hand) << endl;

  return 0;
}