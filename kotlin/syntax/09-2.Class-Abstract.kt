// 09-2. Inheritance : Abstract

fun main(args:Array<String>) {
    val reader = DataReader(4, {a->a*a})
    println(reader.get()) // print 16
}


//! Data 클래스는 추상 클래스.
//! 추상 클래스는 혼자서 인스턴스화 될 수 없다.
abstract class Data {
    //! 멤버필드 정의
    protected var data = 0


    //! 생성자
    constructor(data: Int)
    {
        this.data = data
    }


    //! 추상함수
    //! 자식 메소드는 반드시 이 메소드를 구현해야 한다.
    abstract fun get() :Int
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


    //! 부모의 추상함수를 오버라이드.
    override fun get() :Int
    {
        return read(data)
    }
}