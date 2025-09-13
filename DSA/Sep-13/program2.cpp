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
    int N; // to store the hash table capacity
    int M; // to store the hash table size
    double L; // to store the load factor threshold

    node** T; // to store the pointer to the dynamic array that represents the hash table

    int hashFn(int K){
        // transform K into a hash index
        return K%N;
    }

    void transfer(node* head){
        // 1. rehash (k,v) pairs present in LL represented by "head" pointer to updated hashMap
        node * temp = head;
        while( temp != NULL){
            insert( temp ->K, temp ->V);
            temp = temp ->next;
        }

        //2. release memory allocated for the LL represented by "head" pointer
        while(head != NULL){
            node* temp = head ->next;
            delete head;
            head = temp;
        }
    }

    void rehash(){
        // 1. save pointer to the current hashMap and its capacity
          node** oldT = T;
          int oldN = N;

        // 2. create a hashMap with double capacity
        T = new node*[ 2* N];

        for(int i =0;  i < N; i++){
            T[i] = NULL;
        }

        N = 2* N;
        M = 0;

        // 3. transfer (k,v) pairs from old hashMap to the updated hashMap
        for(int i =0; i < oldN; i++){
            // transfer the LL at the ith index of oldT
            transfer(oldT[i]);
        }

        // 4. release the memory allocated to the old hashMap
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
        // 1. transform the key into hash index using the hash function
        int hashIdx = hashFn(K);

        // 2. create a node with given (k,v) pair and insert it at head of LL stored at the hash index
        node* n = new node(K,V);

        // 3. update the pointer to the head of the LL stored at the hash index such that it holds 
        //  address of the newly created node
         n ->next = T[hashIdx];
         T[hashIdx] = n;
         M++;


        // 4. rehash, if loadFactor exceeds the loadFactor threshold
        double LF = M * 1.0 /N;
        
        if(LF > L){
            cout << "rehashing due to LF" << LF << endl;
            rehash();
        }
    }

    node* find(int K){
        //1. transform the key into hash index using hash function
        
        // 2.search for the node for the given  key in the LL stored at hash index
        
        return NULL;
    }
    
    void erase(int K){
        //1. transform the key into hash index using hash function

        //2. delete the node with the given key in the  LL stored at hash index;

    }

    void printLinkedList(node* head){
        while(head){  //head != NULL
            cout << "{" << head->K << ", "<< head->V << "}" ;
        }
        cout << endl;
    }

    void printHashMap(){
        // Iterate over buckets in the hashmap
        for(int i = 0; i< N; i++){
            // print the LL stored at ith bucket of hashmap
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


    return 0;
}