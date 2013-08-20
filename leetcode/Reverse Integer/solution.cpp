#include <iostream>
#include <vector>

using namespace std;

int reverse(int x);

int main(int argc, char **argv)
{
        vector<int> testData;

        testData.push_back(1000);
        testData.push_back(-1000);
        testData.push_back(1234);
        testData.push_back(-1234);
        testData.push_back(0);

        for (int i = 0; i < testData.size(); ++i) {
                cout << "reverse of " << testData[i] << " : " << reverse(testData[i]) << endl;
        }

        return 0;
}

int reverse(int x)
{
        int result = 0;

        if (x > 0) {
                while (x > 0) {
                        result *= 10;
                        result += x % 10;
                        x /= 10;
                }
        } else if (x < 0){
                while (x < 0) {
                        result *= 10;
                        result -= (-x) % 10;
                        x /= 10;
                }
        } else {
                result = 0;
        }

        return result;
}