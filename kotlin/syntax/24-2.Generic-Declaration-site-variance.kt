// 24-2. Generic-Declaration-site-variance

fun main(args: Array<String>)
{
    // 기본적으로 제네릭은 무공변이다.
    var numBox = Box<Number>(0)
    var intBox = Box<Int>(0)
    // numBox = intBox <ERR>
    // intBox = numBox <ERR>


    // 소비작업에 대한 공변 허용.
    var numWritableBox = WritableBox<Number>(0)
    var intWritableBox = WritableBox<Int>(10)
    // numWritableBox = intWritableBox <ERR>
    intWritableBox = numWritableBox



    // 공급작업에 대한 반공변 허용.
    var numReadableBox = ReadableBox<Number>(0)
    var intReadableBox = ReadableBox<Int> (10)
    // intReadableBox = numReadableBox <ERR>
    numReadableBox = intReadableBox
}


// 선언위치 변성이란,
// 클래스, 인터페이스 선언 위치에서 변성 수식어(in, out)를 정의하는 것.
//      in  : T가 소비만 가능한 타입이라고 컴파일러에게 알린다.
//      out : T가 공급만 가능한 타입이라고 컴파일러에게 알린다.
interface Writable<in T>
{
    fun write(data:T)
}
interface Readable<out T>
{
    fun read():T
}
data class WritableBox<in T> (private var data:T) : Writable<T>
{
    override fun write(data: T) {this.data = data}
}
data class ReadableBox<out T> (private var data:T) : Readable<T>
{
    override fun read(): T = data
}
data class Box<T> (private var data:T)

