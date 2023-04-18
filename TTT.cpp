#include <iostream>
#include <cstdlib>
#include <ctime>

void printarray(char ttboard[3][3]);
bool win(char ttboard[3][3]);
bool duplicate(char ttboard[3][3], int index);
bool isfull(char tttboard[3][3]);

int main() {
  char tttboard[3][3] = {{'0','0','0'},{'0','0','0'},{'0','0','0'}};
  int index = 0;
  int truey = 0;

  srand(time(0));

  while (!win(tttboard) && !isfull(tttboard)) {
    truey = 0;
        while(!duplicate(tttboard,index) || truey != 1){
            std::cout << "Choose where you want to place X? (1-9): ";
            std::cin >> index;
            truey = 1;
            if(!duplicate(tttboard,index)){
                std::cout << "There's an " << tttboard[(index - 1) / 3][(index - 1) % 3] << " located at this spot. try again." << std::endl;
            }
        }
        int row = (index - 1) / 3;
        int col = (index - 1) % 3;
        tttboard[row][col] = 'X';
        index = rand() % 9 + 1;
        while(!duplicate(tttboard,index)){
            index = rand() % 9 + 1;
        }
        row = (index - 1) / 3;
        col = (index - 1) % 3;
        tttboard[row][col] = 'O';
    printarray(tttboard);
    // code to update the tttboard based on the user's choice
  }
  if(isfull(tttboard)){
    std::cout<<"No one wins. Game Over!" << std::endl;
  }
  return 0;
}

bool isfull(char tttboard[3][3]){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tttboard[i][j] != '0'){
                count++;
            }
        }
    }
    
    return count == 9;
}


bool duplicate(char ttboard[3][3], int index){
    int row = (index - 1) / 3;
    int col = (index - 1) % 3;
    if(ttboard[row][col] != '0'){
        return false;
    }
    return true;
}

void printarray(char ttboard[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << ttboard[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


bool win(char ttboard[3][3]) {
  for(int i = 0; i < 3; i++){
    if(((ttboard[i][0] == ttboard[i][1]) && (ttboard[i][1] == ttboard[i][2])) && ttboard[i][1] != '0' ){
        return true;
    }
    if(((ttboard[0][i] == ttboard[1][i]) && (ttboard[1][i] == ttboard[2][i])) && ttboard[1][i] != '0' ){
        return true;
    }
  }
  if((ttboard[2][0] == ttboard[1][1] && ttboard[1][1] == ttboard[0][2] && ttboard[1][1] != '0') || (ttboard[0][0] == ttboard[1][1] && ttboard[1][1] == ttboard[2][2]) && ttboard[1][1] != '0'){
    return true;
  }
  return false;
}
