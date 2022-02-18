bills :: Int -> Int
bills curr = hundreds + twenties + tens + fives + ones
    where   hundreds = curr `div` 100
            twenties = (curr `mod` 100) `div` 20
            tens = (curr `mod` 20) `div` 10
            fives = (curr `mod` 10) `div` 5
            ones = (curr `mod` 5)

main = do
    balance <- getLine
    let a = read balance :: Int
    let out = show $ bills a
    putStrLn out



