#pragma once
#include "FilePrinter.h"

class FilePrinterASCII : public FilePrinter{
public:
    void Display (const char *path) const override;
};