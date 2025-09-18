#include <iostream>

using namespace std ;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front , rear;

    public:
        Queue(){
            front =-1;
            rear =-1;
        }
        bool isEmpty(){
            if(front==-1){
                return true; 
            }
            return false;
        }
        bool isFull(){
            if(rear==SIZE-1){
                return true;
            }
            return false;
        }

        void enqueue(int x ){
            if(isFull()){
                front = 0 ;
                rear = 0 ;
            }
            if(isEmpty()){
                front = 0 ;
                rear = 0 ;
            }
            arr[++rear]=x;
            cout<<x<<"enqued succesfull"<<endl;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"queue is empty , cannot delete"<<endl;
                return;
            }
            cout<<arr[front]<<"dequed succesfully"<<endl;
            if(front == rear ){
                front = rear = -1 ;
            }
            else{
                front++;
            }
        }

        void peek(){
            if(isEmpty()){
                cout<<"queue is empty"<<endl;
            }
            else{
                cout<<"front element is : "<<arr[front]<<endl;
            }
        }

        void display(){
                if(isEmpty()){
                    cout<<"queue is empty"<<endl;
                    return;
            }
            cout<<"queue elements :";
            int i = front;
            while(true){
                cout<<arr[i]<<" ";
                if(i==rear) break;
                i=(i+1)%SIZE;
            }
            cout<<endl;


        }

};


int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty()) cout << "Queue is EMPTY." << endl;
            else cout << "Queue is NOT EMPTY." << endl;
            break;
        case 6:
            if (q.isFull()) cout << "Queue is FULL." << endl;
            else cout << "Queue is NOT FULL." << endl;
            break;
        case 0:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}