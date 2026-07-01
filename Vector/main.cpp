#include <iostream>
#include <string>
#include "Vector.h"

int main() {
    std::cout << "--- Testing Integer Vector ---" << std::endl;
    Vector<int> myVec;

    myVec.Push_Back(10);
    myVec.Push_Back(20);
    myVec.Push_Back(30);
    myVec.Push_Back(40);
    myVec.Push_Back(50);
    std::cout << "After Push_Back: ";
    myVec.Print();

    myVec.Insert(2, 25);
    std::cout << "After Insert 25 at index 2: ";
    myVec.Print();

    myVec.erase(2);
    std::cout << "After erase at index 2: ";
    myVec.Print();

    myVec.pop_back();
    std::cout << "After pop_back: ";
    myVec.Print();

    myVec.left_rotate();
    std::cout << "After left_rotate: ";
    myVec.Print();

    std::cout << "Finding 40 (Transposition): Index " << myVec.find_transposition(40) << std::endl;
    std::cout << "Vector after finding 40: ";
    myVec.Print();

    std::cout << "\n--- Testing String Vector ---" << std::endl;
    Vector<std::string> strVec;
    strVec.Push_Back("Data");
    strVec.Push_Back("Structures");
    strVec.Push_Back("Course");
    
    std::cout << "String Vector: ";
    strVec.Print();
    
    std::cout << "Front element: " << strVec.Front() << std::endl;
    std::cout << "Back element: " << strVec.Back() << std::endl;

    return 0;
}