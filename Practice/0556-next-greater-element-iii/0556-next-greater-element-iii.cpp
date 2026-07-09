class Solution {
public:
    int nextGreaterElement(int n) {
       string numberString = to_string(n);
        int length = numberString.length();
        int breakPoint = length - 2;
        while (breakPoint >= 0 && numberString[breakPoint] >= numberString[breakPoint + 1]) {
            breakPoint--;
        }
        if (breakPoint < 0) {
            return -1;
        }
        int swapPoint = length - 1;
        while (numberString[swapPoint] <= numberString[breakPoint]) {
            swapPoint--;
        }   
        swap(numberString[breakPoint], numberString[swapPoint]);
        int leftIndex = breakPoint + 1;
        int rightIndex = length - 1;
        
        while (leftIndex < rightIndex) {
            swap(numberString[leftIndex], numberString[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
        long long result = stoll(numberString);
        if (result > INT_MAX) {
            return -1;
        }
        return result;
    }
};