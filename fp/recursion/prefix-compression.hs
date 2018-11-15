prefix :: String -> String -> Int
prefix x [] = 0
prefix [] y = 0
prefix (x : xs) (y : ys)
    | x == y = 1 + (prefix xs ys)
    | otherwise = 0

main = do  
    xs <- getLine
    ys <- getLine
    let l = prefix xs ys
    putStrLn $ show l ++ " " ++ take l xs
    putStrLn $ show (length xs - l) ++ " " ++ drop l xs
    putStrLn $ show (length ys - l) ++ " " ++ drop l ys
