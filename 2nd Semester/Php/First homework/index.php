<?php

/**
 * This is the main file which receives and analyzes data, 
 * generates response data and finally calls the template.
 */

// show all warnings and errors on the screen
error_reporting(E_ALL);
ini_set('display_errors', 1);

$currencies = array ("AED"=>"U.A.E Dirham",
"AMD"=>"Armenia Dram",
"ARS"=>"Argentine Peso",
"AUD"=>"Australian Dollar",
"AZN"=>"Azerbaijan Manat",
"BBD"=>"Barbadian Dollar",
"BDT"=>"Bangladeshi taka",
"BGN"=>"Bulgarian Lev",
"BHD"=>"Bahrain Dinar",
"BND"=>"Brunei Dollar",
"BOB"=>"Bolivian Boliviano",
"BRL"=>"Brazilian Real",
"BWP"=>"Botswana Pula",
"BYN"=>"Belarussian Ruble",
"CAD"=>"Canadian Dollar",
"CHF"=>"Swiss Franc",
"CLP"=>"Chilean Peso",
"CNY"=>"Chinese Yuan",
"COP"=>"Colombian Peso",
"CRC"=>"Costa Rican Colón",
"CZK"=>"Czech Koruna",
"DKK"=>"Danish Krone",
"DOP"=>"Dominican Peso",
"DZD"=>"Algerian Dinar",
"EGP"=>"Egyptian Pound",
"EUR"=>"Euro",
"GBP"=>"U.K. Pound Sterling",
"HKD"=>"Hong Kong Dollar",
"HRK"=>"Croatian Kuna",
"HUF"=>"Hungarian Forint",
"IDR"=>"Indonesian Rupiah",
"ILS"=>"Israeli New Sheqel",
"INR"=>"Indian Rupee",
"IRR"=>"Iranian rial",
"ISK"=>"Icelandic Krona",
"JOD"=>"Jordanian Dinar",
"JPY"=>"Japanese Yen",
"KGS"=>"Kyrgyzstan Som",
"KRW"=>"South Korean Won",
"KWD"=>"Kuwaiti Dinar",
"KZT"=>"Kazakhstani Tenge",
"LBP"=>"Lebanese Pound",
"LKR"=>"Sri Lanka Rupee",
"LYD"=>"Libyan Dinar",
"MDL"=>"Moldova Lei",
"MUR"=>"Mauritian Rupee",
"MXN"=>"Mexican Peso",
"MYR"=>"Malaysian Ringgit",
"NGN"=>"Nigerian Naira",
"NIO"=>"Nicaraguan Córdoba",
"NOK"=>"Norwegian Krone",
"NPR"=>"Nepalese Rupee",
"NZD"=>"New Zealand Dollar",
"OMR"=>"Omani Rial",
"PEN"=>"Peruvian Nuevo Sol",
"PGK"=>"Papua New Guinean kina",
"PHP"=>"Philippine Peso",
"PKR"=>"Pakistani Rupee",
"PLN"=>"Polish Zloty",
"PYG"=>"Paraguayan Guaraní",
"QAR"=>"Qatari Rial",
"RON"=>"Romanian New Leu",
"RSD"=>"Serbian Dinar",
"RUB"=>"Russian Rouble",
"SAR"=>"Saudi Riyal",
"SEK"=>"Swedish Krona",
"SGD"=>"Singapore Dollar",
"THB"=>"Thai Baht",
"TJS"=>"Tajikistan Ruble",
"TMT"=>"New Turkmenistan Manat",
"TND"=>"Tunisian Dinar",
"TRY"=>"Turkish Lira",
"TTD"=>"Trinidad Tobago Dollar",
"TWD"=>"New Taiwan Dollar",
"UAH"=>"Ukrainian Hryvnia",
"USD"=>"U.S. Dollar",
"UYU"=>"Uruguayan Peso",
"UZS"=>"Uzbekistan Sum",
"VEF"=>"Venezuelan Bolivar",
"VND"=>"Vietnamese Dong",
"XAF"=>"Central African CFA Franc",
"XOF"=>"West African CFA Franc",
"ZAR"=>"South African Rand");

