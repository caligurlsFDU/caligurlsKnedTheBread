#include "pch.h"
#include "CppUnitTest.h"
#include "../caligurlsKnedTheBread/shift.h"
#include "../caligurlsKnedTheBread/shiftConfig.h"
#include "../caligurlsKnedTheBread/sandwich.h"

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
			Assert::AreEqual(1, shift.getShiftNumber(), L"Shift number is incorrect");
			Assert::AreEqual(3, shift.getCustomersLeft(), L"Number of customers left is incorrect");
			Assert::AreEqual(0.0, shift.getTotalRating(), L"Total rating is incorrect");
		}

		TEST_METHOD(RatingWithNoIngredients)
		{
			//Checks the rating for sandwich with no ingredients
			Sandwich s;
			double result = s.orderStars({ "1", "2", "3" });

			Assert::AreEqual(0.0, result, L"Rating is incorrect");
		}

		TEST_METHOD(RatingWithExtraIngredients)
		{
			//Checks the rating for sandwich with an extra ingredient
			Sandwich s;
			s.addIngredient("1");
			s.addIngredient("2");
			s.addIngredient("3");
			s.addIngredient("4");

			double result = s.orderStars({ "1", "2", "3" });

			Assert::AreEqual(4.0, result, L"Rating is incorrect");
		}

		TEST_METHOD(RatingWithIncorrectIngredients)
		{
			//Checks the rating for sandwich with no correct ingredients
			Sandwich s;
			s.addIngredient("1");
			s.addIngredient("2");
			s.addIngredient("3");

			double result = s.orderStars({ "4", "5", "6" });

			Assert::AreEqual(0.0, result, L"Rating is incorrect");
		}
	};
}
