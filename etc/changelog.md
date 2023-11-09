# Changelog Fdf by @fschuber

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
