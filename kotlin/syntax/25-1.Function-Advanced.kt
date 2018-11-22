// 25-1. Function-Advanced

// 메인함수는 두 타입 중, 하나를 선택할 수 있다.
//      fun main(args:Array<String>)
//      fun main(vararg args:String)
fun main(vararg args:String)
{
    addThenPrint()
    applyThenPrint { a, b -> a / b  }
    printAll("aa", "bb", "cc")
    3 addThenPrint 4    // 3.addThenPrint(4)

    // [Output]
    //      9
    //      2
    //      aa
    //      bb
    //      cc
    //      7
}


// 함수가 단일식인 경우,
// = expr 형태로 { } 를 생략할 수 있다.
fun addThenPrint(a:Int=6, b:Int=3) = println(a + b)


// 함수의 "마지막 인자"가 람다식인 경우,
// () 밖에서 람다인자를 넘길 수 있다.
fun applyThenPrint(a:Int=6, b:Int=3, operation:(Int, Int)->Int) = println(operation(a, b))


// 함수의 인자 개수가 가변적인 경우,
// vararg 키워드를 붙이면 암묵적으로 Array 타입으로 변환된다.
fun printAll(vararg strings:String)
{
    for(str in strings)
    {
        println(str)
    }
}


// 다음의 경우의 중위 함수를 정의할 수 있다.
//      멤버함수이거나 확장함수인 경우
//      피라미터가 한 개인 경우
//      infix 키워드를 사용한 경우
infix fun Int.addThenPrint(x: Int) :Int
{
    println(this + x)
    return this+x
}