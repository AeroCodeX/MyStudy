// 11. Operator Overloading

fun main(args:Array<String>) {
    val a = IntWrap(2)
    val b = IntWrap(4)
    val c = IntWrap(0)

    val sumAB = a + b
    val mulAB = a * b
    val notC  = !c

    println(sumAB) // print "[Wrap] 6"
    println(mulAB) // print "[Wrap] 8"
    println(notC)  // print "[Wrap] 1"
}


class IntWrap {
    var data: Int = 0
    constructor(data: Int)
    {
        this.data = data
    }

    //! 이항 연산자 오버로딩
    operator fun plus(other: IntWrap) :IntWrap {
        return IntWrap(data + other.data)
    }

    //! 단항 연산자 오버로딩
    operator fun not() :IntWrap {
        return IntWrap(if(data==0) 1 else 0)
    }

    //! toString
    override fun toString(): String {
        return "[Wrap] $data"
    }
}

//! 클래스 외부에서 이항 연산자 오버로딩
operator fun IntWrap.times(other: IntWrap) :IntWrap {
    return IntWrap(data * other.data)
}
