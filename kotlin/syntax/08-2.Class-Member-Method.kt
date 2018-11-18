// 08-2. Class : Member-Method

fun main(args:Array<String>) {
    val adder = Adder(2, 3)
    println(adder)  // Adder : 2 + 3 = 5

}


class Adder {
    //! 각각의 필드 아래에 getter 또는 setter 메소드를 재정의할 수 있다.
    var num1 = 0
    var num2 = 0


    //! 생성자
    constructor(num1: Int, num2: Int)
    {
        this.num1 = num1
        this.num2 = num2
    }


    //! 멤버 메소드
    fun get() : Int{
        return num1 + num2
    }


    //! toString() 오버라이드
    override fun toString(): String {
        return "Adder : $num1 + $num2 = ${get()}"
    }
}