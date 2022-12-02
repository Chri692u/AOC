{-# LANGUAGE OverloadedStrings #-}

import qualified Data.Text as T

solve xs = sum scores
    where scores = map score moves
          moves = map move xs

move x = (enemy, me)
    where me    = T.unpack $ last moves
          enemy = T.unpack $ head moves
          moves = T.splitOn (T.pack " ") (T.pack x)

score ("A", "X") = 3+1
score ("C", "X") = 6+1
score ("A", "Y") = 6+2
score ("B", "Y") = 3+2
score ("B", "Z") = 6+3
score ("C", "Z") = 3+3
score (_, "X") = 1
score (_, "Y") = 2
score (_, "Z") = 3