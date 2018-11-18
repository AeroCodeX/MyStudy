// 07-2. Lambda(Anonymous) function

fun main(args:Array<String>)
{
    val v1 = calc(5, 5, {a, b -> a + b})
    val v2 = calc(5, 5, {a, b -> a * b})
    println(v1) // 10
    println(v2) // 25
}

fun calc(
        val1: Int,
        val2: Int,
        exec: (p1: Int, p2: Int) -> Int   // 시그너쳐가 (int, int)이고 반환형이 int인 함수.
) : Int
{
    return exec(val1, val2)
}