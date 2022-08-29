<?php $number = (int)$_GET["number"];


function primeCheck($num){ 
    if ($num == 1) 
    return 0; 
    if ($num < 1)
    return 0;

    for ($i = 2; $i <= $num/2; $i++){ 
        if ($num % $i == 0) 
            return 0; 
    } 
    return 1; 
} 


$flag = primeCheck($number); 
if ($flag == 1) 
    echo "Prime"; 
else
    echo "Not Prime";
