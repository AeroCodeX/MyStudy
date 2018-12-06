import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper

fun main(args: Array<String>)
{
    val mapper = jacksonObjectMapper()
    println("Hello, Jackson!")
}