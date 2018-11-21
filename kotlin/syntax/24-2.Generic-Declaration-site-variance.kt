// 24-1. Generic Basic

fun main(args: Array<String>)
{
    val intBox = Box(3)
    val strBox = Box("str")
    println(intBox)
    println(strBox)

    // [Output]
    //      3
    //      str
}


// 컴파일러가 타입 T에 대해 유동적으로 확장.
data class Box<T>(var data:T)


// T는 어떤 데이터 타입이든 가능.
// 대신 인자는 Box<T> 타입으로 받음.
fun <T>println(box:Box<T>)
{
    val innerData:T = box.data
    println(innerData)
}