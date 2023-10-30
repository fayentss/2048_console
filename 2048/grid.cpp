#include "grid.h"
#include "tile.h"
#include <iostream>
#include <vector>

Grid::Grid(int i_length)
{
	Grid::i_length = i_length;
	v_Tiles.resize(i_length * i_length);

	for (int i = 0; i < i_length * i_length; i++)
	{
		v_Tiles[i] = new Tile();
	}

};

void Grid::SpawnTile()
{
	v_EmptyTiles.clear();

	for (int i = 0; i < i_length * i_length; i++)
	{
		if (v_Tiles[i]->value == 0)
		{
			v_EmptyTiles.push_back(i);
		}
	}

	int i_RandomNb = rand() % v_EmptyTiles.size();

	int i_RandomValue = rand() % 4 + 1;

	if (i_RandomValue == 1 || i_RandomValue == 2 || i_RandomValue == 3)
	{
		v_Tiles[v_EmptyTiles[i_RandomNb]]->value = 2;
	}
	else
	{
		v_Tiles[v_EmptyTiles[i_RandomNb]]->value = 4;
	}



}

int Grid::Get1DCoordFrom2D(int i, int j)
{
	int n = (i * i_length) + j;
	return n;
}

bool Grid::IsInGrid(int i, int j)
{
	if (i >= 0 && i < i_length && j >= 0 && j < i_length)
		return true;
	else
		return false;
}



void Grid::Translation_Left()
{
	//Fusion
	for (int i = 0; i < i_length; i++)
	{
		for (int j = 0; j < i_length; j++)
		{
			if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == 0)
				continue;

			for (int k = 1; k < i_length - j; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i, j + k)]->value == v_Tiles[Get1DCoordFrom2D(i, j)]->value)
				{
					v_Tiles[Get1DCoordFrom2D(i, j)]->value += v_Tiles[Get1DCoordFrom2D(i, j + k)]->value;
					v_Tiles[Get1DCoordFrom2D(i, j + k)]->value = 0;
					break;

				}
				else if (v_Tiles[Get1DCoordFrom2D(i, j + k)]->value != 0)
				{
					break;
				}
			}

		}
	}

	//Translation
	for (int i = 0; i < i_length; i++)
	{
		for (int j = 0; j < i_length; j++)
		{
			if ((v_Tiles[Get1DCoordFrom2D(i, j)]->value != 0))
				continue;

			int i_TileToSwap = -1;

			for (int k = 1; k < i_length - j; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i, j + k)]->value != 0)
				{
					i_TileToSwap = Get1DCoordFrom2D(i, j + k);
					break;
				}
			}

			if (i_TileToSwap == -1)
				continue;

			Tile* tmp = v_Tiles[Get1DCoordFrom2D(i, j)];

			v_Tiles[Get1DCoordFrom2D(i, j)] = v_Tiles[i_TileToSwap];

			v_Tiles[i_TileToSwap] = tmp;
		}
	}
}

void Grid::Translation_Right()
{
	//Fusion
	for (int i = 0; i < i_length; i++)
	{
		for (int j = i_length - 1; j >= 0; --j)
		{
			if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == 0)
				continue;

			for (int k = 1; k <= j; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i, j - k)]->value == v_Tiles[Get1DCoordFrom2D(i, j)]->value)
				{
					v_Tiles[Get1DCoordFrom2D(i, j)]->value += v_Tiles[Get1DCoordFrom2D(i, j - k)]->value;
					v_Tiles[Get1DCoordFrom2D(i, j - k)]->value = 0;
					break;

				}
				else if (v_Tiles[Get1DCoordFrom2D(i, j - k)]->value != 0)
				{
					break;
				}
			}

		}
	}

	//Translation
	for (int i = 0; i < i_length; i++)
	{
		for (int j = i_length - 1; j >= 0; --j)
		{
			if ((v_Tiles[Get1DCoordFrom2D(i, j)]->value != 0))
				continue;

			int i_TileToSwap = -1;

			for (int k = 1; k <= j; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i, j - k)]->value != 0)
				{

					i_TileToSwap = Get1DCoordFrom2D(i, j - k);
					break;
				}
			}

			if (i_TileToSwap == -1)
				continue;

			Tile* tmp = v_Tiles[Get1DCoordFrom2D(i, j)];

			v_Tiles[Get1DCoordFrom2D(i, j)] = v_Tiles[i_TileToSwap];

			v_Tiles[i_TileToSwap] = tmp;
		}
	}
}

