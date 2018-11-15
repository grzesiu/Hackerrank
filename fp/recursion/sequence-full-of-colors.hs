toInt :: Bool -> Int
toInt True = 1
toInt False = 0

isColorful :: String -> Int -> Int -> Int -> Int -> Bool
isColorful [] r g b y = (r == g) && (b == y)
isColorful (x : xs) r g b y
    | r - g > 1 = False
    | y - b > 1 = False
    | otherwise = isColorful xs rn gn bn yn
    where rn = r + (toInt $ x == 'R')
          gn = g + (toInt $ x == 'G')
          bn = b + (toInt $ x == 'B')
          yn = y + (toInt $ x == 'Y')

runTestCase :: Int -> IO ()
runTestCase 1 = getLine >>= (\xs -> putStrLn $ show $ isColorful xs 0 0 0 0)
runTestCase t = runTestCase (t - 1) >> getLine >>= (\xs -> putStrLn $ show $ isColorful xs 0 0 0 0)

main :: IO ()
main = (readLn :: IO Int) >>= (\t -> runTestCase t)
