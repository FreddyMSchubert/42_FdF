# FdF
(FDF is short for ’fil de fer’ in French which means ’wireframe model’.)

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/fdfe.png" alt="Push_swap 42 project badge"/><br>
</p>

> This project was created in compliance with the 42 norm, which means no ternary operators, no switches, no for loops, no in function comments, ... -> https://github.com/FreddyMSchubert/42_cursus/blob/main/en.norm.pdf

![42 gif](https://github.com/FreddyMSchubert/42_FdF/blob/master/etc/readme_assets/pylone.png)

## Subject

Given a heightmap input that looks something like this:

```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

Draw a 3d wireframe model by only drawing the edges between a variety of points. The model must be represented in isometric projection.
To do the bonus and get over 100 points, you should add:
- one extra projection
- a zoom
- model translation
- model rotations
- some more bonus features of your choice.

Allowed external functions:
- open, close, read, write, malloc, free, perror, strerror, exit, all math lib functions

Putting all of that together, you get something like this:

![42 gif](https://github.com/FreddyMSchubert/42_FdF/blob/master/etc/readme_assets/42.gif?raw=true)

## Usage
1. Clone the repo
2. To run it, you can do the following:
```C
make fcomp                    // compile project
./fdf ./test_maps/42.fdf      // run one of the test maps. there's a bunch of them in the test_maps folder
```
3. Controls:

| Key Combination           | Action                                 |
|---------------------------|----------------------------------------|
| Scroll                    | Zoom                                   |
| Hold Arrow Keys + Scroll  | Change Translation                     |
| Hold P + Scroll           | Change Pitch                           |
| Hold Y + Scroll           | Change Yaw                             |
| Hold R + Scroll           | Change Roll                            |
| Shift + P                 | Toggle Pitch Rotate Mode               |
| Shift + Y                 | Toggle Yaw Rotate Mode                 |
| Shift + R                 | Toggle Roll Rotate Mode                |
| i                         | Switch Projection                      |
| s                         | Status Log                             |
| esc                       | Close Window                           |
| enter                     | Reset settings                         |

## Approach

1. Get all the data and convert it to something usable. For this, I created a node struct.
2. Loop through each of the nodes and draw a line from the current to the next top node and next right node if those aren't outside of the grid.
     1. Calculate their pixel positions using the isometric formula
     2. Use [Bresenhams Algo](https://de.wikipedia.org/wiki/Bresenham-Algorithmus) to draw a line between the two pixels.
     3. If there are colors, generate a gradient and save the colors in the struct for the pixels.
     4. Draw the line, just loop through all the pixel structs
3. redo 2 for each screen refresh. save a bunch of info (rotations, held keys, ...) in a settings struct. (that struct turned into the largest struct I ever created.)

> To be clear: Isometric projection has clearly defined angles. When rotating, those are of course no longer considered. So technically, the model is only shown in true isometric projection before any rotations are applied.

#### For the bonus, I added
- [Cabinet projection](https://en.wikipedia.org/wiki/3D_projection#/media/File:Comparison_of_graphical_projections.svg)
- Modular terrain height
- A very funky auto rotation mode
- And of course, all the other mandated features

![t2 gif](https://github.com/FreddyMSchubert/42_FdF/blob/master/etc/readme_assets/t2.gif?raw=true)

---

Made by Frederick Schubert: fschuber@student.42heilbronn.de | http://frederickschubert.de
