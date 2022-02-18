import Data.Char

upper = map Data.Char.toUpper

test s1 s2 
    | a < b = -1
    | a== b = 0
    | a > b = 1
        where a = upper s1
              b = upper s2



main = do
    first <- getLine
    second <- getLine
    putStrLn $ show $ test first second
