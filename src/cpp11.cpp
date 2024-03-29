// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"
#include <R_ext/Visibility.h>

// cpp11_handler.cpp
sexp cpp_bbox_handler_new();
extern "C" SEXP _wk_programming_cpp_bbox_handler_new() {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_bbox_handler_new());
  END_CPP11
}
// reader.cpp
sexp cpp_handle_xy(data_frame input, sexp handler_xptr);
extern "C" SEXP _wk_programming_cpp_handle_xy(SEXP input, SEXP handler_xptr) {
  BEGIN_CPP11
    return cpp11::as_sexp(cpp_handle_xy(cpp11::as_cpp<cpp11::decay_t<data_frame>>(input), cpp11::as_cpp<cpp11::decay_t<sexp>>(handler_xptr)));
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP c_bbox_handler_new();

static const R_CallMethodDef CallEntries[] = {
    {"_wk_programming_cpp_bbox_handler_new", (DL_FUNC) &_wk_programming_cpp_bbox_handler_new, 0},
    {"_wk_programming_cpp_handle_xy",        (DL_FUNC) &_wk_programming_cpp_handle_xy,        2},
    {"c_bbox_handler_new",                   (DL_FUNC) &c_bbox_handler_new,                   0},
    {NULL, NULL, 0}
};
}

extern "C" attribute_visible void R_init_wk_programming(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
