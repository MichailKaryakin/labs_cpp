#pragma once

namespace {
    int sizeCell = 64;
    int width_pixel  = 1024;
    int height_pixel = 768;
    int width_cell = width_pixel / sizeCell;
    int height_cell = height_pixel / sizeCell;
    float scale_W = (float) sizeCell / 16;
    float scale_H = (float) sizeCell / 16;
}