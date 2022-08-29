<?php 
echo "Task 2.2 <br><br>";
for ($x = 1; $x <= 10; $x++) {
    for($y = 0; $y<$x; $y++)
    echo "*";
    echo "<br>";
} 



echo "<br><br>Task 2.3<br><br>";

function summa($input){
$sum = 0;
for($counter = 0; $counter<=$input; $counter++){
    $sum = $sum+$counter;
}
return $sum;
}
$rez = summa(50);
echo "N=50 and the summation is $rez";

echo "<br><br><br>Task 2.4<br><br>";


$startnum = 10;
for($counter = 0; $counter<11; $counter++){
    $rez= summa($startnum);
    echo "The summation of the first $startnum natural numbers is $rez <br>";
    $startnum = $startnum +3;
}
