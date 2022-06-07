#include <iostream>
using namespace std;

void MissingElements(int A[], int size){//Finding missing Elements in a series of natural numbers
    int diff=A[0]-0;
    for(int i=0; i<size; i++){
        if(diff!=A[i]-i){
            while(diff<A[i]-i){
                cout<<"Missing Element:"<<diff+i<<endl;
                diff++;
            }
        }
    }
}

void MissingElementsHashing(int A[], int size){// Finding missing elements using hash table- faster
        int low=A[0], high=A[0];
        for(int k=1; k<size; k++){
            if(low>A[k])
             low=A[k];
            if(high<A[k])
             high=A[k]; 
        }

        int H[high+1] = {};
        for(int i=0; i<size; i++)
            H[A[i]]++;       //incrementing the value of at the index of value of A by 1(used when list unsorted)
        for(int j=low; j<=high; j++)
            if(H[j]==0)
                cout<<"Missing Element:"<<j<<endl;

}

int main(){
    int size;
    cout<<"Enter size of array:";
    cin>>size;
    int A[size];
    cout<<"Enter the elements of the array in a sorted manner:"<<endl;
    for(int i=0; i<size; i++)
        cin>>A[i];

    MissingElements(A, size);

    cout<<"Enter the elements of the array in an unsorted manner:"<<endl;
    for(int i=0; i<size; i++)
        cin>>A[i];
    MissingElementsHashing(A, size);

}