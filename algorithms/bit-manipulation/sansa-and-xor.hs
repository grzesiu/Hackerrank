import Data.Bits

takeEverySecond :: [Int] -> [Int]
takeEverySecond (x:y:xs) = x:takeEverySecond xs
takeEverySecond [x] = [x]

xorOfEven :: [Int] -> Int
xorOfEven xs = foldl1 (\acc x -> acc `xor` x) $ takeEverySecond xs 

subarraysXor :: IO Int
subarraysXor = do
    n <- readLn :: IO Int
    xs <- fmap (\x -> fmap read x) $ fmap words getLine
    return $ case even n of True -> 0
                            False -> xorOfEven xs

main :: IO ()
main = do
    t <- (readLn :: IO Int)
    ans <- sequence $ replicate t subarraysXor
    mapM_ print ans
