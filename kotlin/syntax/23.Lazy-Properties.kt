// 23. Lazy Properties

fun main(args: Array<String>)
{
    hello += " "
    world += "!!!"
    println(lazyHelloWorld)

    world = ""
    println(LazyClass().lazyHelloWorld)


    //! 로컬 변수에도 사용할 수 있음 (1.1부터)
    val lazyHelloWorldLocal: String by lazy(LazyThreadSafetyMode.SYNCHRONIZED) {
        println("Computed!")
        hello+world
    }
    println(lazyHelloWorldLocal)


    // [Output]
    //      Computed!
    //      Hello, World!!!
    //      Computed!
    //      Hello,
    //      Computed!
    //      Hello,
}


// 값의 계산 시점을 최대한 늦춘다.
// LazyThreadSafetyMode (쓰레드 동기화 수준)
//     * SYNCHRONIZED : 기본값
//          최초 하나의 쓰레드에 의해서만 초기화 가능.
//          초기화 된 시점에서 다른 모든 쓰레드의 값도 초기화 됨.
//     * PUBLICATION  :
//          다수의 쓰레드가 초기화를 시도할 수 있음.
//          단, 다른 쓰레드에서 이미 초기화 된 값이 있다면, 그 값을 사용.
//     * NONE :
//          다수의 쓰레드가 초기화를 시도할 수 있음.
//          자신의 쓰레드의 값이 초기화 되지 않은 경우, 무조건 초기화.
//          멀티 쓰레딩 상황에서 문제가 발생할 수 있음.
var hello = "Hello,"
var world = "World"


//! 최상위 변수에서 사용할 수 있음.
val lazyHelloWorld: String by lazy(LazyThreadSafetyMode.SYNCHRONIZED) {
    println("Computed!")
    hello+world
}


class LazyClass {
    //! 클래스의 멤버필드에서도 사용할 수 있음.
    //! 동기화 수준을 명시하지 않은 경우, SYNCHRONIZED 수준이 적용됨.
    val lazyHelloWorld: String by lazy {
        println("computed!")
        hello + world
    }
}