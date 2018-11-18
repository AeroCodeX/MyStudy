// 08-1. Class : Member-Field

fun main(args:Array<String>) {
    val book = Book(title="none", price=-1, type=20)
    println(book)
    // title : ---
    // price : 1234
    // type  : 2
}


class Book {
    //! 각각의 필드 아래에 getter 또는 setter 메소드를 재정의할 수 있다.
    var title : String = "none"
        get() {
            // field is "title"
            return if( field=="none" ) "---" else field
        }
    var price : Int = 0
        set(value){
            // field is "price"
            field = if(value < 0) 1234 else value
        }
    var type  : Int = 0  // 0: "베스트셀러", 1: "스테디셀러", 2: 기타
        set(value) {
            // field is "type"
            field = if(value in 0..1) value else 2
        }


    //! 생성자
    constructor(title: String, price: Int, type: Int)
    {
        this.title = title
        this.price = price
        this.type  = type
    }


    //! toString() 오버라이드
    override fun toString(): String {
        val stringBuilder = StringBuilder()
        stringBuilder.appendln("title : $title")
        stringBuilder.appendln("price : $price")
        stringBuilder.appendln("type  : $type")
        return stringBuilder.toString()
    }
}