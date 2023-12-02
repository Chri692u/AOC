import Text.Parsec
import Text.Parsec.String (Parser)
import Data.Maybe (listToMaybe)
import qualified Data.Text as T
import Text.XHtml (color)

data Color = Blue | Green | Red deriving (Show)

data Game = Game { gameId :: Int, 
                   maxBlue :: Maybe Int,
                   maxGreen :: Maybe Int,
                   maxRed :: Maybe Int
                } deriving (Show)

gameIdParser :: Parser Int
gameIdParser = do
    string "Game "
    id <- many1 digit
    char ':'
    spaces
    return $ read id

colorCounts :: Parser (String, Int)
colorCounts = do
    count <- many1 digit
    space
    color <- string "blue" <|> string "green" <|> string "red"
    optional (char ',' <|> char ';')
    spaces
    return (color, read count)

colorCountParser :: Parser (Maybe Int, Maybe Int, Maybe Int)
colorCountParser = do
    xs <- many1 colorCounts
    let maxBlue = maximumMay [c | ("blue", c) <- xs]
        maxGreen = maximumMay [c | ("green", c) <- xs]
        maxRed = maximumMay [c | ("red", c) <- xs]
    return (maxBlue, maxGreen, maxRed)

maximumMay :: Ord a => [a] -> Maybe a
maximumMay [] = Nothing
maximumMay xs = Just (maximum xs)

gameParser :: Parser Game
gameParser = do
  id <- gameIdParser
  (blue, green, red) <- colorCountParser
  return $ Game id blue green red

gamesParser :: Parser [Game]
gamesParser = many1 gameParser

main :: IO ()
main = do
    input <- readFile "./inputs/2.txt"
    let games =  parse gamesParser "" input
    case games of
        Left err -> print err
        Right games -> do
            -- filter the games that have color values below or equal to the limit
            let bl = Just 14
            let gl = Just 13
            let rl = Just 12
            let filtered_games = filter (\(Game _ b g r) -> b <= bl && g <= gl && r <= rl) games
            -- sum the game ids
            print $ sum $ map gameId filtered_games