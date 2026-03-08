*This project has been created as part of the 42 curriculum by hchartie*
# SO_LONG

## Description

SO_LONG is a 2D tile-based graphical 42 project developed in C using the MinilibX graphics library. The objective is to navigate a map, collect all coins, and reach the exit. The game validates that maps are properly formatted and solvable using a flood-fill algorithm.

### Map Format
Maps are text-based files with `.ber` extension using the following symbols:
- `1` = Wall (solid obstacle)
- `0` = Floor (walkable space)
- `P` = Player starting position (exactly 1 required)
- `E` = Exit target (exactly 1 required)
- `C` = Collectible/Coin (at least 1 required)

Maps must be rectangular and contain only one exit and one player and at least one collectible.

## Instructions

### Build
```bash
make              # Compile the project
make clean        # Remove object files
make fclean       # Remove all compiled files
make re           # Clean rebuild
make norm         # Check The NORM
```

### Run
```bash
./so_long maps/map1.ber
```

Replace `map1.ber` with any valid map file from the `maps/` directory.

### Controls
- **Arrow Keys** or **WASD**: Move the player
- **ESC**: Exit the game

### Map Validation
The game automatically validates maps and checks:
- ✓ Map is surrounded by walls
- ✓ Exactly one player position
- ✓ Exactly one exit
- ✓ At least one collectible
- ✓ All collectibles and exit are reachable (using flood-fill algorithm)

## Resources
Flood fill : \
https://fr.wikipedia.org/wiki/Algorithme_de_remplissage_par_diffusion

## IA Usage 
IA was use for debug and the structure of the README