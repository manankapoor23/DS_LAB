#include <iostream>
using namespace std;

class Node{
    public:
    // ax^2 +bx+c
    int coeff;
    int power;
    Node* next;

    Node(int c , int p , Node* m){
        this->coeff=c;
        this->power=p;
        this->next=m;
    }
};


void insert(Node* &head,int c , int p){
    Node* temp = new Node{c, p, nullptr};
    if (!head) {
        head = temp;
        return;
    }

    Node* curr = head;
    while (curr->next)
        curr = curr->next;

    curr->next = temp;

}

void display(Node* head) {
    if (!head) {
        cout << "0\n";
        return;
    }

    Node* curr = head;
    while (curr) {
        cout << curr->coeff << "x^" << curr->power;
        if (curr->next)
            cout << " + ";
        curr = curr->next;
    }
    cout << "\n";
}

Node* addPoly(Node* poly1 , Node* poly2){
    if(poly1 == NULL || poly2 == NULL){
        cout<<"either one of the polynomial is incorrect";
        return NULL;
    }
    

    Node* temp_poly = NULL;
    while(poly1&&poly2){

        if(poly1->power==poly2->power){
            insert(temp_poly,poly1->coeff+poly2->coeff,poly1->power);
            poly1=poly1->next;
            poly2=poly2->next;
        }

        // power of poly1 higher
        else if(poly1->power>poly2->power){
            insert(temp_poly,poly1->coeff,poly1->power);
            poly1=poly1->next;
        }
         // power of poly2 higher
        else if(poly2->power>poly1->power){
            insert(temp_poly,poly2->coeff,poly2->power);
            poly2=poly2->next;
        }
    }
    while (poly1) {
        insert(temp_poly, poly1->coeff, poly1->power);
        poly1 = poly1->next;
    }

    // Add remaining terms from p2
    while (poly2) {
        insert(temp_poly, poly2->coeff, poly2->power);
        poly2 = poly2->next;
    }

    return temp_poly;

}

int main(){
    int num ;
    cout<<"enter number of terms : ";
    cin>>num;
    int coeff,power;
    int x;
    cout<<"Enter value of x : ";
    cin>>x;
    Node* poly = NULL;
    Node* poly2 = NULL;
    for(int i =0;i<num;i++){
        cout<<"Enter coeffcient of "<<i+1<< "term from left";
        cin>>coeff;
        cout<<"Enter power : ";
        cin>>power;
        insert(poly,coeff,power);
    }

    int num2;
    cout<<"enter number of terms of second polynomial : ";
    cin>>num2;
    int coeff2,power2;
    for(int i =0;i<num2;i++){
        cout<<"Enter coeffcient of "<<i+1<< "term from left";
        cin>>coeff2;
        cout<<"Enter power : ";
        cin>>power2;
        insert(poly2,coeff2,power2);
    }
    cout << "\nPolynomial: ";
    display(poly);
    cout << "\nPolynomial: ";
    display(poly2);

    Node* sum = addPoly(poly,poly2);
    cout << "\nSum of Polynomials: ";
    display(sum);


}