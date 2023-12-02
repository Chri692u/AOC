module One where
import Data.Char
import Data.List

getInput :: IO [String]
getInput = do
        content <- readFile "./inputs/1.txt"
        return (lines content)

solve :: [String] -> Int
solve xs = sum $ map (read . adjust) strs :: Int
        where
                strs = map (filter isDigit) xs
                adjust s = case length s of
                        1 -> s ++ s
                        _ -> head s : [last s]

main = do
        xs <- getInput
        print $ solve xs