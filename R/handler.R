
#' Mikey lurnin
#'
#' https://paleolimbot.github.io/wk/articles/programming.html
#' @return
#' @export
#' @importFrom wk new_wk_handler
#' @examples
#' bbox_handler()
#' library(wk)
#' wk_handle(
#'   wkt(c(NA, "POINT (0 1)", "GEOMETRYCOLLECTION (POINT (2 3))")),
#'   bbox_handler()
#' )
#'
#' # The most important thing about a wk_handler is that, once created, it can only be used once:
#' h <- bbox_handler()
#' wk_handle(wkt(), h)
#' try(wk_handle(wkt(), h))
#'
#' ## pass a function for user-supplied handles
#' handler <- function() bbox_handler()
#' wk_handle(wkt(), handler)
#' wk_handle(wkt(), handler)
#'
#' ## also written without cpp11 (as per the wk/vignettes/articles/)
#' ## ... but not registered yet
#' #ch <- bbox_handler_c()
#' #wk_handle(wkt(), ch)
bbox_handler <- function() {
  wk::new_wk_handler(cpp_bbox_handler_new(), "bbox_wk_handler")
}


bbox_handler_c <- function() {
  new_wk_handler(.Call("c_bbox_handler_new"))
}
