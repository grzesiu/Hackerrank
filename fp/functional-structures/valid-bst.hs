isTree :: [Int] -> String
isTree (x:xs) = isTree' 0 [x] xs

isTree' :: Int -> [Int] -> [Int] -> String
isTree' _ _ [] = "YES"
isTree' lowerbound [] (x:xs) = isTree' lowerbound [x] xs
isTree' lowerbound (s:stack) (x:xs)
    | x < lowerbound = "NO"
    | s < x = isTree' s stack (x:xs)
    | otherwise = isTree' lowerbound (x:s:stack) xs

readTestCase :: IO [Int]
readTestCase =
    getLine >>
    fmap words getLine >>= \tree ->
    return $ map read tree

main :: IO ()
main = do
    t <- readLn :: IO Int
    tcs <- sequence $ replicate t readTestCase
    mapM_ putStrLn $ map isTree tcs
