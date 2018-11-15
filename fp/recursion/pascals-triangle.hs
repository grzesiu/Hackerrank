pr :: [Int] -> [Int]
pr [x] = []
pr (x:y:xs) = (x + y) : (pr (y:xs))

pt :: Int -> [[Int]]
pt 1 = [[1]]
pt 2 = (pt 1) ++ [[1, 1]]
pt x = (pt $ (x-1)) ++ [1 : (pr $ last $ pt $ (x-1)) ++ [1]]

main :: IO()
main = do
    n <- getLine
    putStr $ unlines $ map (unwords . map show) $ pt . (read :: String -> Int) $ n
