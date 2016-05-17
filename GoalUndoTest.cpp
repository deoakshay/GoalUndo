/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest, check_addGoal_basic)
{
  GoalUndo gu;
  gu.addOperation("football","pitch");
  ASSERT_EQ("football",gu.getGoal());
  ASSERT_EQ("pitch",gu.getOperations());

}

TEST(GoalUndoTest, check_addOperation_basic)
{
  GoalUndo gu;
  gu.addOperation("halves");
  ASSERT_EQ("halves",gu.getGoal());
  ASSERT_EQ("halves",gu.getOperations());
}
TEST(GoalUndoTest, check_stackOperations)
{
  GoalUndo gu;
  gu.addOperation("sqaure","horizontalline");
  gu.addOperation("sqaure","90degrees");
  gu.addOperation("square","vertical line");
  gu.undoOperation();
  ASSERT_EQ("90degrees",gu.getOperations());
  gu.undoOperation();
  ASSERT_EQ("horizontalline",gu.getOperations());

}
TEST(GoalUndoTest, check_emptyStack)
{
  GoalUndo gu;
  ASSERT_EQ("",gu.getOperations());
}

TEST(GoalUndoTest, check_goalPoppedifnoOperations)
{
  GoalUndo gu;
  gu.addOperation("sqaure","horizontalline");
  gu.addOperation("90degrees");
  gu.addOperation("vertical line");
  gu.undoOperation();
  gu.undoOperation();
  gu.undoOperation();
  ASSERT_EQ("",gu.getGoal());
}
TEST(GoalUndoTest, check_ifCorrectOperation_returned)
{
  GoalUndo gu;
	gu.addOperation("painting","theme");
	gu.addOperation("canvas");
	gu.addOperation("colors");
	gu.addOperation("photograph","camera");
	gu.addOperation("lighting");
	gu.addOperation("painting","brush");
	gu.addOperation("water");
	ASSERT_EQ("brush water",gu.getOperations());
}
TEST(GoalUndoTest, check_ifAllOperationsReturned)
{
  GoalUndo gu;
  gu.addOperation("sqaure","horizontalline");
  gu.addOperation("90degrees");
  gu.addOperation("verticalline");
  ASSERT_EQ("horizontalline 90degrees verticalline",gu.getOperations());
}
TEST(GoalUndoTest, check_ifAllOperationsReturned_part2)
{
  GoalUndo gu;
  gu.addOperation("sqaure","horizontalline");
  gu.addOperation("90degrees");
  gu.addOperation("verticalline");
  ASSERT_EQ("horizontalline 90degrees verticalline",gu.getOperations());
	gu.addOperation("house","blueprints");
	gu.addOperation("location");
	ASSERT_EQ("blueprints location",gu.getOperations());
}

TEST(GoalUndoTest, check_emptyUndo)
{
	GoalUndo gu;
	gu.undoGoal();
	ASSERT_EQ("",gu.getOperations());

}
