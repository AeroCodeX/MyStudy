// 07-1. named function

//! 엄격한 함수선언
//! Long add (int a = 3, int b = 1)
fun add1(a:Int = 3, b:Int = 1) : Long
{
    return (a + b).toLong()
}


//! 간결한 함수선언 (하나의 표현식만 있을 때 가능)
//! 반환형은 컴파일러가 유추한다.
fun add2(a:Int, b:Int) = (a+b).toLong()


//! 제네릭 <T>
//! 가변인자 함수 (vararg)
fun <T> printAll(vararg list : T)
{
    for(item in list) println(item)
}


//! 함수사용
fun main(args:Array<String>)
{
    add1(3, 4)  // 3 + 4 = 7
    add1(3)         // 3 + 1 = 4
    add1(b=2)           // 3 + 2 = 5

    printAll(4.2, 4.7, 5.9)
}



