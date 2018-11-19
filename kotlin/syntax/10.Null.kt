// 10. Null

fun main(args:Array<String>) {
    //! Null 값이 들어갈 수 있다면 ? 키워드를 붙임.
    val s1: String? = null
    var s2: String  = "Hello, World!"

    //! Null 체크 기법 (1)
    //! if 문으로 Null 값인지 확인한다.
    if( s1 != null) println(s1.length)  // print nothing.

    //! Null 체크 기법 (2)
    //! ?. 연산자는 앞의 값이 Null 값이 아닐때만 참조한다.
    println(s1?.length) // print "null"
    println(s1?.substring(5)?.length)   // print "null

    //! Null 체크 기법 (3)
    //! ?: 연산자는 앞의 값이 Null 값이면 뒤의 정의된 값을 사용한다.
    println(s1?.length ?: 0)    // print "0"

    //! Null 체크 기법 (4)
    //! !! 연산자는 앞의 값이 Null 값이면 NullPointerException 예외를 발생시킨다.
    try{
        println(s1!!.length)    // NullPointerException
    }
    catch (e : Exception){

    }
    finally {

    }

    //! Null 체크 기법 (5)
    //! as? 연산자는 값이 올바르게 캐스팅될 수 없다면 Null 값으로 캐스팅한다.
    //! 정수형은 문자열로 캐스팅되기 위해서는 toString() 메소드를 사용해야 한다.
    var n : Int = 4
    val s3: String? = n as? String?
    println(s3) // print "null"
}

