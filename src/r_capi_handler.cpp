#include <R.h>
#include <Rinternals.h>
#include <stdlib.h>
#include "wk-v1.h"
//#include "wk-v1-impl.c"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct {
  double xmin, ymin, xmax, ymax;
} bbox_handler_data_t;

int bbox_handler_coord(const wk_meta_t* meta, const double* coord,
                       uint32_t coord_id, void* handler_data) {
  bbox_handler_data_t* data = (bbox_handler_data_t*) handler_data;
  data->xmin = MIN(coord[0], data->xmin);
  data->ymin = MIN(coord[1], data->ymin);
  data->xmax = MAX(coord[0], data->xmax);
  data->ymax = MAX(coord[1], data->ymax);
  return WK_CONTINUE;
}

SEXP bbox_handler_vector_end(const wk_vector_meta_t* meta, void* handler_data) {
  bbox_handler_data_t* data = (bbox_handler_data_t*) handler_data;

  const char* names[] = {"xmin", "ymin", "xmax", "ymax", ""};
  SEXP output = PROTECT(Rf_mkNamed(REALSXP, names));
  REAL(output)[0] = data->xmin;
  REAL(output)[1] = data->ymin;
  REAL(output)[2] = data->xmax;
  REAL(output)[3] = data->ymax;

  UNPROTECT(1);
  return output;
}

void bbox_handler_finalize(void* handler_data) {
  bbox_handler_data_t* data = (bbox_handler_data_t*) handler_data;
  free(data);
}

SEXP c_bbox_handler_new() {
  wk_handler_t* handler = wk_handler_create();

  handler->coord = &bbox_handler_coord;
  handler->vector_end = &bbox_handler_vector_end;

  bbox_handler_data_t* data = (bbox_handler_data_t*) malloc(sizeof(bbox_handler_data_t));
  data->xmin = R_PosInf;
  data->ymin = R_PosInf;
  data->xmax = R_NegInf;
  data->ymax = R_NegInf;
  handler->handler_data = data;

  return wk_handler_create_xptr(handler, R_NilValue, R_NilValue);
}
