#include <iostream>
#include <vector>

template <typename T>
class BinarySearch{
    /*
     * Let consider array = [2, 3, 9, 19, 21]
     * low = 0, high = 4 -> last index...
     */
    int binarySearch(const std::vector<T> &seq , const T& _key, const int& low, const int& high) {
        if (high == low && seq[low] == _key) {
            return low; // low is index position at which value found. same as high...
        }
        int mid = (low + high) / 2; // dividing array into half part at each recursion.
        if (_key == seq[mid]) {
            return mid;
        }
        else if (_key > seq[mid] ) {
            if (high == mid) { //if mid reached at high list is ended...
                return -1;
            }
            return binarySearch(seq, _key, mid + 1, high);
        }
        else {
            if (low == mid) { // if mid reached at low list is ended...
                return -1;
            }
            return binarySearch(seq, _key, low, mid - 1);
        }

    }

public:
    /*
     * Binary search with the recursion method. ....
     */
    int bSearch_r(std::vector<T> seq , const T& _value){
        if (seq.size() == 0){
            return 0;
        }
        return binarySearch(seq, _value, 0, seq.size() - 1);
    }

    //...........binary search with the help of iterations. . . . . . . . .//
    int bSearch(const std::vector<T> &seq, const T& _value) {
        int firstIndex = 0;
        int lastIndex = seq.size() - 1;

        int mid = (firstIndex + lastIndex) / 2;

        while (mid >= firstIndex && mid < seq.size()) {
            if (_value > seq[mid])
                mid++;
            else if (_value < seq[mid])
                mid--;
            else if (seq[mid] == _value)
                return mid; // mid is index.
        }

        return -1; //if not found.
    }
};




int main(){

    BinarySearch<int> binarySearch;
    std::vector<int> sequence;
    sequence.push_back(2);
    sequence.push_back(4);
    sequence.push_back(6);

    std::cout << binarySearch.bSearch_r(sequence, 4) ;
    std::cout << "\nBinary search with iteration :: " << binarySearch.bSearch(sequence, 9);
    return 0;
}
