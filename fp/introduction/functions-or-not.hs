import Data.List
import Control.Monad

isGood :: [[String]] -> Bool
isGood [] = True
isGood (x:[]) = True
isGood (x:xs) = (length $ takeWhile (\a -> (a !! 0  /= x !! 0) || ((a !! 0 == x !! 0) && (a !! 1 == x !! 1))) xs) == length xs

isFun :: [[String]] -> Bool
isFun testcase = (length $ takeWhile (\a -> isGood a) $ tails testcase) == length testcase + 1

main :: IO ()
main = do
    t <- readLn :: IO Int

    forM_ [1 .. t] (\a -> do
            n <- readLn :: IO Int
            testcase <- forM [1 .. n] (\a -> do
                ln <- getLine
                return $ words ln)
            if isFun testcase == True then putStrLn "YES" else putStrLn "NO")
    

