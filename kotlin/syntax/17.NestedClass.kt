// 17. Nested Class

fun main(args:Array<String>) {
    val outer  = Outer()
    val nested = Outer.Nested()

    println(outer.call())   // print "outer"
    println(nested.call())  // print "nested"
}


class Outer {
    private val outerData = 0
    fun call():String = "outer"

    class Nested {
        fun  call():String = "nested"
        constructor()
        {
            //! Nested 클래스는 Outer 클래스의 멤버에 접근하지 못한다.
            //! this.outerData = 3   -> 불가능
        }
    }
}
