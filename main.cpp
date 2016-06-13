#include <iostream>
#include "header.h"
using namespace std;

int main (int argc, char** argv)
{
  int i;
  cout << "Please enter an integer value: ";
  cin >> i;
  cout << "The value you entered is " << i;

  if(i == 1) {
	  rsi_main(argc, argv);
  } else if(i==2) {
	  ris_main(argc, argv);
  } else if(i==3) {
	  it_main(argc, argv);
  } else if(i==4) {
	  aip_main(argc, argv);
  }
  return 0;
}
