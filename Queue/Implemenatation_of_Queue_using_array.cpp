#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear;
    int size;

    public:
       Queue(){
           size = 100001;
           arr = new int[size];
           front =0;
           rear =0;
       }

       bool isempty(){
              if(front == rear){
                return true;
              }
              return false;
       }

       void enqueue(int x){
          if(rear == size){
            cout<<"Queue is Full";
          }
          else{
            arr[rear] = x;
            rear++;
          }
       }

       int dequeue(){
             if(front == rear){
                return -1;
             }

             else{
                int ans = arr[front];
                arr[front] = -1;
                front++;
                if(front == rear){
                    front = 0;
                    rear = 0;
                }
                return ans;
             }
       }

       int getfront(){
              if(front == rear){
                return -1;
              }
              else{
                return arr[front];
              }
       }
};

int main(){
    Queue q;
    q.enqueue(27);
    q.enqueue(30);
    q.enqueue(33);
    q.enqueue(36);

    cout<< q.getfront()<<endl;
    q.dequeue();
    cout<< q.getfront()<<endl;

    q.isempty() ? cout<<"Queue Is Empty" : cout<<"Queue is Not Empty";

}