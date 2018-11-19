// 20-2. Object-Expression (이름없는 오브젝트)

fun main(args:Array<String>) {
    Test().test()
}

open class Data{
    open val x: String = "x"
}

class Test {
    private fun privateFun() = object { // private 로 선언되었다면 Object 타입으로 인식함.
        val x: String = "x"
    }

    fun publicFunExtends() = object : Data() { // public 으로 선언되었다면 부모 클래스의 타입으로 인식함.
        override val x: String = "y"
    }

    fun publicFunNotExtends() = object { // public 으로 선언되었고, 부모 클래스도 없다면 Any 타입으로 인식함.
        val x: String = "z"
    }

    fun test() {
        // 반환형 정리
        //      privateFun()          → Object  : private 로 선언되었다면 Object 타입으로 인식함.
        //      publicFunExtends()    → Data    : public 으로 선언되었다면 부모 클래스의 타입으로 인식함.
        //      publicFunNotExtends() → Any     : public 으로 선언되었고, 부모 클래스도 없다면 Any 타입으로 인식함.
        //                               Any 타입으로 변환된 오브젝트는 자신의 멤버에 접근할 수 없음.
        //

        println(privateFun().x)  // print "x"
        println(publicFunExtends().x)  // print "y"
        println(publicFunNotExtends().x)    // compile error, Any 타입은 멤버에 접근 불가능.
    }
}

