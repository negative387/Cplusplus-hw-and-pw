#pragma once
#include "FilePrinter.h"
#include <bitset>

class FilePrinterBinary : public FilePrinter{
public:
    void display (const char *path) const override;
};