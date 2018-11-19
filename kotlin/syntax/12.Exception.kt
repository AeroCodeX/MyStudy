// 12. Exception

fun main(args:Array<String>) {
    //! try-catch-finally 시작
    //!     (1) try 블럭 시도
    //!     (2) 예외발생시 catch 블럭으로 이동
    //!     (3) 예외가 발생했든 안했든 finally 블럭으로 이동
    //! try-catch=finally 종료

    try {
        val a = 1 / 0   // java.lang.ArithmeticException: / by zero
    } catch (e: ArithmeticException) {
        println("exception")
    } finally {
        println("done1")
    }
    println("done2")

    // print "exception"
    // print "done1"
    // print "done2"
}