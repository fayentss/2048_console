#pragma once
#include <vector>
#include "tile.h"

class Grid
{
public:

	int i_length;

	std::vector<Tile*> v_Tiles;

	std::vector<int> v_EmptyTiles;

	Grid(int i_length);

	void SpawnTile();

	int Get1DCoordFrom2D(int i, int j);

	bool IsInGrid(int i, int j);

	void Translation_Left();

	void Translation_Right();

	void Translation_Up();

	void Translation_Down();

	bool LoseCheck();

};