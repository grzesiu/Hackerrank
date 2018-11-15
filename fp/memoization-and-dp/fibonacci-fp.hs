fibs :: Int -> Int -> Int -> Int -> Int
fibs 0 _ _ _ = 0
fibs n a b c
    | c < n - 1 = fibs n ((a + b) `mod` 100000007) a (c + 1)
    | otherwise = a



main :: IO ()
main = do
    n <- readLn :: IO Int
    ns <- sequence $ replicate n (readLn :: IO Int)
    mapM_ print $ map (\x -> fibs x 1 0 0) ns 

