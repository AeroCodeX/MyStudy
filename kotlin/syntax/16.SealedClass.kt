// 16. Sealed Class

fun main(args:Array<String>) {
    val a = IntData(3)
    val b = DoubleData(3.14)
    val c = BooleanData(false)

    println(square(a))    // print "IntData(data=9)"
    println(square(b))    // print "DoubleData(data=9.8596)"
    println(square(c))    // print "BooleanData(data=false)"
}


//! 실드 클래스는 1차 서브 클래스만 허용한다.
//! 부모가 실드인 서브 클래스는, 다른 클래스에게 상속될 수 없다. (final 제한)
sealed class Data
data class IntData(val data:Int) :Data()
data class DoubleData(val data:Double) :Data()
data class BooleanData(val data:Boolean) :Data()


//! 실드 클래스는 when-is 표현식과 함께 쓸 때 유용하다.
fun square(data :Data) : Data
{
    return when(data){
        is IntData -> IntData(data.data * data.data)
        is DoubleData -> DoubleData(data.data * data.data)
        is BooleanData -> BooleanData(data.data && data.data)
    }
}



