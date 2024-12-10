# ga-ga3-unit-testing
The following are instructions on getting a unit test environment up and run commands 
# Installing pre-requisites for setup 
1. Install Make
2. Run command "Choco install make"
3. Install GCC/g++
   1. Link :  https://jmeubank.github.io/tdm-gcc/download/
   2. Set environment variable
4. Install Cmake
   1. Link :  https://cmake.org/install/
   2. Set environment variable
5. pip install gcovr
6. Add path in environment variable
7. gcovr --version
   1. Link: https://sourceforge.net/projects/mingw/

# Building
1. Once all requirements and setup are complete, execute the follwoing to build and run the unit tests:
    1. cd C:/GTestPseudo
    2. Windows : cmake -S GoogleTestPseudo -B GoogleTestPseudo\build -G "MinGW Makefiles"
    3. cmake --build GoogleTestPseudo/build --target test_suite
3. To generate code coverage output on command line:
    1. cmake --build GoogleTestPseudo/build --target coverage
4. To generate code coverage html report:
    1. cmake --build GoogleTestPseudo/build --target coverage_report

# Description
Unit testing framework has been added and an example unit test can be found in the following path:
  1. test/UnitTest/src/SourceA/SourceA_Test.cpp








 
