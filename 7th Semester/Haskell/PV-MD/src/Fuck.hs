--Beāte Galiņa, bg17010
--MD21 kursā Programmēšanas valodas

module Fuck (md) where

    md :: IO ()

-- Funkcija, kura pārliecinās, lai izsaukuma rezultātā vērtības neparādītos divreiz (tā tiek izmantota visās daļās - A,B,C)
    removeDups :: (Eq a) => [a] -> [a]
    removeDups lst = rd lst []

    rd :: (Eq a) => [a] -> [a] -> [a]
    rd [] _ = []
    rd (x:xs) list
         | (x `elem` list) = rd xs list
         | otherwise = x : rd xs (x:list)

--A:
    --šeit tiek atgriezts otrais elements, ja pirmais elements ar to sakrīt
    a x y = [values | (key,values) <- y, key `elem` x]
    -- šeit tiek noņemti dublikāti
    aa x y = removeDups(a x y)

--Divi testpiemēri:
    --Testpiemērs izmantojot skaitļus
    v1_a1 = [1,2,2,1,1,1]
    v2_a1 = [(1, 987),(2,1),(3,7),(4,7), (5,7)]
    aa1 = aa v1_a1 v2_a1  -- Rezultāts:[987,1]

    --Testpiemērs, kur skaitlim atbilst vārds
    v1_a2 = ["1","2","2","2","3","4","5","5","5"]
    v2_a2 = [("1","ir"),("2","ziema"),("3","un"),("1","ir"),("5","aukstums")]
    aa2 = aa v1_a2 v2_a2 -- rezultāts: ["ir","ziema","un","aukstums"]


--B:
    -- šeit tiek definēta 2 argumentu funkcija bb, kura saņemot ieejā divas vārdnīcas (viena datu tipa), izejā izdos abu vārdnīcu kompozīciju
    --funkcijā bb tiek pārbaudīts un kompozīcijas vārdnīcā tiks iekļauti tikai tie pāri, kuriem vienā vārdnīcā eksistē tāda vērtība y1 un otrā vārdnīcā - y2, kur y1 == y2
    -- un pēctam tiek noņemti dublikāti
    bb a b = removeDups [(x, z) | (x, y1) <- a, (y2, z) <- b, y1 == y2]
--Divi testpiemēri:
    --Testpiemērs izmantojot burtus
    v1_b1 = [("ab", "cd"), ("ef", "gh"), ("ef", "gh"), ("ij", "kl"), ("mn", "op")]
    v2_b1 = [("cd", "ef"), ("gh", "ef"), ("op", "zzz"), ("i", "ff"), ("kl", "en")]
    bb1 = bb v1_b1 v2_b1 -- Rezultāts: [("ab","ef"),("ef","ef"),("ij","en"),("mn","zzz")]

    --Testpiemērs izmantojot skaitļus
    v1_b2 = [(1,2), (3,4), (3,6), (7,8), (9,10)]
    v2_b2 = [(1,1), (2,2), (4,0), (6,0), (8,555000)]
    bb2 = bb v1_b2 v2_b2  -- Rezultāts: [(1,2),(3,0),(7,555000)]


--C:
    --Funkcija, kura veido ciklu
    -- k - atzīmē ciklošanās reizi, kas arī testpiemēros redzams kā pirmais skaitlis
    -- ak ir A(K)
    -- ak_next ir A(K+1)
    -- no vārdnīcas tiek izņemti dublikāti
    -- funkcija darbojas līdz ak == ak_next
    ccRes (x : xs) y = let
         k = fst x
         ak = snd x
         ak_next = removeDups (ak++ (bb ak y) ) in
         if ak == ak_next then x : xs else  ccRes ((k+1, ak_next)  : x : xs) y -- Ja nav A(P(A), tad k+1 un cikls sākas no sākuma

    --Izsaukums, kurai tiek padots vērtība K(1) un vārdnīca
    cc a = ccRes [(1, a)] a

--Divi testpiemēri:
    --Testpiemērs izmantojot ciparus
    v_c1= [(1,2),(2,3),(2,3),(1,1),(4,5),(5,1)]
    cc1 = cc v_c1
    --Rezultāts:
    --[(4,[(1,2),(2,3),(1,1),(4,5),(5,1),(1,3),(4,1),(5,2),(4,2),(5,3),(4,3)]),(3,[(1,2),(2,3),(1,1),(4,5),(5,1),(1,3),(4,1),(5,2),(4,2),(5,3)]),(2,[(1,2),(2,3),(1,1),(4,5),(5,1),(1,3),(4,1),(5,2)]),(1,[(1,2),(2,3),(2,3),(1,1),(4,5),(5,1)])]
    
    --Testpiemērs izmantojot burtus
    v_c2 = [("ab","cd"),("cd","ef"),("gh","ij"),("ij","kl"),("kl","mn")]
    cc2 = cc v_c2
    --Rezultāts:
    --[(3,[("ab","cd"),("cd","ef"),("gh","ij"),("ij","kl"),("kl","mn"),("ab","ef"),("gh","kl"),("ij","mn"),("gh","mn")]),(2,[("ab","cd"),("cd","ef"),("gh","ij"),("ij","kl"),("kl","mn"),("ab","ef"),("gh","kl"),("ij","mn")]),(1,[("ab","cd"),("cd","ef"),("gh","ij"),("ij","kl"),("kl","mn")])]

