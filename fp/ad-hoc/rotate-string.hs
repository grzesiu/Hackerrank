import Data.List

rotate :: String -> String -> [String]
rotate [] ys = []
rotate (x:xs) ys = (xs ++ ys ++ [x]) : (rotate xs $ ys ++ [x])

main :: IO ()
main = do
    xs <- getContents
    mapM_ putStrLn $ map (intercalate " ") $ map (\x -> rotate x []) $ tail $ lines xs

