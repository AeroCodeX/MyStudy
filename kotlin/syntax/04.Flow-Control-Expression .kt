// 04. Flow-Control Expression
fun main(args:Array<String>)
{
    var x = 4

    //! if 문
    if(x  < 10) println(x)
    else println(10)

    //! when 문
    when(x){
        1 -> println("one")
        2 -> println("two")
        3 -> println("three")
        4 -> println("four")
        else -> println("else")
    }

    // if와 when 문은 표현식(expression)이다.
    var y = if(x<10) x else 10
    var z = when(x){
        1 -> "one"
        2 -> "two"
        3 -> "three"
        4 -> "four"
        else -> "else"
    }
}