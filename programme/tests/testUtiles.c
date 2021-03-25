#include<stdlib.h>
#include<CUnit/Basic.h>
#include "utile.h"
#include "testUtiles.h"

void test_utile_nbDigit(void)
{
  unsigned int nombre = 1234;
  CU_ASSERT_TRUE(nbDigit(nombre) == 4);
}
void test_utile_prochainNombreDansChaine(void)
{
  char* testString = "abc19de2f3";
  unsigned int result = prochainNombreDansChaine(testString);
  CU_ASSERT_TRUE(result == 19);
}
