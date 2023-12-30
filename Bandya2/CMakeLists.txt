add_executable (Bandya2.0 "main.cpp" "Bandya.hpp" "Other/PasswordFinder.cpp"  "Other/WebCam.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Bandya2.0 PROPERTY CXX_STANDARD 20)
endif()
