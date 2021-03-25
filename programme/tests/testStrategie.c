#include<stdlib.h>
#include<CUnit/Basic.h>
#include "strategie.h"
#include "testStrategie.h"


void test_Strategie_humain(void)
{
  CU_ASSERT_TRUE(Strategie_humain() == HUMAIN);
}

void test_Strategie_IAMinMax(void)
{
  CU_ASSERT_TRUE(Strategie_IAMinMax() == MINMAX);
}

void test_Strategie_IAlphaBeta(void)
{
  CU_ASSERT_TRUE(Strategie_IAAlphaBeta() == ALPHABETA);
}
