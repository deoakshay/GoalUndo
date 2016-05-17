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
  gu.addOperation("sqaure","90degrees");
  gu.addOperation("square","vertical line");
  gu.undoOperation();
  gu.undoOperation();
  gu.undoOperation();
  ASSERT_EQ("",gu.getGoal());
  gu.undoOperation();
  ASSERT_EQ("",gu.getGoal());
}

TEST(GoalUndoTest, check_ifAllOperationsReturned)
{
  GoalUndo gu;
  gu.addOperation("sqaure","horizontalline");
  gu.addOperation("sqaure","90degrees");
  gu.addOperation("square","verticalline");
  ASSERT_EQ("horizontalline 90degrees verticalline",gu.getOperations());
}
