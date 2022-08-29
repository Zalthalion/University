/**
 * Uzdevuma formulejums
 * K304. Sastādīt Kotlin programmu, kas pārveido skaitļu sarakstu, izmetot dotu elementu tā pēdējā parādīšanās reizē.
 * Autors: Juris Freidenfelds jf18017
 */

fun main(args: Array<String>)
{
    //Instructions
    println("Please provide a list of numbers:")
    println("When satisfied with input write '-1'")

    //Declares a list and a number
    var givenList =  arrayListOf<Int>();
    var numNumber = 1;
    var input: String;

    //Considering that user only inputs integers (both signed and unsigned)
    //Any extra parsing check wont be done
    do {
        //Instructions
        println("Input number $numNumber: ")
        //Reads user input
        input = readLine()!!;
        //Adds the input to the list
        givenList.add(input.toInt());
        numNumber++;
    }while (input!="-1");

    //Display
    println("The provided list is: ")
    //Remoces the final -1, from the input
    var result = removeElementAtLastMeet(-1, givenList.toTypedArray())
   //Prints the user provided list
    println(result.contentToString());


    do
    {

            println("Please provide a number that will be removed from the list");
            println("at its last met position: ");
            var removableNumber = readLine()!!.toInt();
            result = removeElementAtLastMeet(removableNumber, result.toTypedArray())
            println("Current List: ");
            println(result.contentToString());
            println("Do you want to remove another element? (1 == yes and 0 == no)")
            var again = readLine()!!;

    }while (again == "1")


}

//A method to removes the user provided element at its last met position
fun removeElementAtLastMeet(elem: Int, ls: Array<Int>): IntArray
{
    var deleteAt = -1;

    //Loops over the array in reverse to find the position of the deletable element
    for (n in ls.count()-1 downTo 0)
    {
        //If the loop finds th deletable element - the loop breaks
       if(ls[n] == elem)
       {
           deleteAt = n;
           break;
       }
    }

    //Parses the array as a list
    var result = ls.toMutableList();

    //If deleta At has changed at all, then we can remove an element from the list
    if ( deleteAt >= 0 )
    {
        result.removeAt( deleteAt );
    }

    //We return a result list of int's changed to array
    return result.toIntArray();
}