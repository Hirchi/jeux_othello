#include<stdlib.h>
#include<string.h>
#include<CUnit/Basic.h>
#include "position.h"
#include "testPosition.h"
#include "plateau.h"


void test_position_abscisse(void)
{
	CU_ASSERT_TRUE(Position_abscisse(Position_creerPosition(2, 4)) == 2);
}
void test_position_ordonnee(void)
{
	CU_ASSERT_TRUE(Position_ordonnee(Position_creerPosition(2, 4)) == 4);
}
void test_position_pEnChaine(void)
{
	CU_ASSERT_TRUE(strcmp(Position_positionEnChaine(Position_creerPosition(5, 4)), "e4")==0);
}
void test_position_pEnChaine_casLimiteDebut(void)
{
	CU_ASSERT_TRUE(strcmp(Position_positionEnChaine(Position_creerPosition(1, 1)), "a1")==0);
}
void test_position_pEnChaine_casLimiteFin(void)
{
	CU_ASSERT_TRUE(strcmp(Position_positionEnChaine(Position_creerPosition(8, 8)), "h8")==0);
}
void test_position_cEnPosition(void)
{
	Position p = Position_chaineEnPosition("e4");
	CU_ASSERT_TRUE(Position_abscisse(p) == 5 && Position_ordonnee(p) == 4);
}
void test_position_cEnPosition_casLimiteDebut(void)
{
	Position p = Position_chaineEnPosition("a1");
	CU_ASSERT_TRUE(Position_abscisse(p) == 1 && Position_ordonnee(p) == 1);
}
void test_position_cEnPosition_casLimiteFin(void)
{
	Position p = Position_chaineEnPosition("h8");
	CU_ASSERT_TRUE(Position_abscisse(p) == 8 && Position_ordonnee(p) == 8);
}
void test_position_pEnPosition(void)
{
	Position pInitiale = Position_creerPosition(6, 3);
	Position pFinale = Position_chaineEnPosition(Position_positionEnChaine(pInitiale));
	CU_ASSERT_TRUE(Position_abscisse(pInitiale) == Position_abscisse(pFinale) && Position_ordonnee(pInitiale) == Position_ordonnee(pFinale));
}


void test_position_positionAdjacente(void)
{ Position pos = Position_creerPosition(5,6);

  CU_ASSERT_TRUE(
		 (Position_abscisse(Position_positionAdjacente(pos,NORD)) == 5) &&
		 (Position_ordonnee(Position_positionAdjacente(pos,NORD)) == 5) &&
		 (Position_abscisse(Position_positionAdjacente(pos,NORD_EST)) == 6) &&
		 (Position_ordonnee(Position_positionAdjacente(pos,NORD_EST)) == 5) &&
		 (Position_abscisse(Position_positionAdjacente(pos,EST)) == 6) &&
		 (Position_ordonnee(Position_positionAdjacente(pos,EST)) == 6) &&
		 (Position_abscisse(Position_positionAdjacente(pos,SUD_EST)) == 6) &&
		 (Position_ordonnee(Position_positionAdjacente(pos,SUD_EST)) == 7) &&
		 (Position_abscisse(Position_positionAdjacente(pos,SUD)) == 5) &&
		 (Position_ordonnee(Position_positionAdjacente(pos,SUD)) == 7) &&
		 (Position_abscisse(Position_positionAdjacente(pos,SUD_OUEST)) == 4) &&
		 (Position_ordonnee(Position_positionAdjacente(pos,SUD_OUEST)) == 7) &&
		 (Position_abscisse(Position_positionAdjacente(pos,OUEST)) == 4) &&
		 (Position_ordonnee(Position_positionAdjacente(pos,OUEST)) == 6) &&
		 (Position_abscisse(Position_positionAdjacente(pos,NORD_OUEST)) == 4) && 
		 (Position_ordonnee(Position_positionAdjacente(pos,NORD_OUEST)) == 5) 
		 );
  
}


void test_position_positionAdjacenteCasLimite(void)
{
   Plateau plateau = Plateau_creePlateau(8,8);
     CU_ASSERT_TRUE(
		    (Position_egales(Position_positionAdjacente(Position_creerPosition(1,1),NORD),Position_creerPosition(1,0))) &&
		     (!Plateau_estDansLePlateau(plateau,Position_positionAdjacente(Position_creerPosition(1,1),NORD))) &&
		     (Position_egales(Position_positionAdjacente(Position_creerPosition(1,1),OUEST),Position_creerPosition(0,1))) &&
		     (!Plateau_estDansLePlateau(plateau,Position_positionAdjacente(Position_creerPosition(1,1),OUEST))) &&
		     (Position_egales(Position_positionAdjacente(Position_creerPosition(8,8),SUD),Position_creerPosition(8,9))) &&
		     (!Plateau_estDansLePlateau(plateau,Position_positionAdjacente(Position_creerPosition(8,8),SUD))) &&
		     (Position_egales(Position_positionAdjacente(Position_creerPosition(8,8),EST),Position_creerPosition(9,8))) &&
		     (!Plateau_estDansLePlateau(plateau,Position_positionAdjacente(Position_creerPosition(8,8),EST)))
		    );
}


void test_position_positionEgales(void)
{
    CU_ASSERT_TRUE(
		 Position_egales(Position_creerPosition(2,3), Position_creerPosition(2,3)) &&
		 !Position_egales(Position_creerPosition(5,6),Position_creerPosition(4,2))
		 );
}
