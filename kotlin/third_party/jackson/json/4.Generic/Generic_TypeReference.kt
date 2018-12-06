import com.fasterxml.jackson.core.type.TypeReference
import com.fasterxml.jackson.module.kotlin.jacksonObjectMapper
import java.io.File

fun main(args: Array<String>)
{
    // java.lang.ClassCastException :
    //     class java.util.LinkedHashMap cannot be cast to class Article
    val article = read<Article>("./my_article.json")

    println(article)
}

fun <T> read(filePath:String) : T
{
    val mapper= jacksonObjectMapper()
    val file = File(filePath)
    val obj = mapper.readValue<T>(file, object:TypeReference<T>(){})
    return obj   // TypeOf(obj) == LinkedHashMap
}