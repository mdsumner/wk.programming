library(wk)

xx <- c(xmin = 0, ymin = 1, xmax = 2, ymax = 3)

test_that("multiplication works", {
  expect_equal(wk_handle(
    wkt(c(NA, "POINT (0 1)", "GEOMETRYCOLLECTION (POINT (2 3))")),
    bbox_handler()
  ), xx)


  expect_equal(wk_handle(
    wkt(c(NA, "POINT (0 1)", "GEOMETRYCOLLECTION (POINT (2 3))")),
    bbox_handler_c()
  ), xx)


  expect_equal(cpp_handle_xy(data.frame(x = as.double(1:2), y = as.double(3:4.0)), h <- bbox_handler()),
               c(xmin = 1, ymin = 3, xmax = 2, ymax = 4))

  expect_error(cpp_handle_xy(data.frame(x = as.double(1:2), y = as.double(3:4.0)), h))
})
