count :: String -> Int
count [x] = 1
count (x:y:xs) 
    | x == y = 1 + count (y:xs)
    | otherwise = 1


compress :: String -> String
compress [] = []
compress (x:xs) 
    | c == 1 = x : (compress $ drop c (x:xs))
    | otherwise = (x:(show c)) ++ (compress $ drop c (x:xs))
    where c = count (x:xs)


main :: IO () 
main = do
    ans <- fmap compress getLine
    putStrLn ans
