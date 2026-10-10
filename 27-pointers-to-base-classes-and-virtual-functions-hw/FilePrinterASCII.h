#pragma once
#include "FilePrinter.h"

class FilePrinterASCII : public FilePrinter{
public:
    void display (const char *path) const override;
};