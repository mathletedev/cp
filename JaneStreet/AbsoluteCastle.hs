import Data.List

-- https://www.reddit.com/r/haskell/comments/g3xbk7/haskell_program_to_list_permutations_pnr_or_npr/
perm :: (Eq a) => [a] -> Int -> [[a]]
perm _ 0 = [[]]
perm xs r
  | length xs < r = [[]]
  -- take each x in xs; delete it; append the recursive result
  | otherwise = [x : ys | x <- xs, ys <- perm (delete x xs) (r - 1)]

hasDuplicates :: (Eq a) => [a] -> Bool
hasDuplicates xs = length (nub xs) /= length xs

diffs :: (Num a) => [a] -> [a]
diffs xs = fmap abs (zipWith (-) (tail xs) xs)

solve :: [Int] -> [Int] -> Bool
solve xs ys
  | hasDuplicates xs = False
  | null ys = True
  | otherwise = solve (xs ++ ys) (diffs ys)

nums :: [Int]
nums = [1 .. 15]

valid :: [[Int]]
valid = filter (solve []) (perm nums 5)

main :: IO ()
main = print valid
