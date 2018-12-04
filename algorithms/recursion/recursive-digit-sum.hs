main :: IO()
main = do
    nk <- fmap words getLine
    let n = read $ nk !! 0 :: Integer
    let k = read $ nk !! 1 :: Integer
    let x = (n * k) `mod` 9
    let ans = if x == 0 then 9 else x
    print ans

