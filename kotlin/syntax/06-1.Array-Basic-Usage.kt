// 06-1. Array : Basic-Usage

fun main(args:Array<String>)
{
    var arr1 : Array<Char> = arrayOf('a', 'b', 'c')
    var arr2               = arrayOf(1, 2, 3, *arr1, 4, 5, 6)   // *는 확산 연산자(끼워넣기), arr2 : Array<Any>
    var arr3 : Array<Int>  = arrayOf(1, 2, 3, *arr1, 4, 5, 6)   // 컴파일 에러, 'a', 'b', 'c'는 Int가 아님
    var arr4               = (0..10 step 3).toList()            // 0, 3, 6, 9

    // for with-value
    for(v in arr2)
    {
        println(v) // print 1, 2, 3, 'a', 'b', 'c', 4, 5, 6
    }


    // for with-iterator
    for(iter in arr2.iterator())
    {
        println(iter) // print 1, 2, 3, 'a', 'b', 'c', 4, 5, 6
    }


    // index base
    for(i in 0 until arr2.size step 2)
    {
        println(arr2[i]) // print 1, 3, 'b', 4, 6
    }
}



