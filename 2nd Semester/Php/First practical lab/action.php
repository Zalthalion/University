
<?php 
$num1 = (int)$_GET["first"];
$num2 = (int)$_GET["second"]; 


if($num1 < $num2){
$rez = $num1+1;
for($counter = $num1+2; $counter<$num2; $counter++){
   $rez = $rez + $counter;
}}
else{
    
        $rez = $num2+1;
        for($counter = $num2+2; $counter<$num1; $counter++){
           $rez = $rez + $counter;
        }
}
echo $rez;


