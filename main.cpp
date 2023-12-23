#include <iostream>
#include <cstdlib>

using namespace std;

class Stack{
  private:
    int len;
    int* arr;
    int size;
    
    void trim(){
      if (this->size > this->len * 5){
        this->size = this->len + 5;
        this->arr = (int *)realloc(this->arr, this->size * sizeof(int));
      };
    }
  
  public:
    Stack(){
      this->len = 0;
      this->size = 5;
      this->arr = (int*)malloc(sizeof(int) * this->size);
    }
    void push(int a){
      if (!(this->len < this->size)){
        this->size += 5;
        this->arr = (int*)realloc(this->arr, this->size * sizeof(int));
      }
      this->arr[this->len] = a;
      this->len += 1;
    }
    int pop(){
      this->trim();
      if (this->len != 0){
        this->len -= 1;
        return this->arr[this->len];
      };
      return -1;
    }
    int peek(){
      if (this->len != 0){
        return this->arr[this->len - 1];
      };
      return -1;
    }
    ~Stack(){
      free(this->arr);
    }
    


};

int main(){
  Stack* mystack = new Stack();
  mystack->push(19);
  mystack->push(20);
  mystack->push(21);
  mystack->push(23);
  cout<<mystack->pop()<<endl;
  cout<<mystack->pop()<<endl;
  cout<<mystack->pop()<<endl;
  cout<<mystack->pop()<<endl;
  delete mystack;
  return 0;
}
