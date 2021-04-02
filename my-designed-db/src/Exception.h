#pragma once
#include <iostream>
#include <string>
#include <exception>

using namespace std;

class CatalogError : public exception
{
public:
    CatalogError(string s)
    {
        error = "Catalog wrong: " + s;
    }

    virtual const char *what() const throw()
    {
        return error.c_str();
    }

private:
    string error;
};
