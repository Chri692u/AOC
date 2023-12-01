module One where
import Data.Char

solve :: [[Char]] -> Int
solve xs = sum $ map (read . adjust) strs :: Int
    where
        strs = map (filter isDigit) xs
        adjust s = case length s of
            1 -> s ++ s
            _ -> head s : [last s]

main = do
    let xs = ["1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"]
    print $ solve xs