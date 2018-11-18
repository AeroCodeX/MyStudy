// 02-1. Primitive Type (Number) : Declare
fun main(args:Array<String>)
{
    //! var  : 변수 (mutable)
    //! val  : 상수 (Immutable) → 변경 시도시, 컴파일 에러.


    //! 정수 타입 (Long, Int, Short, Byte)
    var a:Long  = 0L  // 64 bit (Long Literal : L)
    var b:Int   = 0   // 32 bit
    var c:Short = 0   // 16 bit
    var d:Byte  = 0   //  8 bit


    //! 부동소수점 타입 (Double, Float)
    var e:Double = 1.5e+10  // 64 bit (Double 타입은 e를 사용한 초기화 가능)
    var f:Float  = 123.5f   // 32 bit (Float Literal : f or F)


    //! 코틀린에서 지원하는 다양한 리터럴
    val oneMillion1 = 1000000    // 타입은 Int
    val oneMillion2 = 1000000L   // 타입은 Long
    val oneMillion3 = 1_000_000L // 언더스코어(_)는 가독성을 위해 사용할 수 있음. (Kotlin 1.1부터)
    val hexBytes = 0xFF_EC_DE_5E
    val binBytes = 0b11010010_01101001_10010100_10010010
}