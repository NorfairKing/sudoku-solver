## Sudoku
A minimal sudoku solver.
The solver doesn't solve sudokus in polynomial time with respect to the board size.
Sadly I did not prove P=NP with a sudoku solver.
It solves a board with a given block size, say 3, in constant time and space.

### Input
Input is minimal, numbers seperated by spaces, one row per line.
See `data` for examples.

### Ambiguous boards
The solver can also solve ambiguous boards. Try this out as an example:
```
$ ./sudoku.bin < data/empty.sudoku
```
Because the solver is deterministic, this will always give the same board.

### Other sizes
The solver can handle different board sizes but you'll have to recompile it with the changed constant in `constants.h`.
