import Control.Monad

data Tree = Empty | Node Int Tree Tree

instance Show Tree where
    show (Node x Empty Empty) = show x
    show (Node x Empty r) = show x ++ " " ++ show r
    show (Node x l Empty) = show l ++ " " ++ show x
    show (Node x l r) = show l ++ " " ++ show x ++ " " ++ show r

arrToTree :: [[Int]] -> Tree
arrToTree xs = arrToTree' xs 1

arrToTree' :: [[Int]] -> Int -> Tree
arrToTree' xs index
    | index == -1 = Empty
    | otherwise = Node index (arrToTree' xs $ xs !! (index-1) !! 0) (arrToTree' xs $ xs !! (index-1) !! 1)

swapChildrenOf :: Tree -> Int -> Tree
swapChildrenOf tree depth = swapChildrenOf' tree depth depth 1

swapChildrenOf' :: Tree -> Int -> Int -> Int -> Tree
swapChildrenOf' Empty _ _ _ = Empty
swapChildrenOf' (Node x l r) depth step curr
    | depth == curr = Node x (swapChildrenOf' r (depth+step) step (curr+1)) (swapChildrenOf' l (depth+step) step (curr+1))
    | otherwise = Node x (swapChildrenOf' l depth step (curr+1)) (swapChildrenOf' r depth step (curr+1)) 

main :: IO ()
main = do
    n <- readLn :: IO Int
    nodes <- sequence $ replicate n $ fmap (fmap read) $ fmap words getLine
    let tree = arrToTree nodes

    n <- readLn :: IO Int 

    xs <- sequence $ replicate n $ fmap (read::String->Int) getLine

    mapM_ print $ tail $ scanl (\acc x -> swapChildrenOf acc x) tree xs
