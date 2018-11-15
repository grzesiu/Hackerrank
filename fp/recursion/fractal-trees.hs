import Data.List 

crownRow :: Int -> Int -> [Char]
crownRow rowNo cols = replicate (sideSpaces + 1) '_' ++ "1" ++ replicate innerSpaces '_' ++ "1" ++ replicate sideSpaces '_' 
    where innerSpaces = 2 * rowNo + 1
          sideSpaces = (cols - innerSpaces - 2) `div` 2


crown :: Int -> Int -> [[Char]]
crown rows cols = map (\rowNo -> crownRow rowNo cols) [rows, rows - 1 ..0]


trunk :: Int -> Int -> [[Char]]
trunk rows cols = replicate rows (replicate spaces '_' ++ "1" ++ replicate (spaces - 1) '_')
    where spaces = cols `div` 2


fractalTree :: Int -> Int -> [[Char]]
fractalTree rows cols = crown (rows `div` 4) cols ++ trunk (rows `div` 4) cols


main :: IO ()
main = do
    n <- readLn :: IO Int
    putStrLn $ intercalate "\n" $ fractalTree 63 100
