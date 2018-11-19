// 14. Late-Initialized

fun main(args:Array<String>) {
    var data = Data()
    println(data)
}

class Data {
    //! late-init 키워드를 적으면 초기화를 나중으로 미룰 수 있다.
    //! 초기화 하지 않고, 값에 접근하면 익셉션이 발생한다.
    //!     UninitializedPropertyAccessException
    lateinit var str: String
    override fun toString(): String {
        //! 초기화 여부 확인하기 (1.2부터)
        return if(this::str.isInitialized) str else "Not init."
    }
}