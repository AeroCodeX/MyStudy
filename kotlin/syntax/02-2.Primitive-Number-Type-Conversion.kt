// 02-2. Primitive Type (Number) : Type Conversion
fun main(args:Array<String>)
{
    //! 명시적 형변환.
    //! 모든 정수자료형은 아래의 메소드를 가지고 있다.
    var num1 = 0    // num1 is Int
    num1.toLong()
    num1.toInt()
    num1.toShort()
    num1.toByte()
    num1.toDouble()
    num1.toFloat()


    //! 암묵적 형변환.
    //! 더 범위가 큰 자료형으로 타입을 맞춘다.
    var num2 = 1L + 3   // Long + Int ->  Long
}