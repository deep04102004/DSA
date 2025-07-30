#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//recursive function
void solve(stack<int>&st,int count,int mid){
    if(count == mid){
        st.pop();
        return;
    }

    int top=st.top();
    st.pop();

    solve(st,count+1,mid);

    st.push(top);
}

void deletemiddle(stack<int>&st){
    int n=st.size();
    int mid=n/2;
    int count=0;
    
    solve(st,count,mid);
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}


int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5); // Stack top -> 5 4 3 2 1

    deletemiddle(st);

    cout << "Stack after deleting middle element:\n";
    printStack(st);  // Output should be: 5 4 2 1

    return 0;
}