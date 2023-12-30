#include <iostream>
#include <fstream>
#include <windows.h>

#define RunningFile Name + " - RunningFile.log"

using namespace std;

class Running
{
public:

    void RunInfo(string Name)
    {
        CHAR OpenPath[MAX_PATH];
        GetModuleFileNameA(NULL, OpenPath, MAX_PATH);

        ofstream WriteRunInfo(RunningFile);

        WriteRunInfo << "Admin Run:\t" << UserAdmin() << endl;

        WriteRunInfo << "Open path:\t" << OpenPath << endl;

    }

private:

    string UserAdmin() {
        bool isElevated = false;
        HANDLE token;
        TOKEN_ELEVATION elev;
        DWORD size;
        if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token)) {
            if (GetTokenInformation(token, TokenElevation, &elev, sizeof(elev), &size)) { isElevated = elev.TokenIsElevated; }
        }
        if (token) { CloseHandle(token); token = NULL; }

        return isElevated ? "True" : "False";
    }

};
