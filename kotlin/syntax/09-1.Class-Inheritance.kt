// 09-1. Inheritance : Basic-Usage

fun main(args:Array<String>) {
    val reader = DataReader(4, {a->a*a})
    println(reader.get()) // print 16
}


open class Data {
    //! 멤버필드 정의
    protected var data = 0


    //! 생성자
    constructor(data: Int)
    {
        this.data = data
    }


    //! 데이터를 반환한다.
    //! 자식 클래스가 메소드를 오버라이딩 하기 위해서는 "open" 키워드를 적어야 한다.
    open fun get() :Int
    {
        return data
    }
}


//! 클래스를 상속받으려면 { :open_class_name } 을 적는다.
class DataReader : Data
{
    //! 어떻게 데이터를 읽을 것 인지 정의.
    //! 기본값: "그대로 읽기"
    private var read: (Int)->Int = {a -> a}


    //! 생성자
    constructor(data: Int, read: (Int)->Int) : super(data)
    {
        this.read = read
    }


    //! 정의된 읽는방법에 따라, 데이터를 해석한다.
    //! 부모 클래스의 메소드를 오버라이딩 하기 위해서는 "override" 키워드를 적어야 한다.
    override fun get() :Int
    {
        return read(data)
    }
}