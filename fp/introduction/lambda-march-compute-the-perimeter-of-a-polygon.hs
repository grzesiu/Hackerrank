import Control.Monad

tuplify :: [String] -> (Int ,Int)
tuplify [x,y] = (read x::Int,read y::Int)

perimeter :: [(Int, Int)] -> Float
perimeter [] = 0.0
perimeter [(x,y)] = 0.0
perimeter (x:y:xs) = (len x y) + perimeter (y:xs)

len :: (Int, Int) -> (Int, Int) -> Float
len x y = sqrt (fromIntegral $ (fst x - fst y) ^ 2  + (snd x - snd y) ^ 2) 

main :: IO()
main = do
    n <- readLn :: IO Int
    polygon <- forM [1 .. n] (\_ -> do 
        ln <- getLine
        return $ tuplify $ words ln)
    print $ (perimeter polygon) + (len (head polygon) (last polygon))
