// 01. Hello, World!
//  프로그램의 진입점은 main 이다.
//  명령행 인자는 main 함수의 인자로 받는다.
fun main(args:Array<String>)
{
    println("Hello, World!")
    for(value in args) println(value)   // Range-based Loop
}