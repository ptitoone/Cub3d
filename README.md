# Cub3d

### Simple raycasting program

<p align="center">
  <img src="https://i.imgur.com/8G6G875.png" alt="Program preview" />
</p>

This is a simple raycasting program made with Minilibx graphical library. A map file `.cub` is given as argument, parsed and rendered. Textures and sprites are implemented. 

## Movement

Foward, backward and lateral movement is triggered with `W A S D` keys.
Rotation of feild of view is triggered with `left` and `right` arrow keys.

## Map file structure

#### Textures

The path to the textures and sprite are definied with `NO`, `SO`, `WE`, `EA`, `S`.

```
NO path_to_the_north_texture
SO path_to_the_south_texture
WE path_to_the_west_texture
EA path_to_the_east_texture

S path_to_sprite
```

#### Floor and ceileing colors

Floor and ceiling colors are respectively definied with `F` and `C`, then followed with their RBG value.

```
F 220,100,0
C 225,30,0
```

#### The map

The map walls are represented with `1`, floor with `0`, and sprites with `2`. The map have full enclosing walls.

```
11111111
10000001
10011001
10011001
10000001111
10000000001
10020001111
10000001
11111111
```

## Usage

To build the project for **MacOS** run `make all`. For **linux** run `make alll`. Then lauch `cub3d` or `cub3d_linux` with a `.cub` map file as argument.

It is possible to take a screenshot of the first rendered frame and save it to a `.bmp` file when supplying `--save-bmp` as argument.

## Skills gained

Use an external library and understand simple raycasting mechanisms.

![alt text](https://i.imgur.com/ecwfc8N.png "Final grade 102/100")
