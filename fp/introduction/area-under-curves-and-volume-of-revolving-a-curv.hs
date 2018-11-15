import Text.Printf (printf)


y :: Double -> [Int] -> [Int] -> Double
y x a b = sum $ zipWith (\ai bi -> fromIntegral ai * x ^^ bi) a b 


rect :: Double -> [Int] -> [Int] -> Double -> Double
rect x a b s = ((y x a b) + (y (x + s) a b)) * s / 2


ys :: Double -> Double -> [Int] -> [Int] -> Double -> [Double]
ys l r a b s = map (\x -> rect x a b s) [l, l + s .. r - s]


area :: [Double] -> Double
area vals = sum vals


volume :: [Double] -> Double
volume vals = sum $ map (\val -> pi * 1000 * val ^ 2) vals


solve :: Double -> Double -> [Int] -> [Int] -> Double -> [Double]
solve l r a b s = [area vals, volume vals] 
    where vals = ys l r a b s

main :: IO ()
main = getContents >>= mapM_ (printf "%.1f\n"). (\(a:b:[l, r]:_) -> solve (fromIntegral l) (fromIntegral r) a b 0.001). map (map read. words). lines
