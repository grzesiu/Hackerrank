import Control.Monad
import Data.Bits

howMany :: Int -> Int -> Int
howMany x d
    | x `mod` d == 0 = 1 + howMany (quot x d) d
    | otherwise = 0

factors :: Int -> Int -> Int
factors 1 _ = 0
factors x d
    | (d == 2) && (x `mod` d == 0) = hm + (factors xd 3)
    | (d == 2) = factors xd 3
    | x `mod` d == 0 = hm + (factors xd (d + 2))
    | otherwise = factors x (d + 2)
    where hm = howMany x d
          xd = quot x (d ^ hm)
  
firstOrSecond :: Int -> Int
firstOrSecond x
    | x == 0 = 2
    | otherwise = 1

testCase :: IO Int
testCase = do
    n <- readInt
    xs <- readInts
    return $ firstOrSecond $ foldl1 xor $ fmap (flip factors 2) xs

readInts :: IO [Int]
readInts = fmap (map read . words) getLine

readInt :: IO Int
readInt = getLine >>= return . read

main = do
    t <- readInt
    replicateM_ t $ testCase >>= putStrLn . show
