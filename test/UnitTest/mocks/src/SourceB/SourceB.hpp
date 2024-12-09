#include <gmock/gmock.h>

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

    static int doubleValueB(int x) {
        return mock->doubleValueB(x);
    }

private:
    static SourceB_MOCK* mock;
};
