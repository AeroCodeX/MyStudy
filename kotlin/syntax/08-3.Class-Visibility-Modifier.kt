// 08-3. Class : Visibility-Modifier

fun main(args:Array<String>) {
    val data = Data(2, 2)
    println(data.num1)  // 컴파일 에러 (private)    :Data 안에서만
    println(data.num2)  // 컴파일 에러 (protected)  :Data 서브클래스 안에서만
    println(data.num3)
    println(data.get()) // 컴파일 에러 (private)

}


class Data {
    //! 각각의 필드 아래에 getter 또는 setter 메소드를 재정의할 수 있다.
    private   var num1 = 0
    protected var num2 = 0
    public    var num3 = 0
    private fun get() : Int{
        return num1 + num2
    }
}