void Grid::Translation_Up()
{
	//Fusion
	for (int j = 0; j < i_length; j++)
	{
		for (int i = 0; i < i_length; i++)
		{
			if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == 0)
				continue;

			for (int k = 1; k < i_length - i; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i + k, j)]->value == v_Tiles[Get1DCoordFrom2D(i, j)]->value)
				{
					v_Tiles[Get1DCoordFrom2D(i, j)]->value += v_Tiles[Get1DCoordFrom2D(i + k, j)]->value;
					v_Tiles[Get1DCoordFrom2D(i + k, j)]->value = 0;
					break;

				}
				else if (v_Tiles[Get1DCoordFrom2D(i + k, j)]->value != 0)
				{
					break;
				}
			}

		}
	}

	//Translation
	for (int j = 0; j < i_length; j++)
	{
		for (int i = 0; i < i_length; i++)
		{
			if ((v_Tiles[Get1DCoordFrom2D(i, j)]->value != 0))
				continue;

			int i_TileToSwap = -1;

			for (int k = 1; k < i_length - i; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i + k, j)]->value != 0)
				{
					i_TileToSwap = Get1DCoordFrom2D(i + k, j);
					break;
				}
			}

			if (i_TileToSwap == -1)
				continue;

			Tile* tmp = v_Tiles[Get1DCoordFrom2D(i, j)];

			v_Tiles[Get1DCoordFrom2D(i, j)] = v_Tiles[i_TileToSwap];

			v_Tiles[i_TileToSwap] = tmp;
		}
	}
}

void Grid::Translation_Down()
{
	//Fusion
	for (int j = 0; j < i_length; j++)
	{
		for (int i = i_length - 1; i >= 0; --i)
		{
			if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == 0)
				continue;

			for (int k = 1; k <= i; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i - k, j)]->value == v_Tiles[Get1DCoordFrom2D(i, j)]->value)
				{
					v_Tiles[Get1DCoordFrom2D(i, j)]->value += v_Tiles[Get1DCoordFrom2D(i - k, j)]->value;
					v_Tiles[Get1DCoordFrom2D(i - k, j)]->value = 0;
					break;

				}
				else if (v_Tiles[Get1DCoordFrom2D(i - k, j)]->value != 0)
				{
					break;
				}
			}

		}
	}

	//Translation
	for (int j = 0; j < i_length; j++)
	{
		for (int i = i_length - 1; i >= 0; --i)
		{
			if ((v_Tiles[Get1DCoordFrom2D(i, j)]->value != 0))
				continue;

			int i_TileToSwap = -1;

			for (int k = 1; k <= i; k++)
			{
				if (v_Tiles[Get1DCoordFrom2D(i - k, j)]->value != 0)
				{

					i_TileToSwap = Get1DCoordFrom2D(i - k, j);
					break;
				}
			}

			if (i_TileToSwap == -1)
				continue;

			Tile* tmp = v_Tiles[Get1DCoordFrom2D(i, j)];

			v_Tiles[Get1DCoordFrom2D(i, j)] = v_Tiles[i_TileToSwap];

			v_Tiles[i_TileToSwap] = tmp;
		}
	}
}

bool Grid::LoseCheck()
{
	for (int i = 0; i < i_length; i++)
	{
		for (int j = 0; j < i_length; j++)
		{
			if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == 0)
				return false;



			else if (IsInGrid(i, j + 1) == true)
				if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == v_Tiles[Get1DCoordFrom2D(i, j + 1)]->value)
					return false;

			else if (IsInGrid(i, j - 1) == true)
				if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == v_Tiles[Get1DCoordFrom2D(i, j - 1)]->value)
					return false;

			else if (IsInGrid(i + 1, j) == true)
				if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == v_Tiles[Get1DCoordFrom2D(i + 1, j)]->value)
					return false;

			else if (IsInGrid(i - 1, j) == true)
				if (v_Tiles[Get1DCoordFrom2D(i, j)]->value == v_Tiles[Get1DCoordFrom2D(i - 1, j)]->value)
					return false;
		}
	}
	return true;

}