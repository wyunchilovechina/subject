#include <iostream>

using namespace std;

const int MAXSQRT = 46341;

int sqrt(int x);

int main(int argc, char **argv)
{
  cout << sqrt(2147395599) << endl;
  cout << sqrt(1) << endl;

  return 0;
}

int sqrt(int x)
{
  int small = 0, big = MAXSQRT;

  while (small <= big) {
	int middle = small + (big - small) / 2;
	if (small == middle) {
	  return small;
	}
	if (middle * middle > x) {
	  big = middle;
	} else if (middle * middle < x) {
	  small = middle;
	} else {
	  return middle;
	}
  }
}
