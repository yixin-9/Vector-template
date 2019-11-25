//  VectorT.cxx
//  VectorT.cxx contains the CS52::Vector implementation
//

#include <iostream>
#include <exception>
#include <vector>
#include <string>

namespace CS52 {
    template <class T> // T can be any valid identifier
    class Vector{
        public :
        
        Vector <T>(){ //default constructor, initialize the iSize, iCapacity and iData
            iSize=0;
            iCapacity=0;
            iData=nullptr;
        }
        
        // If the vector's size is less than the requested size, newsize elements are added up to newsize.
        // If the vector's size is larger than newsize, the elements closest to the
        // end of the vector are deleted until size == newsize. else, do nothing
        void resize(int newsize, T val=T()){
            if (iSize<newsize) {
                for (int i=iSize; i<newsize; i++) {
                    iData[i]=val;
                }
                iSize=newsize;
                iCapacity= iSize;
            }else if (iSize>newsize){
                iSize=newsize;
            }else ;
        }
        
        // Increase the capacity of the vector to a value that's greater or equal to new_capacity.
        // If new_capacity is greater than the current capacity, new storage is allocated,otherwise do nothing.
        void reserve (int new_capacity){
            if (iCapacity<=new_capacity) {
                iCapacity=new_capacity;
            }
        }
        
        Vector<T>(int s, T iVal){  //overloaded constructor
            
            if (s==0) { //if s equal 0, do nothing
                ;
            }
            else{
                iData=new T[s]; //else allocate new memory
                for (int i=0; i<s; i++) {
                    iData[i]=iVal;
                    iCapacity++;
                }
            }
            iSize=s;
        }
        
        Vector<T>(const T& b){  //copy constructor
            iSize=b.iSize;
            iData= new T[iSize];  //allocate memory
            for (int i=0; i<iSize; i++) {
                iData[i]=b.iData[i];  //assign b to iData
            }
        }
        
        // Destructor
        ~Vector(){
            if (iData!=nullptr) {
                delete [] iData;
                iData=nullptr;
            }
        }
        
        // Get or set element at location i in Vector
        T& at(int i) const throw (std::out_of_range){
            if (i>=iSize) {  //if i greater or equal to iSize, print out-of-bounds and throw
                std::cout<<"out-of-bounds ";
                throw std::out_of_range("at");
            }
            else
                return iData[i];  //else return the vector
        }
        
        // Returns a reference to the last element in the Vector
        T& back() const throw (std::out_of_range){
            try{
                return iData[iSize-1];  //return the last element of the vector
            }
            catch(std::exception e){
                throw e;
            }
        }
        
        // Returns the allocated storage for the Vector .
        int capacity() const{
            return iCapacity;  //return capacity
        }
        
        // Erases the elements of the Vector but does not change capacity .
        void clear(){
            iSize=0; //clear the Vector, size equals to 0
        }
        
        // Returns pointer to the first element in the Vector .
        T* data() const{
            return iData;
        }
        
        // If Vector is empty return true , else false .
        bool empty() const{
            if (iSize==0) {
                return 1;
            }
            else
                return 0;
        }
        
        // Returns a reference to the first element in a vector .
        T& front() const throw (std::out_of_range){
            try{
                return iData[0];
            }
            catch(std::exception e){
                throw e;
            }
        }
        
        // Deletes the element at the end of the vector .
        void pop_back(){
            iSize=iSize-1;
        }
        
        // Add an element to the end of the vector .
        void push_back(T element){
            if (iSize+1>iCapacity) { //if the iSize+1 is greater than the iCapacity
                if (iCapacity==0) {  //if iCapacity=0, assign iCapacity to 1
                    iCapacity=1;
                }
                iCapacity=iCapacity*2;
                
                T *tmp= new T[iCapacity];  //allocate memory
                for (int i=0; i<iSize; i++) { //assign iData to temporary memory
                    tmp[i]=iData[i];
                }
                delete [] iData;  //delete memory
                iData=tmp;  //assign back to iData
            }
            iData[iSize]= element;  //add element to the end of the vector
            iSize++;  //iSize increase 1
        }
        
        // Returns the number of container elements .
        int size() const{
            return iSize;
        }
        
        // Implementing an integer by selection sort
        void sort(){
            for (int i=0; i<iSize-1; i++) {
                int minIndex= i;
                for (int j=i+1; j<iSize; j++) {
                    if (iData[j]<iData[minIndex]) {  //if iData[j] is greater than the previous iData
                        minIndex=j;  //assign j to minIndex
                    }
                }
                //swap to arrange the vector in ascending order
                int temp= iData[minIndex];
                iData[minIndex]=iData[i];
                iData[i]=temp;
            }
        }
        
        // Overloaded operators
        T& operator[] (int i){  // array syntax
            return iData[i];
        }
        Vector<T> & operator =(const Vector<T>& b){  //copy assignment
            if (this == &b){
                return *this;
            }
            delete[] this->iData;  //delete memory
            iSize= b.iSize;
            this->iData = new T[iCapacity];  //allocate new memory
            for(int i=0; i<b.size(); i++){
                this->iData[i] = b.iData[i];
            }
            return *this;
        }
        
        // Overloaded stream insertion operator
        friend std::ostream & operator <<(std::ostream &stream, Vector<T>& iVector){
            for (int i = 0; i<iVector.size(); i++){
                stream << iVector.at(i)<<" ";
            }
            return stream;
        }
        
        private :
        // helper to copy Vector to new Vector
                
        void copy_data(){
            
            T *a=iData;  //store the original data in pointer a
            iData= new T[iCapacity*2];  //allocate memory

            for (int i=0; i<iCapacity; i++) {  //initialize the new memory with pointer a
                iData[i]=a[i];
            }
            iCapacity=iCapacity*2;  //capacity become twice larger
            delete [] a;  //delete a
            
        }
        
        int iSize = 0;
        int iCapacity = 0;
        T * iData = nullptr;
    };

}// namespace
