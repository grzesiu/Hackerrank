import Control.Applicative
import Control.Monad
import System.IO
import Text.Printf 

factorial :: (Num a, Enum a) => a -> a
factorial x = foldl (\acc x -> acc * x) 1 [1..x]

eexp :: Double -> Double
eexp x = sum [(x**n) / (factorial n) | n <- [0..9]]

main :: IO ()
main = do
    n_temp <- getLine
    let n = read n_temp :: Int
    forM_ [1..n] $ \a0  -> do
        x_temp <- getLine
        let x = read x_temp :: Double 
        printf "%.4f\n" $ eexp x

