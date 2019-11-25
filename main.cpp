// Description : Implementing a generic type using C++'s templating mechanism. Two additional methods, resize(...) and reserve(...) are added. The declarations and denitions of CS52::Vector template are placed in Vector.cxx.


# include <iostream>
# include <string>
# include "VectorT.cxx"

// helper function to display capacity and size in testing
template <class T>
void info ( CS52::Vector <T>&v){
    std::cout<<"Size is:"<<v.size()<<"\n";
    std::cout<<"Capacity is:"<<v.capacity()<<"\n";
    std::cout<<"Contents:";
    for (int i=0; i < v.size(); i++){
        std::cout<<v[i]<<" ";
    }
    std::cout<<"\n";
}

int main(){ //driver code is given to test
    //
    // testing double , bool , std :: string , and CS52 :: Vector <int > instantiations
    //
    CS52::Vector <double> dVector (5, -1.0);
    std::cout<< "CS52::Vector <double> dVector(5,-1);\n";
    info(dVector);
    CS52::Vector <bool > booVector (5, true);
    std::cout<< "\nCS52::Vector <bool> booVector(5,true);\n";
    info(booVector);
    std::cout<< "\nTesting std::string as an element:\n";
    
    CS52::Vector <std::string> strVector;
    strVector.push_back ("this is great");
    strVector.push_back ("I love my CS52::Vector");
    strVector.push_back ("Amazing");
    
    for (int i=0; i<strVector.size(); i++){
        std::cout<<strVector[i]<<"\n";
    }
    
    std::cout<< "\nTesting a 2D vector (matrix)\n";
    CS52::Vector <CS52::Vector<int> > vecOfIntVecs;
    int cols=3; int rows=5;
    for (int i=0; i<rows; i++){
        CS52::Vector<int> v(cols,i);
        vecOfIntVecs.push_back(v);
    }
    for (int i=0; i<vecOfIntVecs.size(); i++){
        CS52::Vector <int> v=vecOfIntVecs[i];
        for (int j=0; j<v.size(); j++){
            std::cout<<v[j]<<" ";
        }
        std::cout<<"\n";
    }
    //
    // Testing Resize and Reserve
    //
    CS52::Vector <int> iVector(3,8);
    std::cout<< "\nCS52::Vector <int> iVector(3,8);\n";
    info (iVector);
    std::cout<< "\nResize Testing\n";
    iVector.resize(10,-1.0);
    std::cout<< "iVector.resize(10,-1);\n";
    info (iVector);
    iVector.resize(5,0);
    std::cout<< "\niVector.resize(5,0);\n";
    info (iVector);
    iVector.reserve(15);
    std::cout<< "\niVector.reserve(15);\n";
    info (iVector);
    iVector.reserve(1);
    std::cout<< "\niVector.reserve(1);\n";
    info (iVector);
    
    return 0;
}

