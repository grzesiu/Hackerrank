import Text.Printf
import Data.List
import Data.Function


getStart :: [(Int, Int)] -> (Int, Int)
getStart xs = minimumBy (compare `on` snd) xs


distance :: (Int, Int) -> (Int, Int) -> Float
distance p1 p2 = sqrt(fromIntegral ((snd p2 - snd p1) ^ 2 + (fst p2 - fst p1) ^ 2))


cosine :: (Int, Int) -> (Int, Int) -> Float
cosine p1 p2 
    | p1 == p2 = -2
    | otherwise = - fromIntegral (fst p2 - fst p1) / (distance p1 p2)


crossProd :: (Int, Int) -> (Int, Int) -> (Int, Int) -> Int
crossProd p1 p2 p3 = x1 * y2 - x2 * y1
    where x1 = fst p2 - fst p1
          x2 = fst p3 - fst p2
          y1 = snd p2 - snd p1
          y2 = snd p3 - snd p2


sortPoints :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)]
sortPoints xs start = sortBy (compCosines) xs where 
    compCosines x y
        | (cosine start x) == (cosine start y) = compare (distance start x) (distance start y)
        | otherwise = compare (cosine start x) (cosine start y)


grahamScan :: [(Int, Int)] -> [(Int, Int)] -> [(Int, Int)]
grahamScan [] (x:y:xs) = grahamScan [y, x] xs
grahamScan hs [] = hs
grahamScan [h] (x:xs) = grahamScan (x:[h]) xs
grahamScan (a:b:hs) (x:xs) 
    | crossProd b a x > 0 = grahamScan (x:a:b:hs) xs
    | otherwise = grahamScan (b:hs) (x:xs)


getPoint :: [String] -> (Int, Int)
getPoint [x, y] = (read x, read y)


getPoints :: String -> [(Int, Int)]
getPoints input = map getPoint $ map words $ lines input


perimeterAllButLast :: [(Int, Int)] -> Float
perimeterAllButLast [] = 0
perimeterAllButLast [x] = 0
perimeterAllButLast (a:b:h) = distance a b + perimeterAllButLast (b:h)

perimeter :: [(Int, Int)] -> Float
perimeter xs = distance (head xs) (last xs) + perimeterAllButLast xs

main :: IO ()
main = do
    n <- readLn :: IO Int
    input <- getContents
    let points = getPoints input
    
    printf "%.1f\n" $ perimeter $ grahamScan [] $ sortPoints points (getStart points)
