vector<int> grayCode(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n == 0) {
        vector<int> result(1, 0);
        return result;
    } else {
        int size = 1 << (n - 1);
        vector<int> result = grayCode(n - 1);
        for (int i = size - 1; i >= 0; --i) {
            result.push_back(result[i] + (1 << (n - 1)));
        }
        
        return result;
    }
}