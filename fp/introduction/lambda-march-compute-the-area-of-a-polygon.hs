import Control.Monad

tuplify :: [String] -> (Int ,Int)
tuplify [x,y] = (read x::Int,read y::Int)

part_area :: (Int, Int) -> (Int, Int) -> Float
part_area x y = (fromIntegral ((snd x + snd y) * (fst x - fst y))) / 2.0

area :: [(Int, Int)] -> Float
area [] = 0.0
area [(x,y)] = 0.0
area (x:y:xs) = (part_area x y) + (area (y:xs))

aabs :: Float -> Float
aabs x = if x > 0 then x else -x 

main :: IO()
main = do
    n <- readLn :: IO Int
    polygon <- forM [1 .. n] (\_ -> do 
        ln <- getLine
        return $ tuplify $ words ln)
    print $ aabs $ area polygon + (part_area (last polygon) (head polygon))
