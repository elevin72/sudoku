# Sudoku

Solves sudoku puzzle. This project was done without looking at anybody elses code.

The latest version solves any puzzle, with no noticable delay

## Complexity

So **an** upper bound is O(9^n) where n is the number of empty squares in the puzzle, but really it's much less. (Most conceivable programs are much less than this). To calculate real run-time, we must find the average (expected value) number of canidates for every given square based on how many squares are already filled in. ie, when you have 0 squares filled in, then every square has 9 canidates that it could be. If you have 80 squares filled in, then that last square has exactly one canidate. And really much before there are 80 filled in squares the average number of canidates is very close to 1. 

### f(n)

f(0) = 9, f(80) = 1.

But even as n approaches 80 it is already very close to 1. For instance if you have 70 squares filled in then the last 10 have exactly 1 canidate.


Domain: [0, 80]
Range: [1, 9] 

Then we could could say T(n) = T(n-1) * f(81 - n) <= T(n-1) * 9

That is to say that we can consider f as a constant... But I guess if we do then we are still at 9^n. So really f(n) is much closer to one than I previously thought. (Otherwise my program would still be running).

How to calculate this...?

