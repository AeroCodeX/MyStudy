// 24-3. Generic-Use-site variance (in,out-projection)

fun main(args: Array<String>)
{
    val numMyArray = MyArray<Number>(arrayOf(1.0, 2.0, 3.0))
    val intMyArray = MyArray<Int>(arrayOf(4, 5, 6))


    copyMyArray(intMyArray, numMyArray)
    // copyMyArray(numMyArray, intMyArray) <ERR>


    fillMyArray(numMyArray, 3)
    fillMyArray(numMyArray, 3.0)
    fillMyArray(intMyArray, 3)
    // fillMyArray(intMyArray, 3.0) <ERR>
}


// 사용위치 변성이란,
// 메소드 위치에서 변성 수식어(in, out)를 정의하는 것.
// T("타입")에 변성 수식어를 붙인다고 해서, 타입 프로젝션이라고 한다.
//      in  T : 소비만 가능한 타입, 자바의 <? super   T>에 대응한다.
//      out T : 공급만 가능한 타입, 자바의 <? extends T>에 대응한다.
class MyArray<T> (val array:Array<T>)
fun <T>copyMyArray(source:MyArray<out T>, dest:MyArray<T>)
{
    val sArr = source.array
    val dArr = dest.array
    if(sArr.size != dArr.size) return
    for(i in dArr.indices) dArr[i] = sArr[i]
}
fun <T>fillMyArray(dest:MyArray<in T>, v:T)
{
    val dArr = dest.array
    for(i in dArr.indices) dArr[i] = v
}



