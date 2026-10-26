#include "pch.h"
#include "CppUnitTest.h"
#include "../caligurlsKnedTheBread/shift.h"
#include "../caligurlsKnedTheBread/shiftConfig.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KnedAutomatedTesting
{
	TEST_CLASS(KnedAutomatedTesting)
	{
	public:
		
		TEST_METHOD(Intro)
		{
			Logger::WriteMessage("Hello from Kned's Automated Testing!");
		}

		TEST_METHOD(ShiftInitialization)
		{
			Shift shift;
			shift.startShift(1);
			Assert::AreEqual(1, shift.getShiftNumber());
			Assert::AreEqual(3, shift.getCustomersLeft());
			Assert::AreEqual(0.0, shift.getTotalRating());
		}
	};
}
