#pragma once
#include "FilePrinter.h"
#include <bitset>

class FilePrinterBinary : public FilePrinter{
public:
    void Display (const char *path) const override;
};