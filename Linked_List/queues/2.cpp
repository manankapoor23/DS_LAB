#include <iostream>

using namespace std;
#define SIZE 5

class CircluarQueue{
    int arr[SIZE];
    int front , rear;

    public:
        CircluarQueue(){
            front =-1;
            rear=-1;
        }

        bool isEmpty(){
            return (front==-1);
        }
        bool isFull(){
            return ((rear+1)%SIZE==front);

        }
        void peek(){
            if(isEmpty()){
                cout<<"what are you looking for , nothings in here !";
            }
            else{
                cout<<"sabse upar : "<<arr[front]<<endl;
            }

        }
        void enqueu(int x ){
            if(isFull()){
                cout<<"The queue is full"<<endl;
                return ;
            }
            if(isEmpty()){
                front = rear = 0 ;
            }
            else{
                rear = (rear+1)%SIZE;
            }
            arr[rear] = x;
            cout << x << " enqueued successfully!" << endl;



        }
        void dequeue(){
            if(isEmpty()){
                cout<<"the queue is empty , cannot be dequeued"<<endl;
                return;
            }
            cout<<"the front element : "<<arr[front]<<"dequed succesfully"<<endl;
            if(front==rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%SIZE;
            }

        }
        void display(){
            if(isEmpty()){
                cout<<"queue is empty"<<endl;
                return ;
            }
            cout<<"queue elements : ";
            int i = front;
            while(true){
                cout<<arr[i]<<" ";
                if(i==rear) break;
                i = (i+1)%SIZE;
            }
            cout<<endl;

        }
};


int main(){
    CircluarQueue q ;
    int choice , value ;
    do{
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
               cout<<"enter the value to enqueu";
               cin>>value;
               q.enqueu(value);
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

                
            

        }
        while(choice!=0);
        return 0 ;
    }
