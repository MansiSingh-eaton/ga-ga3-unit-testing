#ifndef MANSI
#define MANSI
#include <gmock/gmock.h>
#include <stdexcept>

class SourceB_MOCK {
public:
    MOCK_METHOD(int, doubleValueB, (int));
};

class SourceB {
public:
    SourceB() {}
    static void SetMock(SourceB_MOCK* _mock) {
        mock = _mock;
    }

    //static int doubleValueB(int x) {
     //   return mock->doubleValueB(x);
   // }


   static int doubleValueB(int x) {
        if (mock == nullptr) {
            throw std::runtime_error("Mock object not set");
        }
        return mock->doubleValueB(x);
   }

private:
    static SourceB_MOCK* mock;
};

#endif