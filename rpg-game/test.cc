#include <iostream>
int main() {
  int arr[6]{1, 2, 3, 4, 5, 6};
  std::cout << "Size or arr: " << sizeof(arr) / sizeof(arr[0]) << std::endl;
}
