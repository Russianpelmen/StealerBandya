#include <iostream>
#include <string>
#include <Windows.h>

#define Locate Name + " - Locate.log"

class ÑlassLocate
{
public:

    void WriteLocate(std::string Name) {
        std::wofstream LocateInfo(Locate);

        LocateInfo << "Country code:\t" << CountryCode() << std::endl;

        LocateInfo.close();
    }

private:

    wstring CountryCode()
    {
        GEOID myGEO = GetUserGeoID(GEOCLASS_NATION);
        int sizeOfBuffer = GetGeoInfoW(myGEO, GEO_ISO2, NULL, 0, 0);
        WCHAR* buffer = new WCHAR[sizeOfBuffer];
        int result = GetGeoInfoW(myGEO, GEO_ISO2, buffer, sizeOfBuffer, 0);
        std::wcout << buffer;

        std::wstring resultString(buffer);

        return resultString;
    }

};