mzip :: [Char] -> [Char] -> [Char]
mzip [] _ = []
mzip _ [] = []
mzip (p:ps) (q:qs) = (p:[q]) ++ (mzip ps qs)



main :: IO()
main = do
    p <- getLine
    q <- getLine
    putStrLn $ mzip p q 
