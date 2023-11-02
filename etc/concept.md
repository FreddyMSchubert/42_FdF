First of all, we're gonna need a parsing function to create a two dimensional array where array[x][y] is the height value at that position

then loop through the array. make a function that draws a line between two pixels, and a function that takes the 3d coords and turns them into 2d pixels
second function may be: 
x' = (x - y) * cos(30°)
y' = -z + (x + y) * sin(30°)
during the loop, draw a line to the top and right of each coordinate if there is another point there.