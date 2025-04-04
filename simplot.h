#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <math.h>
#include <float.h>

#ifndef _SIMPLOT_H_
#define _SIMPLOT_H_

static void simplot(double (*func)(double), uint16_t screen[2], int16_t x_range[2]);

#ifdef SIMPLOT_IMPLEMENTATION
static void simplot(double (*func)(double), uint16_t screen[2], int16_t x_range[2]) {
  assert(x_range[1] > x_range[0]);
  uint16_t x_diff = x_range[1] - x_range[0];

  char plot[screen[1]][screen[0]];

  for (uint_fast16_t y = 0; y < screen[1]; y++) {
    for (uint_fast16_t x = 0; x < screen[0]; x++) {
      plot[y][x] = ' ';
    }
  }

  double max_y = DBL_MIN;
  double min_y = DBL_MAX;

  double data_y[screen[0]];
  for (uint16_t x = 0; x < screen[0]; x++) {
    double x_scaled = (double)x_range[0] + ((double)x_diff / (double)screen[0]) * (double)x;
    double y = func(x_scaled);
    if (y < min_y) min_y = y;
    if (y > max_y) max_y = y;
    data_y[x] = y;
  }
  assert(max_y >= min_y);
  double y_diff = max_y - min_y;

  for (uint16_t x = 0; x < screen[0]; x++) {
    uint16_t y_scaled = round((((double)screen[1] - 1) / (double)y_diff) * (data_y[x] - min_y));
    uint16_t y_plot = screen[1] - 1 - y_scaled;
    plot[y_plot][x] = '#';
  }

  // Add a scaling info, which causes shearing and streching
  fprintf(stdout, "x: [%d - %d], y: [%d, %d]\n", x_range[0], x_range[1], (int)min_y, (int)max_y);
  for (uint16_t y = 0; y < screen[1]; y++) {
    for (uint16_t x = 0; x < screen[0]; x++) {
      putc(plot[y][x], stdout);
    }
    putc('\n', stdout);
  }
}

#endif // SIMPLOT_IMPLEMENTATION
#endif // _SIMPLOT_H_
