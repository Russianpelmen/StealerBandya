#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class DiskInfo
{
public:

    void WriteDiskInfo(string name)
    {

        wofstream DiskInfo(name + " - Disk" + ".log");

        while (driveLetter <= 'Z')
        {
            drivePath[0] = driveLetter;
            drivePath[1] = ':';
            drivePath[2] = '\\';
            drivePath[3] = '\0';

            driveType = GetDriveTypeA(drivePath);

            if (driveType != DRIVE_NO_ROOT_DIR) {
                if (GetDiskFreeSpaceExA(drivePath, NULL, &totalBytes, &freeBytes)) {
                    if (GetVolumeInformationA(drivePath, volumeName, MAX_PATH + 1, NULL, NULL, &fileSystemFlags, fileSystemName, MAX_PATH + 1)) {
                        if (GetDiskFreeSpaceA(drivePath, &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters)) {
                            DiskInfo << "Disk " << driveLetter << ":\n";
                            DiskInfo << "Disk Type: ";

                            switch (driveType) {
                            case DRIVE_REMOVABLE: DiskInfo << "Removable\n"; break;
                            case DRIVE_FIXED:     DiskInfo << "Local\n";     break;
                            case DRIVE_REMOTE:    DiskInfo << "Network\n";   break;
                            case DRIVE_CDROM:     DiskInfo << "CD/DVD\n";    break;
                            case DRIVE_RAMDISK:   DiskInfo << "RAM-disk\n";  break;
                            default:              DiskInfo << "Unknown\n";   break;
                            }

                            DiskInfo << "Total volume: " << totalBytes.QuadPart << " Byte\n";
                            DiskInfo << "Free space: " << freeBytes.QuadPart << " Byte\n";
                            DiskInfo << "Ocupied space: " << totalBytes.QuadPart - freeBytes.QuadPart << " Byte\n";
                            DiskInfo << "Volume Name: " << volumeName << "\n";
                            DiskInfo << "File system: " << fileSystemName << "\n";
                            DiskInfo << "Number bytes per sector: " << bytesPerSector << "\n";
                            DiskInfo << "Number sectors in cluster: " << sectorsPerCluster << "\n\n";
                        }
                    }
                }
            }
            driveLetter++;
        }

        DiskInfo.close();

    }

private:

    char driveLetter = 'A';
    char drivePath[4];
    DWORD driveType;
    ULARGE_INTEGER totalBytes;
    ULARGE_INTEGER freeBytes;
    char volumeName[MAX_PATH + 1];
    DWORD fileSystemFlags;
    char fileSystemName[MAX_PATH + 1];
    DWORD sectorsPerCluster;
    DWORD bytesPerSector;
    DWORD numberOfFreeClusters;
    DWORD totalNumberOfClusters;

};