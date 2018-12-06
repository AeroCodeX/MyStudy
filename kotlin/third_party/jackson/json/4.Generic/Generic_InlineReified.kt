import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import java.io.File

fun main(args: Array<String>)
{
    val article = read<Article>("./my_article.json")
    println(article)
}

inline fun <reified T> read(filePath:String) : T
{
    val mapper= jacksonObjectMapper()
    val file = File(filePath)
    val obj = mapper.readValue<T>(file, T::class.java)
    return obj
}