// 22-1. Delegated Properties - Standard
import kotlin.reflect.KProperty

fun main(args: Array<String>)
{
    val myData = MyData()
    myData.data
    myData.data = "Hello, World!"
    println(myData.data)

    // [output]
    //      Read("")
    //      Write("Hello, World!")
    //      Read("Hello, World!")
    //      Hello, World!
}


class MyData {
    // 위임하는 방법은 클래스와 똑같이 by 키워드를 사용하지만,
    // 인스턴스의 형태로 주어져야 한다.
    var data:String by Observer()
}


// 위임패턴은 주로 데이터의 변화를 감지하기 위해 사용하는 패턴이다.
class Observer {
    // 위임된 프로퍼티에 값에 직접 접근 할 수 없으므로, 데이터 홀더를 정의한다.
    // get 또는 set 액션이 발생할 때 마다, 홀딩된 값을 이용한다.
    private var data: String = ""


    // 아래의 메소드는 반드시 구현해야 프로퍼티에 위임될 수 있다.
    // 값의 읽기가 발생할 때 호출된다.
    operator fun getValue(thisRef: Any?, property: KProperty<*>) :String
    {
        // 직접적으로 값에 접근할 수 있는 방법이 없다,
        // 홀딩된 데이터를 사용한다.
        println("Read(\"$data\")")
        return data
    }
    // 프로퍼티가 val(immutable) 이라면, setValue 메소드는 구현하지 않아도 된다.
    // 값의 쓰기가 발생할 때 호출된다.
    operator fun setValue(thisRef: Any?, property: KProperty<*>, value: String)
    {
        // 새로운 데이터를 홀딩한다.
        println("Write(\"$value\")")
        this.data = value
    }
}