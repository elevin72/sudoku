# Sudoku

Solves sudoku puzzle. This project was done 100% independently, without looking at any other code.

The latest version solves any puzzle, but with a decent delay for harder puzzles (5-7 seconds). There are definitely ways to get this delay much smaller.

## Complexity

So **an** upper bound is O(9^n) where n is the number of empty squares in the puzzle, but really it's much less. (Most conceivable programs are much less than this). To calculate real run-time, we must find the average (expected value) number of canidates for every given square based on how many squares are already filled in. ie, when you have 0 squares filled in, then every square has 9 canidates that it could be. If you have 80 squares filled in, then that last square has exactly one canidate. And really much before there are 80 filled in squares the average number of canidates is very close to 1. 

### f(n)

f(0) = 9, f(80) = 1.

Domain: [0, 80]
Range: [1, 9] 

Then we could could say T(n) = T(n-1) * f(81 - n) >= T(n-1) * 9

How to calculate this...?
