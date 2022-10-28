// Mack Foggia - CS 350
// 4/8/2021 - Quick Sort

#include <iostream>
#include <string>
using namespace std;


void quickSort(int array[], int low, int high);
void swap(int array[], int a, int b);


int main(){
  int num = 0;
  int * array = NULL;

  cout << "How many data point are there? ";
  cin >> num;
  cin.ignore(100, '\n');

  array = new int[num];

  cout << "Please enter " << num << " data points." << endl;

  for(int i = 0; i < num; ++i){
    cin >> array[i];
    cin.ignore(100, '\n');
  }

  //Print pre sort
  cout << endl;
  for(int i = 0; i < num; ++i){
    cout << array[i] << " ";
  }
  cout << endl;

  //Sort
  quickSort(array, 0, num - 1);

  //Post sort print
  cout << endl;
  for(int i = 0; i < num; ++i){
    cout << array[i] << " ";
  }
  cout << endl;

  delete [] array;

  return 0;
}



void quickSort(int array[], int low, int high){
  if(low == high) return;

  int pivot = low;
  int p1 = pivot + 1, p2 = high;
  bool p1halt = false, p2halt = false;

  while(p1 < p2){
    if(!p1halt && array[p1] < array[pivot]) ++p1;
    else p1halt = true;
    if(!p2halt && array[p2] > array[pivot]) --p2;
    else p2halt = true;
    
    if(p1halt && p2halt){
      p1halt = p2halt = false;
      swap(array, p1, p2);
      ++p1; --p2;
    }
  }

  if(array[p2] < array[pivot]){
    swap(array, p2, pivot);
    pivot = p2;
  }
  else {
    swap(array, p2 - 1, pivot);
    pivot = p2 - 1;
  }

  if(pivot - low > 1) quickSort(array, low, pivot - 1);
  if(high - pivot > 1) quickSort(array, pivot + 1, high);
}
 

void swap(int array[], int a, int b){
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}
