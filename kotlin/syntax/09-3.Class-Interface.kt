// 09-3. Interface

fun main(args:Array<String>) {
    val reader = DataReader(4, {a->a*a})
    println(reader.get()) // print 16
}


interface DataReadable {
    var data  :Int   // abstract
    fun get() :Int
}


//! 클래스를 상속받으려면 { :open_class_name } 을 적는다.
class DataReader : DataReadable
{
    override var data: Int
    private  var read: (Int)->Int = {a->a}

    constructor(data:Int, read:(Int)->Int)
    {
        this.data = data
        this.read = read
    }


    //! 인터페이스 구현
    override fun get() :Int {
        return read(data)
    }
}