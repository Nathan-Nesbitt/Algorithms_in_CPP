#ifndef ERRORS_H
#define ERRORS_H


#include <iostream>

// Error classes for indexing //
struct OutOfBounds : public std::exception
{
    // Out of bounds error //
    std::string error;
    // Constructor to create with string //
    OutOfBounds(std::string s) : error(s) {}
    // Destructor //
    ~OutOfBounds() throw () {}
    // Returns the error //
    const char* get_error() const throw() { 
        return error.c_str(); 
    }
};

#endif