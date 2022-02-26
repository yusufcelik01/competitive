cuts :: Int -> Int -> Int 
cuts m n = m *(n-1) + n*(m-1)

main = do
    line <- getLine
    let a = read $ takeWhile (/= ' ') line :: Int
    let b = read $ drop 1 $ dropWhile (/= ' ') line :: Int 
    let out = show $ cuts a b 
    putStrLn out
    
