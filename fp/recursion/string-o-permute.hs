swap2 :: [Char] -> [Char]
swap2 [] = []
swap2 (n1:n2:n) = [n2, n1] ++ swap2 n

submain :: Int -> IO()
submain 0 = return ()
submain x = do
    n <- getLine
    putStrLn $ swap2 n
    submain $ x - 1

main :: IO()
main = do
    t <- readLn :: IO Int
    submain t
