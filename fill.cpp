#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


#define FILENAME "input.txt"
#define NUMBER_OF_ITEMS 100
#define UPPER_RANGE 1000



int main(){
  srand(time(NULL));

  fstream fout;
  fout.open(FILENAME);
  if(fout.is_open()){
    fout << NUMBER_OF_ITEMS << endl;
    for(int i = 0; i < NUMBER_OF_ITEMS; ++i){
      fout << rand() % UPPER_RANGE + 1 << endl;
    }
  }

  fout.close();

  return 0;
}
