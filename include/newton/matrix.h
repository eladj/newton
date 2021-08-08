#include <iostream>
#include <vector>

class Matrix{
 public:
  void print(){
    for (const float& x : data){
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
 private:
  std::vector<float> data = {1, 2, 3};
};