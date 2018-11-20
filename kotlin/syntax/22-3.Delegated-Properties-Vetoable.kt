// 22-3. Delegated Properties - Vetoable
import kotlin.properties.Delegates

fun main(args: Array<String>)
{
    val myData = MyData()
    myData.data = "Hello, World!"
    println(myData.data)
    myData.data = "Hello"   // 갱신이 무시될 것 이다.
    println(myData.data)

    // [output]
    //      Hello, World!
    //      Hello, World!
}


class MyData {
    // Delegates.observable 위임자는 값의 갱신을 감지한다.
    // obserable 위임자와 다르게, 선택적으로 값의 대입을 막을 수 있다.
    var data:String by Delegates.vetoable("<Not-Init>"){
        // 이 람다식은 값의 갱신시 호출된다. (onChange)
        // 새 문자열이 이전 문자열보다 짧다면 값의 갱신을 막는다.
        // 평가식이 true 일 때, 값이 갱신된다.
        prop, old, new -> old.length < new.length
    }
}