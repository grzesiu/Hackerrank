import Control.Monad

tellTheWinner :: Int -> Int -> Int -> String
tellTheWinner a b c
    | abs(c - a) < abs(c - b) = "Cat A"
    | abs(c - a) > abs(c - b) = "Cat B"
    | otherwise = "Mouse C"

readInt :: IO Int
readInt = getLine >>= return . read

readInts :: IO [Int]
readInts = fmap (map read.words) getLine

testCase :: IO String
testCase = do
    [a, b, c] <- readInts
    return $ tellTheWinner a b c
 
main = do
    q <- readInt
    replicateM_ q $ testCase >>= putStrLn
