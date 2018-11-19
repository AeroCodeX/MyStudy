// 18. Inner Class

fun main(args:Array<String>) {
    val outer = Outer()
    val inner = outer.Inner()   // 내부 클래스는 외부 클래스의 "인스턴스" 안에 있다.

    println(outer.call())   // print "outer"
    println(inner.call())   // print "inner"
    println(outer.outerData) // print "3"
}


class Outer { // 암묵적인 라벨선언 Outer
    var outerData = 0
    fun call():String = "outer"

    inner class Inner { // 암묵적인 라벨선언 Inner
        fun  call():String = "inner"
        constructor() : super()
        {
            //! this 키워드를 명확하게 선언 (한정된 this 식)
            val outer = this@Outer
            val inner = this@Inner

            //! Inner 클래스는 Outer 클래스에 접근할 수 있다.
            outer.outerData = 3
        }
    }
}
