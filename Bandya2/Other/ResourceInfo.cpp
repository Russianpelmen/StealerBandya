#include <iostream>
#include <Windows.h>
#include <fstream>
#include <Lmcons.h>

#include <string>
#include <locale>
#include <codecvt>

#define Resorce Name + " - Resources.log"

using namespace std;

class ResourcesInfo
{
public:

    void WriteResources(string Name) {
        
        wofstream ComputerInfo(Resorce);

        ComputerInfo << "Computer name:\t"  << ComputerName() << "\n" << endl;

        ComputerInfo << "SystemType:\t"     << TypeSystem()   << "\n" << endl;

        ComputerInfo.close();
    }

private:

    wstring ComputerName() {
        wchar_t buffer[256];
        DWORD size = 256;
        GetComputerNameW(buffer, &size);

        return buffer;
    }

    const int TypeSystem() { if (sizeof(void*) == 8) { return 64; } else { return 32; } }

};
