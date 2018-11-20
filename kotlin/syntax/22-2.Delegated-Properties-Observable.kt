// 22-2. Delegated Properties - Observable
import kotlin.properties.Delegates

fun main(args: Array<String>)
{
    val myData = MyData()
    myData.data
    myData.data = "Hello, World!"
    println(myData.data)

    // [output]
    //      var MyData.data: kotlin.String   <Not-Init> -> Hello, World!
    //      Hello, World!
}


class MyData {
    // Delegates.observable 위임자는 값의 갱신을 감지한다.
    // obserable 위임자는 갱신을 막을 수 없으며,
    // 갱신을 막아야 하는 경우가 있다면 Delegates.vetoable 위임자를 사용해야 한다.
    var data:String by Delegates.observable("<Not-Init>"){
        // 이 람다식은 값의 갱신시 호출된다. (onChange)
        // prop: KProperty<*>
        // old와 new의 타입은 동일해야 한다.
        prop, old, new -> println("$prop   $old -> $new")
    }
}