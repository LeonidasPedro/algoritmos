#include <iostream>
#include <stdexcept>

class DynamicArray {
public:
  DynamicArray(): size_(0), capacity_(1) {
    data_ = new int[capacity_];
  }

  ~DynamicArray(){
    delete[] data_;
  }

  void add(int value){
    if (size_ == capacity_){
      resize();
    }
    data_[size_++] = value;
    std::cout << "Tamanho: " << size_ << " ";
    std::cout << "Capacidade: " << capacity_ << std::endl;
  }

  int get(int index) const {
    if (index < 0 || index >= size_){
      throw std::out_of_range("Out of range");
    }
    return data_[index];
  }

  int size() const {
    return size_;
  }

  int capacity() const{
    return capacity_;
  }

private:
  void resize(){

    capacity_ *= 2;
    int* newData = new int[capacity_];

    for (int i = 0; i < size_; ++i){
      newData[i] = data_[i];
    }

    delete[] data_;
    data_ = newData;
  }

  int* data_;
  int size_;
  int capacity_;
};


int main(){
  DynamicArray arr;

  for (int i = 0; i < 10; ++i) {
        arr.add(i);
  }
  for(int i = 0; i < 10; i++){
    std::cout << arr.get(i) << " capacidade: " << arr.capacity() << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
