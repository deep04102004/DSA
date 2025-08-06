#include <iostream>
using namespace std;

class nstacks{
    int *arr;
    int *top;
    int *next;

    int n,s;
    int freespot;

public:
    nstacks(int N,int S){
        n=N;
        s=S;

        arr=new int[s];
        top=new int[n];
        next=new int[s];

        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        
        for(int i=0;i<s;i++){
            next[i]=i+1;
        }

        next[s-1]=-1;
        freespot=0;
    }

    bool push(int x, int m){
            if(freespot == -1){
                return false;
            }
            //find index
            int index= freespot;
            
            //update freespot
            freespot=next[index];
            
            //push value
            arr[index]=x;
            
            //update next
            next[index]=top[m-1];
            
            //update top
            top[m-1]=index;

            return true;
    }

    int pop(int m){
        if(top[m-1] == -1){
            return -1;
        }
    
        int index=top[m-1];

        top[m-1]=next[index];

        next[index]=freespot;

        freespot=index;

        return arr[index];
    }
};

int main()
{
    nstacks st(3, 10); // 3 stacks, total size 10

    st.push(10, 1);
    st.push(20, 1);
    st.push(30, 2);
    st.push(40, 3);

    cout << st.pop(1) << endl; // 20
    cout << st.pop(2) << endl; // 30
    cout << st.pop(3) << endl; // 40
    cout << st.pop(1) << endl; // 10
    cout << st.pop(1) << endl; // -1 (empty)

    return 0;
}