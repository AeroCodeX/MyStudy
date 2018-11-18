// 02-3. Primitive Type (Number) : Operation
fun main(args:Array<String>)
{
    val a = 10
    val b = 2

    //! 비트연산
    //! not은 boolean 타입에서만 지원한다.
    a shl b     // a << b   signed shift
    a shr b     // a >> b   signed shift
    a ushr b    // a >>> b  unsigned shift
    a and b
    a or b
    a xor b


    //! 범위연산
    val x = 1
    a..b        // 닫힌구간 [10, 100]
    x  in a..b   // x가 닫힌구간 [10, 100] 안에 있는가? → False
    x !in a..b   // in의 부정형 → True
}