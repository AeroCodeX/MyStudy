// 16. Sealed Class

fun main(args:Array<String>) {
    val a = IntData(3)
    val b = DoubleData(3.14)
    val c = BooleanData(false)

    println(square(a))    // print "9"
    println(square(b))    // print "9.8596"
    println(square(c))    // print "false"
}


//! 실드 클래스는 1차 서브 클래스만 허용하고, 그 자체는 추상 클래스이다.  (혼자 인스턴스화 불가)
//! 부모가 실드인 서브 클래스는, 다른 클래스에게 상속될 수 없다. (final 제한)
sealed class Data
data class IntData(val data:Int) :Data()
data class DoubleData(val data:Double) :Data()
data class BooleanData(val data:Boolean) :Data()


//! 실드 클래스는 when-is 표현식과 함께 쓸 때 유용하다.
fun square(data :Data) : Any
{
    return when(data){
        is IntData -> data.data * data.data
        is DoubleData -> data.data * data.data
        is BooleanData -> data.data && data.data
    }
}



