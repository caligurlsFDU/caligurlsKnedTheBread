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


		// verify an ingredient is added to the sandwich
		// first checking the number of ingredients on the sandwich, then checking that the ingredient is present
		TEST_METHOD(IngredientIsAddedToTheSandwich)
		{
			Sandwich s;
			s.addIngredient("turkey");
			Assert::AreEqual((size_t)1, s.getIngredients().size(), L"Wrong number of ingredients on the sandwich");
			Assert::AreEqual(std::string("turkey"), s.getIngredients()[0], L"Ingredient was not added to the sandwich");
		}

		// verify an ingredient cannot be added to the sandwich if it is already present
		// checks that the size of the ingredients vector is still 1 after trying to add the same ingredient twice
		TEST_METHOD(IngredientCannotBeAddedTwice)
		{
			Sandwich s;
			s.addIngredient("ham");
			s.addIngredient("ham");
			Assert::AreEqual((size_t)1, s.getIngredients().size(), L"Ingredient was added twice to the sandwich");
		}

		// verify that ingredients are removed from the sandwich correctly
		// checks that the size of the ingredients vector is 0 after adding and then removing an ingredient to an empty sandwich
		TEST_METHOD(IngredientIsRemovedFromTheSandwich)
		{
			Sandwich s;
			s.addIngredient("american cheese");
			s.removeIngredient("american cheese");
			Assert::AreEqual((size_t)0, s.getIngredients().size(), L"Ingredient was not removed from the sandwich");
		}

		// verify that ingredients cannot be removed from the sandwich if they are not present
		// adds an ingredient to the sandwich, then tries to remove a different ingreidient
		// checks that the size of the ingredients vector is still 1 after trying to remove an ingredient that is not present
		TEST_METHOD(NotPresentIngedientsCannotBeRemoved)
		{
			Sandwich s;
			s.addIngredient("white bread");
			s.removeIngredient("american cheese");
			Assert::AreEqual((size_t)1, s.getIngredients().size(), L"Ingredient was removed from the sandwich even though it was not present");
		}

		//Checks if ingredients added and correct sandwich match
		TEST_METHOD(IngredientsMatchCorrectSandwich)
		{
			Sandwich s;
			s.addIngredient("cheese");
			s.addIngredient("white bread");
			s.addIngredient("ham");
			Assert::IsTrue(s.matchesOrder("cheese, white bread, ham"));
		}

		//Checks if sandwich with extra ingredients does not match correct sandwich
		TEST_METHOD(IngredientsDoNotMatchCorrectSandwich)
		{
			Sandwich s;
			s.addIngredient("cheese");
			s.addIngredient("white bread");
			s.addIngredient("ham");
			s.addIngredient("mayo");
			Assert::IsFalse(s.matchesOrder("cheese, white bread, ham"));
		}

		//Checks if sandwich with missing ingredients does not match correct sandwich
		TEST_METHOD(IngredientsDoNotMatchCorrectSandwich2)
		{
			Sandwich s;
			s.addIngredient("cheese");
			s.addIngredient("white bread");
			Assert::IsFalse(s.matchesOrder("cheese, white bread, ham"));
		}

		//Checks if a sandwich with two correct first ingredients and one incorrect last ingredient returns false for matchesOrder
		TEST_METHOD(WrongIngredientLastReturnsFalse)
		{
			Sandwich s;
			s.addIngredient("White Bread");
			s.addIngredient("Ham");
			s.addIngredient("American Cheese");

			Assert::IsFalse(s.matchesOrder("White Bread, Ham, Mayo"));
		}

		//Checks if sandwich with all correct ingredients is given the correct rating of 5 stars
		TEST_METHOD(AllCorrectIngredientsRating)
		{
			Sandwich s;
			s.addIngredient("cheese");
			s.addIngredient("white bread");
			s.addIngredient("ham");
			double result = s.orderStars({ "cheese", "white bread", "ham" });
			Assert::AreEqual(5.0, result, L"Rating is incorrect");
		}

		//Checks if empty sandwich is given the correct rating of 0 stars
		TEST_METHOD(RatingWithNoIngredients)
		{
			Sandwich s;
			double result = s.orderStars({ "white bread", "turkey", "swiss cheese" });

			Assert::AreEqual(0.0, result, L"Rating is incorrect. An empty sandwich should have a rating of 0 stars.");
		}

		//Checks the rating of a correct sandwich with an extra ingredient. The rating should be 4 stars.
		TEST_METHOD(RatingWithExtraIngredients)
		{
			Sandwich s;
			s.addIngredient("white bread");
			s.addIngredient("turkey");
			s.addIngredient("swiss cheese");
			s.addIngredient("mayo");

			double result = s.orderStars({ "white bread", "turkey", "swiss cheese" });

			Assert::AreEqual(4.0, result, L"Rating is incorrect");
		}

		//Checks the rating for sandwich with no correct ingredients
		TEST_METHOD(RatingWithIncorrectIngredients)
		{
			Sandwich s;
			s.addIngredient("white bread");
			s.addIngredient("turkey");
			s.addIngredient("swiss cheese");

			double result = s.orderStars({ "ham", "american cheese", "mayo" });

			Assert::AreEqual(0.0, result, L"Rating is incorrect");
		}

		//Checks the rating for an empty sandwich with an empty order. The rating should be 5 stars.
		TEST_METHOD(RatingWithEmptySandwichAndEmptyOrder)
		{
			Sandwich s;
			double result = s.orderStars({});
			Assert::AreEqual(5.0, result, L"Rating is incorrect");
		}

		//Checks the rating of a sandwich with one less ingredient than the order. The rating should be 3.5 stars.
		TEST_METHOD(RatingWithTwoCorrectIngredients)
		{
			Sandwich s;
			s.addIngredient("White Bread");
			s.addIngredient("Turkey");

			double result = s.orderStars({ "White Bread", "Turkey", "Mayo" });

			Assert::AreEqual(3.5, result, L"Rating is incorrect");
		}

	};
}
