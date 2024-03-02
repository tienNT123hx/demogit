#include <iostream>
using namespace std;

class Array {
  private:
    int length;
    int *data;

  public:
    Array(int length) {
      this->length = length;
      data = new int[length];
    }

    ~Array() {
      delete[] data;
    }

    int &operator[](int index) {
      return data[index];
    }

    friend ostream &operator<<(ostream &os, const Array &arr) {
      for (int i = 0; i < arr.length; i++) {
        os << arr.data[i] << " ";
      }
      return os;
    }

    friend istream &operator>>(istream &is, Array &arr) {
      for (int i = 0; i < arr.length; i++) {
        is >> arr.data[i];
      }
      return is;
    }

    int operator()() {
      int max = data[0];
      for (int i = 1; i < length; i++) {
        if (data[i] > max) {
          max = data[i];
        }
      }
      return max;
    }

    Array operator+(const Array &arr) {
      Array arr1(arr.length);
      for (int i = 0; i < arr.length; i++) {
        arr1[i] = data[i] + arr.data[i];
      }
      return arr1;
    }

    Array operator-(const Array &arr) {
      Array arr1(arr.length);
      for (int i = 0; i < arr.length; i++){
      	arr1[i] = data[i] - arr.data[i];
      }
      return arr1;
	  } 
	  
	 Array operator*(const Array &arr1, const Array &arr2) {

  Array arr(arr1.length);
  for (int i = 0; i < arr1.length; i++) {
    arr[i] = arr1[i] * arr2[i];
  }
  return arr;
}

Array operator*(const Array &arr, int a) {
  Array arr1(arr.length);
  for (int i = 0; i < arr.length; i++) {
    arr1[i] = data[i] * a;
  }
  return arr1;
}

};

int main() {
  Array arr1(5);
  arr1[0] = 1;
  arr1[1] = 2;
  arr1[2] = 3;
  arr1[3] = 4;
  arr1[4] = 5;

  Array arr2(5);
  arr2[0] = 6;
  arr2[1] = 7;
  arr2[2] = 8;
  arr2[3] = 9;
  arr2[4] = 10;

  Array arr3 = arr1 + arr2;

  cout << "M?ng arr1: ";
  cout << arr1 << endl;

  cout << "M?ng arr2: ";
  cout << arr2 << endl;

  cout << "M?ng arr3 = arr1 + arr2: ";
  cout << arr3 << endl;

  int a = 2;
  

  cout << "M?ng arr1 * 2: ";
  

  return 0;
}

