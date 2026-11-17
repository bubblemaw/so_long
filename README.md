*This project has been created as part of the 42 curriculum by masase.*

# so_long

## Description

`so_long` is a small 2D game built in C with the **MiniLibX** graphical library. The player collects every collectible on the map and then reaches the exit, using as few moves as possible. The project covers window management, events, textures/sprites, and map parsing and validation.

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./so_long maps/map.ber
```

### Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `S` / `↓` | Move down |
| `A` / `←` | Move left |
| `D` / `→` | Move right |
| `ESC` or window close | Quit cleanly |

The number of moves is displayed in the terminal (and/or on screen).

### Map format (`.ber`)

| Char | Meaning |
|------|---------|
| `0` | Empty space |
| `1` | Wall |
| `C` | Collectible |
| `E` | Exit |
| `P` | Player start position |

Map rules:

- Rectangular, closed by walls
- Exactly 1 `E`, 1 `P`, and at least 1 `C`
- A valid path must exist from `P` to every `C` and to `E` (checked with flood fill)
- On any invalid map, the program prints `Error` followed by an explicit message

Example:

```
1111111
1P0C0E1
1011101
1C00001
1111111
```

## Resources

- MiniLibX documentation
- Flood fill algorithm
