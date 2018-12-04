powerSum :: Int -> Int -> Int -> Int
powerSum x n r
    | r ^ n < x = (powerSum x n (r + 1)) + (powerSum (x - r ^ n) n (r + 1))
    | r ^ n == x = 1
    | otherwise = 0

main :: IO()
main = do
    x <- readLn :: IO Int
    n <- readLn :: IO Int
    print $ powerSum x n 1

