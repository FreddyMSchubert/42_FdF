# Changelog Fdf by @fschuber

### v0.3.10 - 11.11.23
- fixed grid end stupidity, could have used NULL all along instead of using an elaborate sentinel value. much easier! program also runs through for all test cases now. success!

### v0.3.9 - 10.11.23
- Various Norminette Improvements. Now flawless
- Removed testing code from conversion.c
- fixed problem in bresenhams algo where all the pixels in one returned array would point to a single pixel by adding a function that allocates a new pixel. moved smaller than to bresen_util to reduce number of functions in a single file.
- It works!

### v0.3.8 - 10.11.23
- Added log function to simplify clear logging of program states. It's colorful, too! + Added basic error statements + removed previous unnecessary print statements
- Updated bresenhams-algo.c to work with mallocated pixels
- Multiplied pixel coords by COORD_SPREAD macro to make things more easily visible.
- added draw_lines function to draw all the lines in the pixelmap.

### v0.3.7 - 10.11.23
- Added "terminator" as sentinel value field to t_hm_node and set it in input manager to make looping easy going forward.
- successful conversion of input text to nodes to pixels. color values get turned into right format and coordinates get turned into correct pixels to create 3d effect. line drawing time!

### v0.3.6
- Reordering. drawing util now entirely for gradients, window management now in fdf.c, main file
- Started with the main loop of the program, stopped.

### v0.3.5
- Added draw_line function which draws line with gradient between two points using Bresenhams Algorithm.
- In other words, it works. The difficult part is done. (i think / hope)

### v0.3.4
- Handled 0 division in get_color_gradient_step
- Fixed checksum issues in bresenhams algo, now functional

### v0.3.3
- Added get_gradient function to get gradient between two colors
- Implemented Bresenhams Algo, but there are occasional checksums.

### v0.3.2
- Started bresenhams-algo.c implementation

### v0.3.1
- Continued with draw_manager logic
- changed all function names to start with fdf_ for ease of use
- got bresenhams logic

### v0.3.0
- Imported MLX42 lib and turned all imports into submodules.
- tested input_manager.c, fully functional
- started work on draw_manager.c

### v0.1.0
- Added printf, get_next_line, libft and the test maps
- created header & makefile
- defined node typedef
- created untested inputmanager.c which is supposed to turn the input coordinates into an easily usable 3d array
