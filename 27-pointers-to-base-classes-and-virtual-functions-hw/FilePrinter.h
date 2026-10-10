#pragma once
#include <iostream>
#include <fstream>

class FilePrinter {

public:
    virtual void display (const char *path) const;

    virtual ~FilePrinter();
};