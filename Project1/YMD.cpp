#include "YMD.h"
#include <vector>
#include "Outputs.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms::DataVisualization::Charting;

void YMD_setup(Chart^ chart, YMD_Carrier& carrier)
{
    chart->Series->Clear();
    chart->ChartAreas->Clear();

    ChartArea^ area = gcnew ChartArea("Main");

    area->AxisX->Title = "Lateral Acceleration (g)";
    area->AxisY->Title = "Yaw Moment (Nm)";

    area->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
    area->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;

    area->AxisX->Minimum = carrier.min_a_lat;
    area->AxisX->Maximum = carrier.max_a_lat;

    area->AxisX->Interval = 0.2;
    area->AxisX->IntervalOffset = 0.0;

    area->AxisY->Interval = 1000.0;
    area->AxisY->IntervalOffset = 0.0;

    chart->ChartAreas->Add(area);
}

void YMD_clear(Chart^ chart)
{
    for each (Series ^ s in chart->Series)
        s->Points->Clear();
}

void YMD_plot(Chart^ chart, YMD_Carrier& carrier)
{
    int intensity = 0.0;
    Color base_beta = Color::Red;

    for (size_t j = 0; j < carrier.a_lat_isobeta.size(); j++) {

        intensity = j * 255 / carrier.a_lat_isobeta.size();

        std::vector<double>& x = carrier.a_lat_isobeta[j];
        std::vector<double>& y = carrier.M_yaw_isobeta[j];
        std::vector<double>& beta = carrier.beta_isobeta[j];
        std::vector<double>& delta = carrier.delta_isobeta[j];
        std::vector<double>& control = carrier.control[j];

        Series^ s = gcnew Series(System::String::Format(L"\u03B2 = {0:F2} \u00B0", Convert::ToDouble(carrier.beta_iso[j])));
        s->ChartType = SeriesChartType::Spline;
        s->BorderWidth = 2;
        s->ChartArea = "Main";
        s->Color = Color::FromArgb(255, 255, 255 - intensity, 0);
        s->MarkerStyle = MarkerStyle::Circle;
        s->MarkerSize = 6;

        chart->Series->Add(s);

        for (size_t i = 0; i < x.size(); i++) {
            int idx = s->Points->AddXY(x[i], y[i]);
            s->Points[idx]->ToolTip =
                L"\u03B2 = " + beta[i].ToString("F2") + L" \u00B0"
                L"\n\u03B4 = " + delta[i].ToString("F1") + L" \u00B0" +
                "\nLateral acceleration = " + x[i].ToString("F3") + " g"
                "\nYaw moment = " + y[i].ToString("F2") + " Nm" +
                "\nControl = " + control[i].ToString("F2") + L" Nm/\u00B0";
        }
    }

    
    Color base_delta = Color::Blue;
    for (size_t j = 0; j < carrier.a_lat_isodelta.size(); j++) {
        intensity = j * 255 / carrier.a_lat_isodelta.size();

        std::vector<double>& x = carrier.a_lat_isodelta[j];
        std::vector<double>& y = carrier.M_yaw_isodelta[j];
        std::vector<double>& beta = carrier.beta_isodelta[j];
        std::vector<double>& delta = carrier.delta_isodelta[j];
		std::vector<double>& stability = carrier.stability[j];

        Series^ s = gcnew Series(Convert::ToString(System::String::Format(L"\u03B4d = {0:F1} \u00B0", Convert::ToDouble(carrier.delta_iso[j]))));
        s->ChartType = SeriesChartType::Spline;
        s->BorderWidth = 2;
        s->ChartArea = "Main";
        s->Color = Color::FromArgb(255, 0, intensity, 255);
        s->MarkerStyle = MarkerStyle::Circle;
        s->MarkerSize = 6;

        chart->Series->Add(s);

        for (size_t i = 0; i < x.size(); i++) {
            int idx = s->Points->AddXY(x[i], y[i]);
            s->Points[idx]->ToolTip =
                L"\u03B2 = " + beta[i].ToString("F2") + L" \u00B0"
                L"\n\u03B4 = " + delta[i].ToString("F1") + L" \u00B0" +
                "\nLateral acc = " + x[i].ToString("F2") + " g"
                "\nYaw moment = " + y[i].ToString("F2") + " Nm" +
				"\nStability = " + stability[i].ToString("F2") + L" Nm/\u00B0";
        }
    }

    Series^ s = gcnew Series("Single run");
    s->ChartType = SeriesChartType::Point;
    s->BorderWidth = 2;
    s->ChartArea = "Main";
	s->MarkerBorderColor = System::Drawing::Color::Green;
	s->MarkerColor = System::Drawing::Color::Green;
	s->MarkerStyle = MarkerStyle::Star4;
	s->MarkerSize = 10;

    chart->Series->Add(s);

    s->Points->AddXY(carrier.single_a_lat, carrier.single_M_yaw);

}