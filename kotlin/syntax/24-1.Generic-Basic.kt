// 24-1. Generic Basic

fun main(args: Array<String>)
{
    val intBox = Box(3)
    val strBox = Box("str")
    println1(intBox)
    println1(strBox)
    println2(intBox)
    println2(strBox)

    // [Output]
    //      3
    //      str
    //      3
    //      str
}


// 컴파일러가 타입 T에 대해 유동적으로 확장.
data class Box<T>(var data:T)


// T는 어떤 데이터 타입이든 가능.
// 인자는 Box<T> 타입으로 받음.
fun <T>println1(box:Box<T>)
{
    val innerData:T = box.data
    println(innerData)
}


// 처음부터 T를 Box<*> 이하로 제한. (상위 한계)
// 인자는 Box<*> 이하로 제한된 T 타입으로 받음.
fun <T:Box<*>>println2 (box:T)
{
    val innerData:Any? = box.data // box.data is Any?
    println(innerData?.toString())
}