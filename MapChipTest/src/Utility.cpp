#include "Utility.h"

int ChipData::row = 100;
int ChipData::column = 100;
int ChipData::gap = 5;
int ChipData::size = 64;

int Window::width = 1024;
int Window::height = 1024;
int Window::widthFit = Window::width / 2 - ChipData::gap;
int Window::heightFit = Window::height / 2 - (ChipData::size + ChipData::gap);


