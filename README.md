# ga-ga3-unit-testing
The following are instructions on getting a unit test environment up and run commands 
# Installing pre-requisites for setup 
1. Install Make
2. Run command "Choco install make"
3. Install GCC/g++
   Link :  https://jmeubank.github.io/tdm-gcc/download/
   Set environment variable
4. Install Cmake
   Link :  https://cmake.org/install/
   Set environment variable
5. pip install gcovr
6. Add path in environment variable
7. gcovr --version
   Link: https://sourceforge.net/projects/mingw/

# Building
Once all requirements and setup are complete, execute the follwoing to build and run the unit tests:
Windows : cmake -S GoogleTestPseudo -B GoogleTestPseudo\build -G "MinGW Makefiles"




