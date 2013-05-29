#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool is_palindrome(string str);
void partition(vector<string> , string , vector<vector<string> >& );
void print(vector<string>);

int main(int argc, char **argv)
{
  vector<string> empty;
  string orig;
  vector<vector<string> > solutions;

  cin >> orig;
  partition(empty, orig, solutions);
  for (int i = 0; i < solutions.size(); ++i) {
	print(solutions[i]);
  }

  return 0;
}

bool is_palindrome(string str)
{
  if (str.empty()) {
	return false;
  }

  for (int p = 0, q = str.size() - 1; p < q; ++p, --q) {
	if (str[p] != str[q]) {
	  return false;
	}
  }

  return true;
}

void partition(vector<string> palindromes, string string_left, vector<vector<string> > &solutions)
{
  if (string_left.empty()) {
	// cout << "Solution : ";
	// for (int i = 0; i < palindromes.size(); ++i) {
	//   cout << palindromes[i] << ' ';
	// }
	// cout << endl;
	solutions.push_back(palindromes);
  }

  for (int i = 0; i < string_left.size(); ++i) {
	vector<string> tmp = palindromes;
	if (is_palindrome(string_left.substr(0, i + 1))) {
	  tmp.push_back(string_left.substr(0, i + 1));
	  if (i != string_left.size() - 1) {
		partition(tmp, string_left.substr(i + 1), solutions);
	  } else {
		partition(tmp, "", solutions);
	  }
	}
  }
}

void print(vector<string> vec)
{
  cout << "Solution : ";
  for (int i = 0; i < vec.size(); ++i) {
	cout << vec[i] << ' ';
  }
  cout << endl;
}
