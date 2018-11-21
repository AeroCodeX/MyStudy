// 24-4. Generic-Use-site variance (Star-Projection)

fun main(args: Array<String>)
{
    val myArray:MyArray<*> = MyArray(arrayOf(1.0, "str", true)) // MyArray<out Any?>
    printMyArray(myArray)

    // [Output]
    //      1.0
    //      str
    //      true
}


// 사용위치 변성이란,
// 메소드 위치에서 변성 수식어(in, out, *)를 정의하는 것.
// *("스타-애스터리스크")를 사용한 변성이라 하여, 스타 프로젝션이라고 한다.
//      *  : out Any?   으로 번역된다.
class MyArray<T> (val array: Array<T>)
fun printMyArray(myArray: MyArray<*>)
{
    for(data in myArray.array)
    {
        println(data)
    }
}