// DO NOT EDIT BEFORE THIS LINE

/* Functions and classes You might want to use (you have to study function descriptions and examples)
 * Note: You can easily solve this task without using any regular expressions
file_get_contents() http://lv1.php.net/file_get_contents
file_put_contents() http://lv1.php.net/file_put_contents
file_exists() http://lv1.php.net/file_exists
round() http://lv1.php.net/round
SimpleXMLElement http://php.net/manual/en/simplexml.examples-basic.php http://php.net/manual/en/class.simplexmlelement.php 
date() http://lv1.php.net/manual/en/function.date.php or Date http://lv1.php.net/manual/en/class.datetime.php
Multiple string functions (choose by studying descriptions) http://lv1.php.net/manual/en/ref.strings.php
Multiple variable handling functions (choose by studying descriptions) http://lv1.php.net/manual/en/ref.var.php
Optionally you can use some array functions (with $_GET, $target_currencies) http://lv1.php.net/manual/en/ref.array.php
*/

// Your code goes here

$result = ""; //valid values: empty string, "OK", "ERROR"
$result_message = "";
$date = "";

//
//by jf18017 Juris Freidenfelds
//

 //Function that downloads currency rate and writes it in a xml file
function create_file()
{    
    global $result;
    global $result_message;
    $currency_from = $_GET['trans_currency'];
    $filename = "xml/$currency_from.xml";
    // $url = "http://www.floatrates.com/daily/$currency_from.xml";
    $file_data = file_get_contents("http://www.floatrates.com/daily/$currency_from.xml");

     //If the data can not be downloaded, then the result changes to "ERROR" and converts the result message to the corresponding message
    if($file_data == FALSE)
    {
        $result = "ERROR";
        $result_message = "Currency rates could not be downloaded!";

    } 
    else  
     //If it is possible, to download the currency rates then...
    {
     //Function creates and opens a file
        $file = fopen($filename, "a+w"); //a+w allows to create a file and write in it
     //Fill the document with downloaded data
        fwrite($file, $file_data);
     //Closes the document
        fclose($file);
        $result = "OK";
    }
}

$fails=0; //This is a counter for how many fails does the user make while filling the fields
$trans_currency_test = 13; //test value, that works as an error code, that should change if the selected currency appears in the array
$card_currency_test = 13; //test value, that works as an error code, that should change if the selected currency appears in the array
//This is the data validation block

