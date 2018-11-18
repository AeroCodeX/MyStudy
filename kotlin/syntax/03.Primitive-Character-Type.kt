// 03-1. Primitive Type (character)
fun main(args:Array<String>)
{
    //! 문자타입 변수 선언
    var c : Char   = 'c'  // 형식추론 가능, var c = 'c' 로 축약할 수 있다.
    var s : String = "Hello, World!"


    //! 비교,범위 연산
    c.toInt() == 0     // 비교연산을 하려면 타입을 맞춰야 한다.
    c in 'a' .. 'z'


    //! 문자열은 문자의 배열이다.
    println(s[0])
    for(ch in s) print(ch)


    //! 문자열 리터럴
    val text1 = "Hello, World!"
    val text2 = """
        Hello,
        World!
    """.trimIndent()  // 왼쪽의 공백을 없애는 메소드.


    //! 문자열 템플릿
    val i = 10
    println("i = $i")  // print "i = 10"
    println("${'$'}")  // '$'를 출력해야 한다면 감싼다.
}