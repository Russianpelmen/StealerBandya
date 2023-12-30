#include <iostream>
#include <Windows.h>
#include <fstream>
#include <Lmcons.h>

#include <string>
#include <locale>
#include <codecvt>

#define Computer Name + " - Computer.log"

using namespace std;

class ComputerInfo
{
public:

    void WriteComputerInfo(string Name) {

        SYSTEM_INFO systemInfo;
        GetNativeSystemInfo(&systemInfo);

        wofstream ComputerInfo(Computer);

        ComputerInfo << "Screen Width:\t|\t" << screenWidth << endl;
        ComputerInfo << "Screen Height:\t|\t" << screenHeight << "\n\n";

        ComputerInfo << "Available RAM:\t|\t" << AvailableRAMMemory() << "\n";
        ComputerInfo << "All RAM:\t|\t" << AllRAMMemory() << "\n\n";

        ComputerInfo << "architecture:\t|\t" << systemInfo.wProcessorArchitecture << ", " << architecture() << "\n";
        ComputerInfo << "prcesosors:\t|\t" << NumberOfPrcesosors() << "\n";
        ComputerInfo << "Processor type:\t|\t" << ProcessorType() << "\n\n";

        ComputerInfo << "Videocard name:\t|\t" << VideoCardName() << "\n\n";

        ComputerInfo << "Username:\t|\t" << ComputerUsername() << "\n\n";

        ComputerInfo.close();
    }

private:

    wstring architecture() {                         // получаем архетиктуру процессора
        SYSTEM_INFO systemInfo;
        GetNativeSystemInfo(&systemInfo);

        switch (systemInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:   return L"x64";     break;
        case PROCESSOR_ARCHITECTURE_ARM:     return L"ARM";     break;
        case PROCESSOR_ARCHITECTURE_ARM64:   return L"ARM64";   break;
        case PROCESSOR_ARCHITECTURE_IA64:    return L"Itanium"; break;
        case PROCESSOR_ARCHITECTURE_INTEL:   return L"x86";     break;
        case PROCESSOR_ARCHITECTURE_UNKNOWN: return L"Another"; break;
        default:                             return L"Another"; break;
        }
    }

    wstring VideoCardName() {                        // получаем имя видеокарты
        DISPLAY_DEVICE displayDevice;
        displayDevice.cb = sizeof(DISPLAY_DEVICE);
        EnumDisplayDevices(NULL, 0, &displayDevice, 0);

        wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
        wstring Device = converter.from_bytes(displayDevice.DeviceString);

        return Device;
    }

    wstring ComputerUsername() {                     // получаем имя пользователя компьютера
        wchar_t username[UNLEN + 1];
        DWORD username_len = UNLEN + 1;

        if (GetUserNameW(username, &username_len)) { return wstring(username); }
    }

    int NumberOfPrcesosors() {                       // получаем количество процессоров
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);

        return sysInfo.dwNumberOfProcessors;
    }

    int ProcessorType() {                            // получаем тип процессора
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);

        return sysInfo.dwProcessorType;
    }

    wstring ComputerName() {                         // получаем сетевое имя компьютера
        wchar_t buffer[256];
        DWORD size = 256;
        GetComputerNameW(buffer, &size);

        return buffer;
    }

    int AvailableRAMMemory() {                       // получаем количество вcей доступной оперативной памяти
        MEMORYSTATUSEX memStatus;
        memStatus.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memStatus);

        return memStatus.ullAvailPhys / (1024 * 1024);
    }

    int AllRAMMemory() {                             // получаем количество вcей оперативной памяти
        MEMORYSTATUSEX memStatus;
        memStatus.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&memStatus);

        return memStatus.ullTotalPhys / (1024 * 1024);
    }

    const int TypeSystem() { if (sizeof(void*) == 8) { return 64; } else { return 32; } } //разрядность ОС

    const int screenWidth = GetSystemMetrics(SM_CXSCREEN);    // высота экрана
    const int screenHeight = GetSystemMetrics(SM_CYSCREEN);    // широта экрана

};
