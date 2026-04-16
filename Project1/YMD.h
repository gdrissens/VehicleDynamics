#pragma once
#include <vector>
#include "Outputs.h"

using namespace System;
using namespace System::Windows::Forms::DataVisualization::Charting;

void YMD_setup(Chart^ chart, YMD_Carrier& carrier);

void YMD_clear(Chart^ chart);

void YMD_plot(Chart^ chart, YMD_Carrier& carrier);