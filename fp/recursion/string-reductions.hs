import qualified Data.Set as Set

reduct :: Set.Set Char -> String -> String -> String
reduct s l [] = l
reduct s l (x : xs)
    | Set.notMember x s = reduct (Set.insert x s) (l ++ [x]) xs
    | otherwise = reduct s l xs

main :: IO ()
main = do
    str <- getLine
    putStrLn $ reduct Set.empty [] str

