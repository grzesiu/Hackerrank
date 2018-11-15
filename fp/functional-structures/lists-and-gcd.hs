import qualified Data.Map as M

minCommonMembers :: [M.Map Int Int] -> M.Map Int Int
minCommonMembers (m:ms) = foldl (\acc x -> M.intersectionWith min acc x) m ms

toMap :: [Int] -> M.Map Int Int
toMap [x,y] = M.singleton x y 
toMap (x:y:xs) = M.insert x y $ toMap xs 


show' :: M.Map Int Int -> String
show' m = foldl (\acc (k, v) -> acc ++ show k ++ " " ++ show v ++ " ") "" $ M.toList m


main :: IO ()
main = do
    contents <- getContents
    let lists = map (\x -> map (read :: String -> Int) $ words x) $ tail $ lines contents
    let awd = map toMap lists
    putStrLn $ show' $ minCommonMembers awd