//Checks if aleast one field contains information
if(!empty($_GET))
//If atleast one field contains information, the code starts to check for all possible user made mistakes
{

 //Checks if the value entered in "amount" is a numberic value. If it is not numberic then the code checks if the field is empty (empty field is also not a numberic value)
    if(!is_numeric($_GET['amount']))
    {   
        if($_GET['amount'] =='')
        {
            $fails++;
            $result = "ERROR";
            $result_message .= "The amount field is empty! Please enter a number that is bigger than zero!";
        }
        else
        {
            $fails++;
            $result = "ERROR";
            $result_message .= "The value you entered in amount is not numeric! Please enter a numberic value! (must be larger than zero!) ";    
        } 
    }
 //Checks if the value entered in "Amount" is larger than 0
    if(is_numeric($_GET['amount']) && $_GET['amount'] <= 0)
    {
        $fails++;
        $result = "ERROR";
        $result_message .= "The value you entered in amount is equal or lower to zero! Please enter an amount that is larger than zero!";    
    }
 //Checks if the value entered in "Bank fee" is numberic. If it is not numberic, then the code checks if the field is empty (empty field is also not a numberic value)
    if(!is_numeric($_GET['bank_fee']))
    {
        if($_GET['bank_fee'] =='')
        {
         $fails++;
         $result = "ERROR";
         $result_message .= "The bank fee field is empty! Please enter a number between 1 and 0!";
        }
        else
        {
         $fails++;
         $result = "ERROR";
         $result_message .= "The value you entered in Bank Fee is not numberic! Please enter a numberic value between 0 and 100.";    
        }
    }
 //Checks if the value entered in "Bank fee" is lower than 0
    if(is_numeric($_GET['bank_fee']) && $_GET['bank_fee'] < 0)
    {
        $fails++;
        $result = "ERROR";
        $result_message .= "The value you enteref in Bank Fee is too small! Please enter a numberic value between 0 and 100.";    
    }
 //Checks if the value put in "Bank fee" is bigger than 100
    if(is_numeric($_GET['bank_fee']) && $_GET['bank_fee'] >100)
    {
        $fails++;
        $result = "ERROR";
        $result_message .= "The value you entered in Bank Fee is too big! Please enter a numberic value between 0 and 100.";    
    }
 //Checks if the user has selected a card currency
    if($_GET['card_currency']=='')
    {
        $fails++;
        $result = "ERROR";
        $result_message .= "Please select a card currency.";    
    }
     //if the currency has been selected, then the code checks if it exists in the currency array
    else
    {
        
        foreach($currencies as $cur=>$let)
        {
            if($cur == $_GET['card_currency'])
            {
                $card_currency_test = 0;
                break;
            }
            
        }
        if($card_currency_test == 13)
        {
        $fails++;
        $result = "ERROR";
        $result_message .= "The card curency you provided does not exist in the database! Please provide a correct currency!";
        }
        //Checks if the selected currencies are not the same
        if($_GET['card_currency']==$_GET['trans_currency'])
        {
            $fails++;
            $result = "ERROR";
            $result_message .= "The card curency is the same as the Transaction currency! Please choose diffrent currencies!";
        }
    }
    
 //Checks if the user has selected a transaction currency
    if($_GET['trans_currency']=='')
    {
        $fails++;
        $result = "ERROR";
        $result_message .= "Please select transaction a card currency.";    
    }
 //if the currency has been selected, then we check if it exists in the currency array
 else
    {
        foreach($currencies as $cur=>$let)
        {
            if($cur == $_GET['trans_currency'])
            {
                $trans_currency_test = 0;
                break;
            }
        }
        if($trans_currency_test==13)
        {
            $fails++;
            $result = "ERROR";
            $result_message .= "The transaction currency you selected does not exist in the database! Please select a correct currency!";
        }
    
    }   
     //If all tests passed, then the "fails" counter should be 0
     if($fails==0)
    {
     //And it means that the input data is correct and we can continue
        $currency_from = $_GET['trans_currency'];
        $filename = "xml/$currency_from.xml";
     // Checks if there is a xml document made for the corresponding currency(value put in "transaction currency" field)
        if (file_exists($filename)) 
        {
            $xml = simplexml_load_file($filename);
            $result_time = $xml->xpath("pubDate");
            $date_from = strtotime($result_time[0]);
         //Checks if the document is outdated
            if((time()-(60*60*24)) > $date_from)
            {
             //If it is outdated we crate a new one
                create_file();

                $result = "OK";
            } else
             //Otherwise we just continue our work
            {
                $result = "OK";
            }
        }
        else
         //If file doe not exists we create it and continue 
        {
            create_file();
            $result = "OK";
        }

        $xml = simplexml_load_file($filename);
        $result_time = $xml->xpath("pubDate");
        $date = $result_time[0];
        $items = $xml->xpath("item");
        foreach($items as $item)
        {
         //An if statement that finds the corresponding "targetCurency"(must be the same as "card_currency" value) from our created xml file
            if($item->targetCurrency == $_GET['card_currency'])
            {
                //If we find the correct 'targetCurrency' then we can get the corresponding exchangerate and convert it to float type (because multiplication did not work with 2 string values)
                $rate =floatval( $item->exchangeRate);
                //Gets the value from 'amount' and converts it to a float type (because multiplication did not work with 2 string values)
                $amount = floatval($_GET['amount']);
                $money = $_GET['amount'] * $rate;
                $result_message = round($money + $money*$_GET['bank_fee']/100 , 2);
               
            }
        }       
    }
}
// DO NOT EDIT AFTER THIS LINE
//rebel mode on
require("view.php");

