// 15. DataClass

fun main(args:Array<String>) {
    var a = User("a", 23)   // (a, 23)
    var b = a.copy(name="b")    // (b, 23)
    var (c, d) = a
    var e = b.component1()
    var f = b.component2()

    println(a) // print "User(name=a, age=23)"
    println(b) // print "User(name=b, age=23)"
    println(c) // a
    println(d) // 23
    println(e) // b
    println(f) // 23
}


data class User(val name: String, val age: Int){ }
//! <데이터 클래스의 쓸 때의 간편한 점>
//! 	equals() / hashCode() 자동 생성
//! 	toString() 자동 생성 -> User(name=a, age=23) 형태의 문자열로 만들어준다.
//! 	(선언한 순서대로) n번째 요소의 대응되는 componentN() 자동 생성
//! 	일부 멤버필드만 변경한 뒤, 복사하는 copy() 자동 생성

