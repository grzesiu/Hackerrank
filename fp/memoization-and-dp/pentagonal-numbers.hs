
main :: IO () 
main = do
    t <- readLn :: IO Int
    ns <- sequence $ replicate t $ getLine
    mapM_ print $ map ((\x -> (x - 1) * (4 + 3 * (x - 2)) `quot` 2 + 2 * x - 1) . (read::String->Int)) ns
