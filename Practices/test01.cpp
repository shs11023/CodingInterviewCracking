#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int> &array, int a, int b){
  int temp = array[a];
  array[a] = array[b];
  array[b] = temp;
}

void print_permu(vector<int> &array,int point) {
  if(point == array.size())
  {
    for(int num : array) cout<<num<<" ";
    cout<<endl;
    return;
  }

  for(int i=point ; i<array.size() ; i++) {
    swap (array, point, i);
    print_permu(array, point+1);
    swap (array, point, i);

  }
}

int main(void)
{
  vector<int> array;
  array.push_back(1);
  array.push_back(2);
  array.push_back(3);
  array.push_back(4);

  print_permu (array,0);

  //printf("helloworld!\n");
  return 0;
}

/*
Permutation

0 1 2 3
1 0 2 3
2 0 1 3
3 0 1 2





*/
