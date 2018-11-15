everynth :: Int -> String -> String
everynth _ [] = []
everynth n (x:xs) = x:(everynth n $ drop n xs)

encrypt :: String -> [String]
encrypt xs = map (\x -> everynth n $ drop x xs) [0..n]
    where n = floor $ sqrt $ fromIntegral $ length xs - 1

main :: IO ()
main = do
    xs <- getLine
    putStrLn $ unwords $ encrypt xs
    
