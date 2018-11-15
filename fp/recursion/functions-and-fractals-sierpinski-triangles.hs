import Data.List

oneOrUnderscore :: Char -> Char -> Char
oneOrUnderscore c1 c2
    | c1 == '1' && c2 == '1' = '_'
    | otherwise = c2

reflectLine :: [Char] -> [Char] -> [Char]
reflectLine l1 l2 = zipWith oneOrUnderscore l1 l2

sierpinskify :: [[Char]] -> Int -> [[Char]]
sierpinskify triangle 0 = triangle
sierpinskify triangle n = 
    let lower = sierpinskify (map (\i -> reflectLine (triangle !! (rd2 - i)) (triangle !! (rd2 + i - 1))) [1..rd2]) (n-1)
        upper = sierpinskify (take rd2 triangle) (n-1)
    in upper ++ lower
    where rd2 = length triangle `div` 2

row :: Int -> Int-> [Char]
row x y = replicate (x - y) '_' ++ replicate (2 * y + 1) '1' ++ replicate (x - y) '_'

main :: IO ()
main = do
    n <- readLn :: IO Int
    let rows = 32 
        triangle = map (\x -> row (rows-1) x) [0..(rows-1)]
    putStrLn $ intercalate "\n" $ sierpinskify triangle n
