### Bresenhams Algo

int draw_line(coord a, coord b)
1. Calculate stuff
	dx & dy
	fast direction (dx >= dy)
	error (fastdir / 2)
2. mark first pixel
3. while (currfastdircoord < fastdirlength)
	increment fastdircoord
	err = err - slowdirlength;
	if (err < 0)
		currslowdircoord++;
		err = err + fastdirlength;
	set pixel
4. set last pixel


this function expects that a is not above or right of b. if this is the code, switch them before inserting them into function.