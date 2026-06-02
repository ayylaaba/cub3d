
<img width="232" height="217" alt="22" src="https://github.com/user-attachments/assets/fdac3d31-f97c-4ae2-8557-f7f069357a8f" />
<img width="1920" height="1100" alt="333" src="https://github.com/user-attachments/assets/9efe4736-ef0f-406e-b212-dd7699f03f89" />



# Cub3D

**Cub3D** is a collaborative project from **42 School** that consists of creating a real-time 3D maze exploration game using the **MiniLibX** graphics library. The project is based on the **raycasting** technique, inspired by the legendary game **Wolfenstein 3D**, widely recognized as one of the first first-person shooter (FPS) games in video game history.

This repository has been archived in the exact state it was in at the time of its final evaluation.

## Project Status

* **Validation Date:** 12/02/2023
* **Final Grade:** 115%

## Repository Setup

Clone the repository together with the MiniLibX submodule:

```bash
git clone --recursive https://github.com/mcombeau/cub3D.git
```

Alternatively:

```bash
git clone https://github.com/mcombeau/cub3D.git
git submodule update --init --recursive
```

## Compilation

Two versions of the project are available:

### Mandatory Version

Compile the mandatory part:

```bash
make
```

### Bonus Version

The bonus implementation includes:

* Wall collision detection
* Minimap display
* Mouse-controlled camera rotation

Compile the bonus version:

```bash
make bonus
```

> Note: You may need to execute `make fclean` before switching between the mandatory and bonus builds.

## Running the Program

Launch the game by providing a `.cub` map file:

```bash
./cub3d <path/to/map.cub>
```

Example:

```bash
./cub3d maps/good/library.cub
```

The program should start normally.

Invalid map example:

```bash
./cub3d maps/bad/filetype_wrong.buc
```

The program should display an error message and terminate.

## Controls

### Movement

* **W** → Move forward
* **S** → Move backward
* **A** → Strafe left
* **D** → Strafe right

### Camera Rotation

* **Left Arrow** → Rotate left
* **Right Arrow** → Rotate right
* **Mouse Movement** → Rotate view (Bonus version only)

## Learning Resources

### MiniLibX

* hsmits MiniLibX Documentation
* gontjarow's MiniLibX Tutorial

### Xlib Events

* The Xlib Manual

### Raycasting

* Lode's Computer Graphics Tutorial – Raycasting
* Permadi's Raycasting Tutorial

### Movement Mathematics

* Calculating Heading in 2D Games Using Trigonometric Functions

## Authors

Developed by **Alex Quesada** and **Mia Combeau**.

## About the Project

Cub3D aims to recreate a Wolfenstein 3D–style experience by rendering a 3D environment from a 2D map using raycasting algorithms. The project introduces fundamental concepts of computer graphics, game rendering, event handling, and mathematical calculations involved in first-person game engines.
