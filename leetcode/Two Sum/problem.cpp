#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target);

int main(int argc, char **argv)
{
  vector<int> numbers;
  numbers.push_back(2);
  numbers.push_back(7);
  numbers.push_back(11);
  numbers.push_back(15);

  int target = 9;

  vector<int> result = twoSum(numbers, target);

  cout << "index1=" << result[0] << ", index2=" << result[1] << endl;

  return 0;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
  for (int i = 0; i < numbers.size(); ++i) {
	for (int j = i + 1; j < numbers.size(); ++j) {
	  if (numbers[i] + numbers[j] == target) {
		vector<int> result;
		result.push_back(i + 1);
		result.push_back(j + 1);
		return result;
	  }
	}
  }
}
