// 26. Function-Higher-Order

fun main(vararg args: String) {
    execute { a, b -> a * b }
    evenTest(3)
    evenTest(3)()
}


// 고차함수(1) 함수를 인자로 받는 경우
fun execute(a: Int = 1, b: Int = 2, f: (Int, Int) -> Int) = println(f(a, b))


// 고차함수(2) 함수를 리턴하는 경우
fun evenTest(n: Int): () -> Unit {
    if (n % 2 == 0) return { println("isEven") } else return { println("isNotEven") }
}