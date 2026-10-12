
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_5.2/lab_5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            int n;
            double result = S(1, 0.00001, n);
            double expected = exp(1.0);

            Assert::AreEqual(expected, result, 0.00001);
        }
    };
}
