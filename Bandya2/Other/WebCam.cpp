#include <iostream>
#include <fstream>

#define WebCamInfo Name + " - WebCamInfo.log"

using namespace std;

class WebCamera
{
public:

	void WriteCameraInfo(string Name)
	{
		ofstream CameraInfoFile(WebCamInfo);

		CameraInfoFile << "Camera enable: " << CameraEnable() << endl;

		CameraInfoFile << "Camera name: " << CameraName() << endl;

		CameraInfoFile.close();
	}

private:

	string CameraName()
	{
		return "123";
	}
	
	string CameraEnable()
	{
		bool Enable = false;

		return Enable ? "True" : "False";
	}
};