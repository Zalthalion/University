module Main (md) where
    md :: IO ()

--A daļa

--Palīgfunkcija, lai no padotā saraksta tiktu noņemtu dublikāti izmantojot rekursiju. 
-- Tā tiek izmantota punktos A,B un C
removeDublicates :: Eq a => [a] -> [a]
removeDublicates = tempMas []
    where tempMas found [] = found
          tempMas found (x:xs)
              | x `elem` found = tempMas found xs
              | otherwise = tempMas (found ++ [x]) xs 


-- atgriež 2. mainīgā oro elementu, ja 1. mainīgajā ir tāda pati vērtība, kas ir 1. mainīgā pirmajā elementā
-- Un beigās noņem dublikātus.
aa x y  = removeDublicates( [snd xy | xy <- y, fst xy `elem` x])

aa1 = aa [1,2,4,8,8] [(1,3),(2,3),(3,22),(4,33),(8,13)]-- atbilst rezultāts [3,33,13]
aa2 = aa ["2","3","5","6","7"] [("2","a"),("3","b"),("5","g"),("6","g"),("7","hh")] -- atbilst rezultāts ["a","b","g","hh"]


--B daļa

--Atgriež jaunu vārdnīcu ,kas sastāv no 1. vārdnīcas  1. elementa un 2. vārdnīcas 2. elementa, ar filtru ja
-- 1. vārdnīcas  2. elements sakrīt ar  2. vārdnīcas 1. elementu
-- Un beigās noņem dublikātus.
bb x y  = removeDublicates([(x1,y2) | (x1,x2) <-x,(y1,y2) <-y, x2 == y1 ])

bb1 =  bb [("a", "b"),("c", "d"),("e", "f"),("g", "h"),("i", "j")] [("b","b"),("b","c"),("g","h"),("h","i"),("b","c")] -- atbilst rezultāts ["a","b","g","hh"]
bb2 =  bb [(1, 2),(2, 3),(2, 4),(3, 1),(222, 8)] [(2,5),(4,22),(22,4),(7,9),(1,2)] -- atbilst rezultāts [(1,5),(2,22),(3,2)]



--C daļa

--Notiek ciklošanās izmantojot rekursiju 
ccgetresult (x : xs) y = let
    k = fst x -- Apzīmē kuru reizi ciklojas
    ak = snd x -- Apzīmē pašreizējo vārdnīcu
    nak_ak = removeDublicates( ak ++ (bb ak y) )in --  Apzīmē Vārdnīcu nākamajā iterācijā noņemot dublikātus
                                             --izmantojot uzdevuma B daļā jau izstrādāto funkciju 
    if ak == nak_ak --Ja nav bijušas nekādas izmaiņas starp iterācijām tas nozīmē, ka sasniegts A(P(A)) 
    then x : xs else  ccgetresult ((k+1, nak_ak)  : x : xs) y -- Ja nav sasniegts A(P(A) 
    --tad turpina iterāciju ar jau jauno vādnīcu un palielinot k par 1 



--Sākortnējais izsaukums, kur K sākotnēji ir 1
cc a = ccgetresult [(1, a)] a


cc1 = cc [(1,2),(2,3),(3,1),(4,5),(6,7)]-- atbilst rezultāts [(3,[(1,2),(2,3),(3,1),(4,5),(6,7),(1,3),(2,1),(3,2),(1,1),(2,2),(3,3)]),(2,[(1,2),(2,3),(3,1),(4,5),(6,7),(1,3),(2,1),(3,2)]),(1,[(1,2),(2,3),(3,1),(4,5),(6,7)])]
cc2 = cc [("a","b"),("b","c"),("c","e"),("e","d"),("d","e")]
-- atbilst rezultāts [(4,[("a","b"),("b","c"),("c","e"),("e","d"),("d","e"),("a","c"),("b","e"),
--("c","d"),("e","e"),("d","d"),("a","e"),("b","d"),("a","d")]),(3,[("a","b"),("b","c"),("c","e"),
--("e","d"),("d","e"),("a","c"),("b","e"),("c","d"),("e","e"),("d","d"),("a","e"),("b","d")]),
--(2,[("a","b"),("b","c"),("c","e"),("e","d"),("d","e"),("a","c"),("b","e"),("c","d"),("e","e"),
--("d","d")]),(1,[("a","b"),("b","c"),("c","e"),("e","d"),("d","e")])]


