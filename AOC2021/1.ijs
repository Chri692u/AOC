NB. Read inputs
input =: "."1 'm' freads './inputs/1.txt'

NB. Solve part one
partOne =: {{ +/0>2-/\y }}

NB. Solve part two
partTwo =: partOne 3+/\input
