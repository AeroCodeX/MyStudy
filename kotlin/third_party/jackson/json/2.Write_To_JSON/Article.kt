import java.time.LocalDateTime

data class Article(
    // 게시글 제목
    val title : String = "",

    // 게시글 등록일자
    val date  : LocalDateTime? = null,

    // 게시글 조회회수
    val viewCnt  : Int = 0,

    // 게시글 내용
    val content : String = ""
)