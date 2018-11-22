// 27. Closure

fun main(vararg args: String) {
    // 람다함수는 람다 밖의 변수를 수정할 수 있다.
    var sum = 0
    (0..10).forEach { sum += it }
    println(sum)

    // [Output]
    //      55
}
