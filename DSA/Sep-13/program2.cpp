#include <iostream>
using namespace std;

class node {
    public :
        int K;
        int V;
        node* next;

        node(int K, int V){
            this->K = K;
            this->V = V;
            this->next = NULL;
        }
};

class HashMap{
    int N; // hash table capacity
    int M; 
    double L; 

    node** T; 

    int hashFn(int K){
        return K%N;
    }

    void transfer(node* head){
        node * temp = head;
        while( temp != NULL){
            insert( temp ->K, temp ->V);
            temp = temp ->next;
        }

        while(head != NULL){
            node* temp = head ->next;
            delete head;
            head = temp;
        }
    }

    void rehash(){
          node** oldT = T;
          int oldN = N;

        T = new node*[ 2* N];

        for(int i =0;  i < N; i++){
            T[i] = NULL;
        }

        N = 2* N;
        M = 0;

        for(int i =0; i < oldN; i++){
            // transfer the LL at the ith index of oldT
            transfer(oldT[i]);
        }

        delete [] oldT;
    }

    public:

    HashMap(int N=7, double L=0.7){
        this->N = N;
        this->M = 0;
        this->L = L;

        T = new node* [N];

        for(int i = 0; i < N; i++){
            T[i] = NULL;
        }
    }

    void insert(int K, int V){
        int hashIdx = hashFn(K);

        node* n = new node(K,V);

         n ->next = T[hashIdx];
         T[hashIdx] = n;
         M++;


        double LF = M * 1.0 /N;
        
        if(LF > L){
            cout << "rehashing due to LF" << LF << endl;
            rehash();
        }
    }

    node* find(int K){
        int hashIdx = hashFn(K);
        
        node* temp = T[hashIdx];
        while(temp != NULL){
            if(temp->K == K){
                break;
            }
            temp = temp->next;
        }
        
        return temp;
    }
    
    void erase(int K){
        int hashIdx = hashFn(K);

        //delete the node with the given key
        node* temp = T[hashIdx];
        node* prev = NULL;
        while(temp != NULL){
            if(temp ->K == K){
                prev->next = temp->next;
                delete temp;
                M--;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

    }

    void printLinkedList(node* head){
        while(head){  //head != NULL
            cout << "{" << head->K << ", "<< head->V << "}" ;
        }
        cout << endl;
    }

    void printHashMap(){
        for(int i = 0; i< N; i++){
            cout << i << ": ";
            printLinkedList(T[i]);
        }
        cout << endl;
    }
};


int main(){
    HashMap hm;

    hm.insert(0,0);
    hm.insert(2,4);
    hm.insert(7,49);

    hm.printHashMap();

    int key = 7;
    node* temp = hm.find(key);

    if(temp != NULL){
        cout << temp->V << endl;
    }else{
        cout << key << " is not found"<< endl;
    }


    return 0;
}