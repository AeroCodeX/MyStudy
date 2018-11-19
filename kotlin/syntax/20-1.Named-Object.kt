// 20-1. Named-Object

fun main(args:Array<String>) {
    println(Singleton.get())
}

open class SimpleData{
    protected var data:Int = 0
}
interface  SimpleInterface{
    fun get() :Int
}


//! 오브젝트는 단 1개 밖에 없는 객체. (싱글톤 구현하기 편함)
//! 오브젝트도 클래스와 인터페이스를 상속받을 수 있음.
//! 오브젝트의 이름은 Singleton
object Singleton :SimpleData(), SimpleInterface {
    override fun get(): Int {
        return data
    }
}