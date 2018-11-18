// 06-2. Array : Advanced-Usage

fun main(args:Array<String>)
{
    var n      : List<Int> = (0..10 step 1).toList()

    //! Map to n^2
    var nSqure : List<Int> = n.map { it -> it*it }
    for(v in nSqure) println(v) // 0, 1, 4, 9, 16, .., 81, 100

    //! Map to Str
    var nString : List<String> = n.map{it->it.toString()}
    for(v in nString) println(v)

    //! Reduce
    var sum = n.reduce{ acc, it-> acc+it } // (((0 +1) +2) +3) + ...

    //! ForEach
    //! print "current : 0" .. "current : 10"
    n.forEach { it -> println("current : $it") }
}