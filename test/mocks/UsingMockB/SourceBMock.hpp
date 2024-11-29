#pragma once
#include <gmock/gmock.h>
#include <SourceA.hpp>

class MockSourceB
{	
public:
    MOCK_METHOD(int, doubleValueB, (int));
};

class SourceB 
{
public:
    SourceB() {
        if (instance == nullptr) {
            instance = new MockSourceB();
        }
    }

    static int doubleValueB(int x) {
        return instance->doubleValueB(x);
    }

    // Control Instance of Mock
    static void SetInstance(MockSourceB* inst) {
        instance = inst;
    }

    static MockSourceB* GetInstance() {
        return instance;
    }

private:
    static MockSourceB* instance;
};

MockSourceB* SourceB::instance = nullptr;

