// 28-1. Function-Literals-With-Receiver

fun main(vararg args: String) {
    val t1 = ADD {
        // 리시버를 적용가능한 람다에서는,
        // 람다가 객체를 * this 으로 참조할 수 있다.
        // this 는 생략할 수 있다.
        add(3)
        add(2)
        add(1)
    }
    val t2 = ADD2 {
        // 평범한 람다함수에서는,
        // 람다가 객체를 객체를 it 으로 참조한다.
        // it 은 생략할 수 없다.
        it.add(3)
        it.add(2)
        it.add(1)
    }
    println(t1.data)
    println(t2.data)
}

class Adder(var data: Int = 0) {
    fun add(n: Int) {
        this.data += n
    }
}

// 리시버를 적용할 수 있는 람다
fun ADD(init: Adder.() -> Unit): Adder {
    val adder = Adder()
    adder.init()
    return adder
}

// 평범한 람다
fun ADD2(init:(Adder)->Unit):Adder{
    val adder = Adder()
    init(adder)
    return adder
}