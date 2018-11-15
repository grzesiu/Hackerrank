import qualified Data.Vector as V

getIndex :: (Int, Int) -> (Int, Int) -> Int -> Int -> (Int, Int)
getIndex (x, y) _ 0 _ = (x, y)
getIndex (x, y) (m, n) r l
    | x == l && y < n - l - 1 = getIndex (x, y + 1) (m, n) (r - 1) l
    | y == n - l - 1 && x < m - l - 1 = getIndex (x + 1, y) (m, n) (r - 1) l
    | x == m - l - 1 && y > l = getIndex (x, y - 1) (m, n) (r - 1) l
    | y == l && x > l = getIndex (x - 1, y) (m, n) (r - 1) l

getLayer :: (Int, Int) -> (Int, Int) -> Int
getLayer (x, y) (m, n) = minimum [x, y, m - x - 1, n - y - 1]

getPerimeter :: (Int, Int) -> Int -> Int
getPerimeter (m, n) l = 2 * (m + n - 4 * l) - 4 

getShift :: Int -> Int -> Int
getShift r perimeter = if r < perimeter then r else r `rem` perimeter

getElemAt :: V.Vector (V.Vector String) -> (Int, Int) -> (Int, Int) -> Int -> String
getElemAt matrix (i, j) (m, n) r = matrix V.! x V.! y
    where (x, y) = getIndex (i, j) (m, n) nr l
          nr = getShift r $ getPerimeter (m, n) l
          l = getLayer (i, j) (m, n)

main :: IO ()
main = do
    [m, n, r] <- fmap (fmap (read :: String -> Int)) $ fmap words getLine
    contents <- fmap (fmap words) $ fmap lines getContents
    let matrix = V.fromList $ fmap V.fromList contents
    let rotatedIndices = [[getElemAt matrix (i, j) (m, n) r | j <- [0 .. n - 1]] | i <- [0 .. m - 1]]
    putStr $ unlines $ map unwords rotatedIndices
