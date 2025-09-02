#include<iostream>
using namespace std;
class kqueue{
   public:
      int n;
      int k;
      int *arr;
      int *front;
      int *rear;
      int *next;
      int freespot;

      // constructor
      kqueue(int n, int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        for(int i=0;i<k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i=0;i<n;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        freespot = 0; 
      }

     // Push in Queue
      void enqueue(int data, int qn){
        if(freespot == -1){
            cout<<"no empty space available";
            return;
        }
        int index = freespot;

        freespot= next[index];

        if(front[qn-1] == -1){
            front[qn-1] = index;
        }
        else{
            next[rear[qn-1]] = index;
        }

        next[index] = -1;

        rear[qn-1] = index;

        arr[index] = data;

      }

      // pop from queue
      int dequeue(int qn){
        if(front[qn-1] == -1){
            cout<<"Queue is underflow";
            return -1;
        }

        int index = front[qn-1];
        front[qn-1] = next[index];

        next[index] = freespot;
        freespot = index;

        return arr[index];
      }
};

int main(){
     kqueue q(10,3);

     q.enqueue(10,1);
     q.enqueue(15,1);
     q.enqueue(20,2);
     q.enqueue(25,1);

     cout<< q.dequeue(1);

    return 0;
}